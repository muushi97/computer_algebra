#include "expression.hpp"

#include <iostream>

using namespace cut_cut_cut;

namespace cut_cut_cut
{
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

	union ch_de
	{
		unsigned char integer[4];
		double decimal;
	};
}

// 関数名から関数IDを返す
unsigned char expression::to_functionID(std::string name)
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
unsigned char expression::to_function_term_of_number(std::string name)
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
// 変数名から変数インデックスを返す
unsigned char expression::to_variable_index(std::string name)
{
	for (unsigned char i = 0; i < m_variable_list.size(); ++i)
	{
		if (m_variable_list[i] == name)
			return i;
	}
	return 0;
}
// 文字列から小数を返す
double expression::to_decimal(std::string name)
{
	return std::stod(name);
}


// コンストラクタ
expression::expression()
{
}

// 変数定義 (再定義も可能)
// @a		: スカラー変数 a を定義
// $a		: ベクトル変数 a を定義
// %a		: 行列変数 a を定義 (次元は未定義)
// &a		: スカラー数列 a を定義 ('_' の個数でインデックスの個数も指定可能) (要検討)
bool expression::define_variable(std::initializer_list<std::string> variable_list)
{
	for (auto itr = variable_list.begin(); itr != variable_list.end(); itr++)
	{
		if ((*itr)[0] != '@' && (*itr)[0] != '$' && (*itr)[0] != '%')
			return false;

		std::cout << (*itr) << std::endl;
	}
	m_variable_list = variable_list;
	return true;
}

// 式本体定義 (再定義も可能)
// \hoge[n]			: n個の引数を持つ hoge 演算を行う
// \sum[3][k]		: インデックスを k とし，n <= k <= m となる範囲で総和計算 (範囲は引数で表す)
// \pro[3][k]		: インデックスを k とし，n <= k <= m となる範囲で総乗計算 (範囲は引数で表す)
// @a				: スカラー変数を参照
// $a				: ベクトル変数を参照
// $a(k)			: ベクトル変数 a の k 個目の要素を参照 (1 <= k <= N ; Nはベクトル変数の次元)
// %a				: 行列変数を参照
// %a(k)(l)			: 行列変数 a の k 行 l 列の要素を参照 (1 <= k , l ; k <= N ; l <= M ; a は N 行 M 列の行列変数)
// &a_k				: 数列の第 k 項を参照 (要検討)
// &a_k_l			: 数列の第 k 項の第 l 項を参照 (要検討)]
//
// 関数は関数ごとにIDに変換し数値として保持 (char[0] = ID, char[1] = 項数)
// 変数は変数リストに対応するインデックスを保持 (char[0] = インデックス, char[1] = 変数の種類)
// 定数は，共用体を用いて整数配列へ変換して保持 (char[0..7] = 値)
bool expression::define_body(std::string body)
{
	for (auto itr = body.begin(); itr != body.end(); itr++)
	{
		// 空白のば・あ・い
		if ((*itr) == ' ')
			continue;

		// 関数っぽいば・あ・い
		if ((*itr) == '\\')
		{
			auto itr2 = itr;
			for (; (itr2 + 1) != body.end(); itr2++)
			{
				if (*(itr2 + 1) == ' ')
				{
					if (*itr2 != *itr)
						break;
					else
						return false;
				}
			}
			std::cout << "fun : " << static_cast<int>(to_functionID(std::string(itr + 1, itr2 + 1))) << " : " << static_cast<int>(to_function_term_of_number(std::string(itr + 1, itr2 + 1))) << std::endl;
			itr = itr2;
			continue;
		}

		// 変数っぽいば・あ・い
		if ((*itr) == '@' || (*itr) == '$' || (*itr) == '%')
		{
			auto itr2 = itr;
			for (; (itr2 + 1) != body.end(); itr2++)
			{
				if (*(itr2 + 1) == ' ')
				{
					if (*itr2 != *itr)
						break;
					else
						return false;
				}
			}
			m_body_temp.emplace_back(itr, itr2 + 1);
			std::cout << "var : " << m_body_temp.back() << std::endl;
			itr = itr2;
			continue;
		}

		// 定数っぽいば・あ・い
		auto itr2 = itr;
		for (; (itr2 + 1) != body.end(); itr2++)
		{
			if (*(itr2 + 1) == ' ')
			{
				if (*(itr2 + 1) != *itr)
					break;
				else
					return false;
			}
			else if (*(itr2 + 1) == 'i' || *(itr2 + 1) == 'j')
			{
				std::cout << "con : " << to_decimal(std::string(itr, itr2 + 1)) << std::endl;
				itr = itr2 + 2;
			}
		}
		std::cout << "con : " << to_decimal(std::string(itr, itr2 + 1)) << std::endl;
		itr = itr2;
	}
	return true;
}
