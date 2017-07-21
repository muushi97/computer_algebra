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
		const expression *m_body;						// 数式本体への参照
		std::vector<matrix> m_variable;					// 変数の値

		std::vector<unsigned char> m_bin;				// 計算形式の数式

		// 関数名から関数IDを返す
		unsigned char to_functionID(std::string name);
		// 関数名から関数の項数を返す
		unsigned char to_function_term_of_number(std::string name);
		// 文字列から小数を返す
		double to_decimal(std::string name);

		// 数式を計算用に変換
		void convert_expression();

	public:
		// コンストラクタ
		calculator();
		calculator(const expression &obj);

		// 数式をセットする
		void set_expression(const expression &obj);
	};
}

#endif
