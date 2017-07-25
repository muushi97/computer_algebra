#include "matrix_value.hpp"

using namespace cut_cut_cut;

// コンストラクタ
matrix_value::matrix_value()
{
	m_value.change_size(1, 1);
}
matrix_value::matrix_value(const little_mzk::matrix &value)
{
	m_value = value;
}
matrix_value::matrix_value(const matrix_value &value)
{
	m_value = value.m_value;
}

// 値を参照 ((i+1)行 (j+1)列目の要素を参照)
std::complex<double> &matrix_value::ref(unsigned int i, unsigned int j)
{
	return m_value(i , j);
}
const std::complex<double> &matrix_value::ref(unsigned int i, unsigned int j) const
{
	return m_value(i , j);
}
// 値の種類を返す (cut_cut_cut::value_type::matrix を返す)
value_type matrix_value::type() const
{
	return cut_cut_cut::value_type::matrix;
}
