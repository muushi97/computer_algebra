#ifndef IG_MATRIX_VALUE_HPP
#define IG_MATRIX_VALUE_HPP

#include <vector>
#include <complex>

#include "vector.hpp"
#include "value_interface.hpp"

namespace cut_cut_cut
{
	class vector_value : public value_interface
	{
	private:
		little_mzk::vector m_value;

	public:
		// コンストラクタ
		vector_value();
		vector_value(const little_mzk::vector &value);
		vector_value(const vector_value &value);

		// 値を参照 ((i+1)個目の要素を参照，jは無視)
		virtual std::complex<double> &ref(unsigned int i, unsigned int j);
		virtual const std::complex<double> &ref(unsigned int i, unsigned int j) const;
		// 行と列を返す (行数は 次元，列数は -1 を返す)
		virtual int row() const;
		virtual int column() const;
	};
}

#endif
