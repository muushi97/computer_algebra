#include "calculator.hpp"

using namespace cut_cut_cut;


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

	char index;
	for (unsigned int i = 0; i < size; ++i)
	{
		if ((m_body.variable(i))[0] == 't')
			index = 1;
		else
			index = 0;

		if ((m_body.variable(i))[index] == 's')
			m_variable[i].change_size(1, 1);

		if ((m_body.variable(i))[index] == 'v')
			m_variable[i].change_size(1, 0);

		if ((m_body.variable(i))[index] == 'm')
			m_variable[i].change_size(0, 0);
	}
}
