#ifndef IG_SCALAR_VALUE_HPP
#define IG_SCALAR_VALUE_HPP

#include "value_interface.hpp"

namespace cut_cut_cut
{
	class scalar_value : public value_interface
	{
	private:
		std::complex<double> m_value;

	public:
		// コンストラクタ
		scalar_value();
		scalar_value(const std::complex<double> &value);
		scalar_value(double real, double imaginary);
		scalar_value(const scalar_value &value);

		// 値を参照 (i , j によらず常に定数を返す)
		virtual std::complex<double> &ref(unsigned int i, unsigned int j);
		virtual const std::complex<double> &ref(unsigned int i, unsigned int j) const;
		// 行と列を返す (どっちも -1 を返す)
		virtual int row() const;
		virtual int column() const;
	};
}

#endif
