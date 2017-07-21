#include "expression.hpp"

#include <cstdint>
#include <iostream>

using namespace cut_cut_cut;

// 変数を追加する
void expression::add_veriable(std::string name)
{
	m_variable_list.push_back(name);
}

// コンストラクタ
expression::expression()
{
}

// 変数定義 (再定義も可能)
// 変数識別子	: s=スカラー , v=ベクトル , m=行列
//				: 変数識別子の前に，t を付けた場合，その変数は一時変数とし，数式外からの操作を不可能とする．
// sa			: スカラー変数 a を定義
// va			: ベクトル変数 a を定義 (次元は未定義)
// ma			: 行列変数 a を定義 (次元は未定義)
// &a			: スカラー数列 a を定義 ('_' の個数でインデックスの個数も指定可能) (要検討)
bool expression::define_variable(std::initializer_list<std::string> variable_list)
{
	char ind;
	for (auto itr = variable_list.begin(); itr != variable_list.end(); itr++)
	{
		if ((*itr)[0] != 't')
			ind = 0;
		else
			ind = 1;

		if ((*itr)[ind] != 's' && (*itr)[ind] != 'v' && (*itr)[ind] != 'm')
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
// sa				: スカラー変数を参照
// va				: ベクトル変数を参照
// va(k)			: ベクトル変数 a の k 個目の要素を参照 (1 <= k <= N ; Nはベクトル変数の次元)
// ma				: 行列変数を参照
// ma(k)(l)			: 行列変数 a の k 行 l 列の要素を参照 (1 <= k , l ; k <= N ; l <= M ; a は N 行 M 列の行列変数)
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

		{// 関数っぽいば・あ・い
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
				m_body.emplace_back(itr, itr2 + 1);
				std::cout << "func : " << m_body.back();
				std::cout << std::endl;
				itr = itr2;
				continue;
			}
		}

		{// 変数っぽいば・あ・い
			auto itr2 = itr;
			if ((*itr2) == 't')
				itr2++;
			if ((*itr2) == 's' || (*itr2) == 'v' || (*itr2) == 'm')
			{
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
				m_body.emplace_back(itr, itr2 + 1);
				std::cout << "var : " << m_body.back();
				std::cout << std::endl;
				itr = itr2;
				continue;
			}
		}

		{// 定数っぽいば・あ・い
			auto itr2 = itr;
			for (; (itr2 + 1) != body.end(); itr2++)
			{
				if (*(itr2 + 1) == ' ')
				{
					if (*(itr2) != *itr)
						break;
					else
						return false;
				}
			}
			m_body.emplace_back(itr, itr2 + 1);
			std::cout << "cons : " << m_body.back();
			std::cout << std::endl;
			itr = itr2;
			continue;
		}
	}
	return true;
}

// 定義されている変数の数を返す
unsigned int expression::variable_size() const
{
	return m_variable_list.size();
}
// インデックス index の変数名を返す (変数識別子含む)
const std::string &expression::variable_name(unsigned int index) const
{
	return m_variable_list[index];
}
// 変数を探して，見つかった場合，インデックスを返す．(見つからなかった場合 -1 を返す)
int expression::variable_index(std::string variable_name) const
{
	for (int i = 0; i < m_variable_list.size(); ++i)
	{
		if (m_variable_list[i] == variable_name)
			return i;
	}
	return -1;
}
