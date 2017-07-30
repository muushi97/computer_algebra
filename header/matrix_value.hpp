#ifndef IG_MATRIX_VALUE_HPP
#define IG_MATRIX_VALUE_HPP

#include <vector>
#include <complex>

#include "matrix.hpp"
#include "value_interface.hpp"

namespace cut_cut_cut
{
	class matrix_value : public value_interface
	{
	private:
		little_mzk::matrix m_value;

	public:
		// コンストラクタ
		matrix_value();
		matrix_value(const little_mzk::matrix &value);
		matrix_value(const matrix_value &value);

		// 値を参照 ((i+1)行 (j+1)列目の要素を参照)
		virtual std::complex<double> &ref(unsigned int i, unsigned int j);
		virtual const std::complex<double> &ref(unsigned int i, unsigned int j) const;
		// 行と列を返す (それぞれ 行数 列数 を返す)
		virtual int row() const;
		virtual int column() const;
	};
}

#endif
