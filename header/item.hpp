#ifndef IG_ITEM_HPP
#define IG_ITEM_HPP

#include <vector>
#include <cstdint>

namespace
{
	union convert_union
	{
		uint_least64_t _integer;
		double _decimal;
		item_type _item_type;
		function_type _function_type;
	};
}

namespace hoge
{
	enum type_type
	{
		no,
		constant,
		variable,
		function,
	};

	class item
	{
	private:
		std::vector<uint_least64_t> m_data;

	public:
		// コンストラクタ
		item(type_type type);
	}
}

#endif
