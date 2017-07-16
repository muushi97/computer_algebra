#include "expression.hpp"

#include <iostream>
#include <string>

using namespace cut_cut_cut;

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

		// 関数のば・あ・い
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
			std::string hoge(itr + 1, itr2 + 1);
			m_body_temp.emplace_back(itr, itr2 + 1);
			std::cout << "fun : " << m_body_temp.back() << std::endl;
			itr = itr2;
			continue;
		}

		// 変数のば・あ・い
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

		// 定数のば・あ・い
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
		}
		m_body_temp.emplace_back(itr, itr2 + 1);
		std::cout << "con : " << m_body_temp.back() << std::endl;
		itr = itr2;
	}

	return true;
}
