#include "scalar_value.hpp"

using namespace cut_cut_cut;

// コンストラクタ
scalar_value::scalar_value() : scalar_value(0.0, 0.0)
{ }
scalar_value::scalar_value(const std::complex<double> &value)
{
	m_value = value;
}
scalar_value::scalar_value(double real, double imaginary)
{
	m_value.real(real);
	m_value.imag(imaginary);
}
scalar_value::scalar_value(const scalar_value &value)
{
	m_value = value.m_value;
}

// 値を参照 (i , j によらず常に定数を返す)
std::complex<double> &scalar_value::ref(unsigned int i, unsigned int j)
{
	return m_value;
}
const std::complex<double> &scalar_value::ref(unsigned int i, unsigned int j) const
{
	return m_value;
}
// 値の種類を返す (cut_cut_cut::value_type::scalar を返す)
value_type scalar_value::type() const
{
	return cut_cut_cut::value_type::scalar;
}
