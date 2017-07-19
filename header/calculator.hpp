#ifndef IG_CALCULATOR_HPP
#define IG_CALCULATOR_HPP

#include <vector>
#include <complex>

#include "matrix.hpp"

namespace cut_cut_cut
{
	class expression;

	class calculator
	{
	private:
		const expression &m_body;						// 数式本体への参照
		std::vector<matrix> m_variable;					// 変数の値

	public:
		// コンストラクタ
		calculator(expression &obj);

		// 数式をセットする
		void set_expression(expression &obj);
	};
}

#endif
