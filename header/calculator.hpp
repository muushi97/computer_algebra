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

		std::vector<unsigned char> m_bin;				// 計算形式の数式

		// 数式を計算用に変換
		void convert_expression();

	public:
		// コンストラクタ
		calculator(const expression &obj);

		// 数式をセットする
		void set_expression(const expression &obj);
	};
}

#endif
