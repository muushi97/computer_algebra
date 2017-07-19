#include "calculator.hpp"

#include <list>
#include <iostream>

using namespace cut_cut_cut;

// 数式を計算用に変換
void calculator::convert_expression()
{
	std::list<std::string> expr;

	for (auto itr = expr.begin(); itr != expr.end(); itr++)
	{
		{// 関数のば・あ・い
			if ((*itr)[0] == '\\')
			{
				std::cout << static_cast<int>(term_type::fun) << " ";
				std::cout << static_cast<int>(to_functionID(*itr)) << " ";
				std::cout << static_cast<int>(to_function_term_of_number(*itr)) << " ";
				std::cout << std::endl;
				itr = itr2;
			}
			continue;
		}

		{// 変数のば・あ・い
			if ((*itr)[0] == 't' || (*itr)[0] == 's' || (*itr)[0] == 'v' || (*itr)[0] == 'm')
			{
				std::cout << static_cast<int>(term_type::var) << " ";
				std::cout << static_cast<int>(to_variable_index(*itr)) << " ";
				std::cout << std::endl;
			}
			continue;
		}

		{// 定数のば・あ・い
			auto itr_s = (*itr).begin();
			auto itr_t = itr;
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
calculator::calculator(const expression &obj)
{
	set_expression(obj);
}

// 数式をセットする
void calculator::set_expression(const expression &obj)
{
	m_body = obj;
	unsigned int size = m_body.variable_size();

	m_variable.resize(size);
}
