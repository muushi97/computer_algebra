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
	private:
		std::vector<std::string> m_variable_list;		// 変数リスト
		std::vector<char> m_body;						// 式本体
		std::list<std::string> m_body_temp;			// 式本体

	public:
		// コンストラクタ
		expression();

		// 変数定義 (再定義も可能)
		bool define_variable(std::initializer_list<std::string> variable_list);

		// 式本体定義 (再定義も可能)
		bool define_body(std::string body);
	};
}

#endif
