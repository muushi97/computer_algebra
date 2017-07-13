#ifndef IG_EXPRESSION_HPP
#define IG_EXPRESSION_HPP

#include <string>
#include <vector>
#include <initializer_list>

namespace hoge
{
	class item;

	class expression
	{
	private:
		std::vector<std::string> m_variable_list;		// 変数リスト
		std::vector<item> m_body;						// 式本体

	public:
		// コンストラクタ
		expression();

		// 変数定義 (再定義も可能)
		void define_variable(std::initializer_list<std::string> variable_list);

		// 式本体定義 (再定義も可能)
		void define_body(std::string body);
	}
}

#endif
