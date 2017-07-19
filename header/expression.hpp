#ifndef IG_EXPRESSION_HPP
#define IG_EXPRESSION_HPP

#include <string>
#include <vector>
#include <list>
#include <initializer_list>

namespace cut_cut_cut
{
	class expression
	{
		friend class calculator;

	private:
		std::vector<std::string> m_variable_list;						// 変数リスト
		std::list<std::string> m_body;									// 式本体

		// 変数を探す
		short find_variable(std::string variable_name);

		// 関数名から関数IDを返す
		unsigned char to_functionID(std::string name);
		// 関数名から関数の項数を返す
		unsigned char to_function_term_of_number(std::string name);
		// 変数名から変数インデックスを返す (一時変数の場合，定義されていなかったら定義する)
		unsigned char to_variable_index(std::string name);
		// 文字列から小数を返す
		double to_decimal(std::string name);

	public:
		// コンストラクタ
		expression();

		// 変数定義 (再定義も可能)
		bool define_variable(std::initializer_list<std::string> variable_list);

		// 式本体定義 (再定義も可能)
		bool define_body(std::string body);

		// 定義されている変数の数を返す
		unsigned int variable_size() const;
		// インデックス index の変数名を返す (変数識別子含む)
		const std::string &variable(unsigned int index) const;
	};
}

#endif
