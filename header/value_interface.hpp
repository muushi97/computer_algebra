#ifndef IG_VALUE_INTERFACE_HPP
#define IG_VALUE_INTERFACE_HPP

#include <complex>

namespace cut_cut_cut
{
	class value_interface
	{
	public:
		// 値を参照
		virtual std::complex<double> &ref(unsigned int i, unsigned int j) = 0;
		virtual const std::complex<double> &ref(unsigned int i, unsigned int j) const = 0;
		// 行と列を返す
		virtual int row() const = 0;
		virtual int column() const = 0;
	};
}

#endif
