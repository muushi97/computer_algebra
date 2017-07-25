#include <cstdio>
#include <cstdint>
#include <iostream>
#include <vector>
#include <string>

#include "expression.hpp"
#include "calculator.hpp"
#include "matrix.hpp"

namespace cut_cut_cut
{
	enum item_type : uint_least64_t
	{
		no,
		constant,
		variable,
		function,
	};
	enum function_type : uint_least64_t
	{
		non,
		add,
		sub,
		mul,
		div,
	};

	union convert_union
	{
		uint_least64_t _integer;
		double _decimal;
		item_type _item_type;
		function_type _function_type;
	};

	class item_parameter
	{
	protected:
		item_type m_type;
		std::vector<uint_least64_t> m_data;

	public:
		item(item_type type)
		{
			m_type = type;
		}
	};

	class item_interface
	{
	public:
		uint_least64_t hoge;
	};
}

int main()
{
	cut_cut_cut::expression hoge;
	cut_cut_cut::calculator cal;

	std::cout << "define variable" << std::endl;
	hoge.define_variable({"sa" , "vb" , "mc" , "tsd" , "tvd" , "tme"});
	std::cout << std::endl;

	std::cout << "define body" << std::endl;
	hoge.define_body("\\add 1i0 \\mul 9i10 sa");
	std::cout << std::endl;

	std::cout << "set expression" << std::endl;
	cal.set_expression(hoge);
	std::cout << std::endl;

	return 0;
}
