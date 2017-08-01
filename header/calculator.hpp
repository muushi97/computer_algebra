#ifndef IG_CALCULATOR_HPP
#define IG_CALCULATOR_HPP

#include <vector>
#include <list>
#include <complex>
#include <memory>
#include <utility>

#include "expression.hpp"

#include "value_interface.hpp"
//#include "matrix.hpp"

namespace cut_cut_cut
{
	class expression;

	class calculator
	{
	private:
		expression *m_body;						// 数式本体への参照
		std::vector<std::unique_ptr<value_interface>> m_variable;					// 変数の値

		// 処理を移譲する
		std::unique_ptr<value_interface> calulate_chain(decltype(m_body->m_body)::iterator i);

		// 変数名から値を取得する
		value_interface *get_value(decltype(m_body->m_body)::iterator i);

		// 関数群 decltype(m_body->m_body)
		std::unique_ptr<value_interface> add(decltype(m_body->m_body)::iterator i);	// 加算

	public:
		// コンストラクタ
		calculator();
		calculator(expression &obj);

		// 数式をセットする
		void set_expression(expression &obj);

		// 計算する
		std::complex<double> calculate();
	};
}

#endif
