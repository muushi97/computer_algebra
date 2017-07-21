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

		// 変数を追加する
		void add_veriable(std::string name);

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
		const std::string &variable_name(unsigned int index) const;
		// 変数を探して，見つかった場合，インデックスを返す．(見つからなかった場合 -1 を返す)
		int variable_index(std::string variable_name) const;
	};
}

#endif
