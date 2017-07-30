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
// 行と列を返す (それぞれ 行数 列数 を返す)
int matrix_value::row() const
{
	return m_value.row();
}
int matrix_value::column() const
{
	return m_value.column();
}
