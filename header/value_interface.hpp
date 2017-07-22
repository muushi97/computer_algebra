#ifndef IG_VALUE_INTERFACE_HPP
#define IG_VALUE_INTERFACE_HPP

#include <complex>

namespace cut_cut_cut
{
	enum value_type
	{
		scalar,
		vector,
		matrix,
	};

	class value_interface
	{
	public:
		// 値を参照
		virtual std::complex<double> &ref(unsigned int i, unsigned int j) = 0;
		virtual const std::complex<double> &ref(unsigned int i, unsigned int j) const = 0;
		// 値の種類を返す
		virtual value_type type() const = 0;
	};
}

#endif
