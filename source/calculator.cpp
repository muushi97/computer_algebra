#include "calculator.hpp"

#include <list>
#include <iostream>

#include "expression.hpp"

using namespace cut_cut_cut;

namespace
{
	unsigned char integer_devide(uint_least64_t &integer)
	{
		unsigned char to_conv = integer & 0x000000ff;
		integer = integer >> 8;
		return to_conv;
	}
}

namespace cut_cut_cut
{
	enum term_type : unsigned char
	{
		fun,
		var,
		con,
	};

	enum function : unsigned char
	{
		non,
		add,
		sub,
		mul,
		div,
		frac,
		pow,
	};

	union in_de
	{
		uint_least64_t integer;
		double decimal;
	};
}

// 関数名から関数IDを返す
unsigned char calculator::to_functionID(std::string name)
{
	cut_cut_cut::function ID;

	if (name == "add")
		ID = cut_cut_cut::function::add;
	else if (name == "sub")
		ID = cut_cut_cut::function::sub;
	else if (name == "mul")
		ID = cut_cut_cut::function::mul;
	else if (name == "div")
		ID = cut_cut_cut::function::div;
	else if (name == "frac")
		ID = cut_cut_cut::function::frac;
	else if (name == "pow")
		ID = cut_cut_cut::function::pow;
	else
		ID = cut_cut_cut::function::non;

	return static_cast<unsigned char>(ID);
}
// 関数名から関数の項数を返す
unsigned char calculator::to_function_term_of_number(std::string name)
{
	unsigned char term_of_number;

	if (name == "add")
		term_of_number = 2;
	else if (name == "sub")
		term_of_number = 2;
	else if (name == "mul")
		term_of_number = 2;
	else if (name == "div")
		term_of_number = 2;
	else if (name == "frac")
		term_of_number = 2;
	else if (name == "pow")
		term_of_number = 2;
	else
		term_of_number = 0;

	return term_of_number;
}
// 文字列から小数を返す
double calculator::to_decimal(std::string name)
{
	return std::stod(name);
}


// 数式を計算用に変換
void calculator::convert_expression()
{
	for (auto itr = m_body->m_body.begin(); itr != m_body->m_body.end(); itr++)
	{
		{// 関数のば・あ・い
			if ((*itr)[0] == '\\')
			{
				std::cout << static_cast<int>(term_type::fun) << " ";
				std::cout << static_cast<int>(to_functionID(*itr)) << " ";
				std::cout << static_cast<int>(to_function_term_of_number(*itr)) << " ";
				std::cout << std::endl;
				continue;
			}
		}

		{// 変数のば・あ・い
			if ((*itr)[0] == 't' || (*itr)[0] == 's' || (*itr)[0] == 'v' || (*itr)[0] == 'm')
			{
				std::cout << static_cast<int>(term_type::var) << " ";
				std::cout << static_cast<int>(m_body->variable_index(*itr)) << " ";
				std::cout << std::endl;
				continue;
			}
		}

		{// 定数のば・あ・い
			auto itr_s = (*itr).begin();
			auto itr_t = itr_s;
			in_de conv;
			for (; (itr_t + 1) != (*itr).end(); itr_t++)
			{
				if (*(itr_t + 1) == 'i' || *(itr_t + 1) == 'j')
				{
					std::cout << static_cast<int>(term_type::con) << " ";
					std::cout << to_decimal(std::string(itr_s, itr_t + 1)) << " ";
					conv.decimal = to_decimal(std::string(itr_s, itr_t + 1));
					std::cout << conv.integer << " ";
					for (unsigned int i = 0; i < 8; ++i)
						std::cout << static_cast<int>(integer_devide(conv.integer)) << " ";
					itr_s = itr_t + 2;
					break;
				}
			}
			std::cout << to_decimal(std::string(itr_s, (*itr).end())) << " ";
			conv.decimal = to_decimal(std::string(itr_s, (*itr).end()));
			std::cout << conv.integer << " ";
			for (unsigned int i = 0; i < 8; ++i)
				std::cout << static_cast<int>(integer_devide(conv.integer)) << " ";
			std::cout << std::endl;
			itr_s = itr_t;
		}
	}
}

// コンストラクタ
calculator::calculator()
{ }
calculator::calculator(const expression &obj)
{
	set_expression(obj);
}

// 数式をセットする
void calculator::set_expression(const expression &obj)
{
	m_body = &obj;
	unsigned int size = m_body->variable_size();

	m_variable.resize(size);

	convert_expression();
}
