#include "calculator.hpp"

#include <list>
#include <iostream>
#include <array>

#include "expression.hpp"

#include "scalar_value.hpp"
#include "vector_value.hpp"
#include "matrix_value.hpp"

using namespace cut_cut_cut;

namespace cut_cut_cut
{
	std::unique_ptr<value_interface> generete_value(std::string &data)
	{
		double real, imaginary;
		auto itr = data.begin();
		for (; itr != data.end(); itr++)
		{
			if (*itr == 'i')
			{
				real = std::stod(std::string(data.begin(), itr));
				itr++;
				break;
			}
		}
		imaginary = std::stod(std::string(itr, data.end()));

		return std::unique_ptr<value_interface>(new scalar_value(real, imaginary));
	}
}

// 処理を移譲する
std::unique_ptr<value_interface> calculator::calulate_chain(decltype(m_body->m_body)::iterator i)
{
	auto function_name = i;
	i++;

	if (*function_name == "\\add") return add(i);
	else if (*function_name == "\\sub") return add(i);
}

// 変数名から値を取得する
value_interface *calculator::get_value(decltype(m_body->m_body)::iterator i)
{
	int index = m_body->variable_index(*i);
	if (index == -1)
		return nullptr;

	return m_variable[index].get();
}

template <typename T>
class fool_ptr
{
private:
	bool m_flag;
	T *m_pointer;

public:
	// コンストラクタ
	fool_ptr()
	{
		m_pointer = nullptr;
	}

	void set(T *pointer, bool flag)
	{
		m_flag = flag;
		m_pointer = pointer;
	}

	T *get()
	{
		return m_pointer;
	}

	T *reset(T *pointer, bool flag)
	{
		T *past = m_pointer;
		m_flag = flag;
		m_pointer = pointer;
		return past;
	}

	T *operator -> () const
	{
		return m_pointer;
	}

	~fool_ptr()
	{
		if (m_flag && m_pointer != nullptr)
			delete m_pointer;
	}
};
// 関数群
std::unique_ptr<value_interface> calculator::add(decltype(m_body->m_body)::iterator i)	// 加算
{
	unsigned int counter = 0;
	std::array<fool_ptr<value_interface> , 2> argument;

	auto itr = i;
	//std::unique_ptr<value_interface> value;
	for (; itr != m_body->m_body.end(); itr++)
	{
		// 値を取得して保持
		if ((*itr)[0] == '\\')
			argument[counter].set(calulate_chain(itr).release(), true);
		else if ((*itr)[0] == 's' || (*itr)[0] == 'v' || (*itr)[0] == 'm' || (*itr)[0] == 't')
			argument[counter].set(get_value(itr), false);
		else
			argument[counter].set(generete_value(*itr).release(), true);

		std::cout << counter << argument[counter]->ref(0, 0) << std::endl;
		counter++;

		// いっぱいいっぱい になったら計算して吐く
		if (counter >= argument.size())
			break;
	}
	std::complex<double> temp = argument[0]->ref(0, 0) + argument[1]->ref(0, 0);

	return std::unique_ptr<value_interface>(new scalar_value(temp));
}

// コンストラクタ
calculator::calculator()
{ }
calculator::calculator(expression &obj)
{
	set_expression(obj);
}

// 数式をセットする
void calculator::set_expression(expression &obj)
{
	m_body = &obj;
	unsigned int size = m_body->variable_size();

	m_variable.resize(size);
}

// 計算する
std::complex<double> calculator::calculate()
{
	std::unique_ptr<value_interface> fuga;

	fuga = calulate_chain(m_body->m_body.begin());
	std::cout << fuga->ref(0, 0) << std::endl;
}
