#include <cstdio>
#include <cstdint>
#include <iostream>
#include <vector>
#include <string>
#include <memory>

#include "expression.hpp"
#include "calculator.hpp"
#include "matrix.hpp"

int main()
{
	cut_cut_cut::expression hoge;
	cut_cut_cut::calculator cal;

	std::cout << "define variable" << std::endl;
	hoge.define_variable({"sa" , "vb" , "mc" , "tsd" , "tvd" , "tme"});
	std::cout << std::endl;

	std::cout << "define body" << std::endl;
	hoge.define_body("\\add 1i0 \\add 114i514 1919i810");
	std::cout << std::endl;

	std::cout << "set expression" << std::endl;
	cal.set_expression(hoge);
	std::cout << std::endl;

	std::cout << "calculate" << std::endl;
	cal.calculate();
	std::cout << std::endl;

	return 0;
}
