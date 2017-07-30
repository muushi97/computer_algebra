#include "vector_value.hpp"

using namespace cut_cut_cut;

// コンストラクタ
vector_value::vector_value()
{
	m_value.change_demention(1);
}
vector_value::vector_value(const little_mzk::vector &value)
{
	m_value = value;
}
vector_value::vector_value(const vector_value &value)
{
	m_value = value.m_value;
}

// 値を参照 ((i+1)個目の要素を参照，jは無視)
std::complex<double> &vector_value::ref(unsigned int i, unsigned int j)
{
	return m_value(i);
}
const std::complex<double> &vector_value::ref(unsigned int i, unsigned int j) const
{
	return m_value(i);
}
// 行と列を返す (行数は 次元，列数は -1 を返す)
int vector_value::row() const
{
	return m_value.demention();
}
int vector_value::column() const
{
	return -1;
}
