#include "vector.hpp"

using namespace little_mzk;

// 行数，及び列数変更時の配列サイズ変更 (元の値との整合性はとれない)
void vector::update_array()
{
	m_value.resize(m_dimension);
}

// コンストラクタ
vector::vector() : vector(1)
{ }
vector::vector(unsigned int dimension)
{
	change_dimension(dimension);
}

// 代入演算子
const vector &vector::operator = (const vector &obj)
{
	m_dimension = obj.m_dimension;
	m_value = obj.m_value;
}

// 次元を変更
void vector::change_dimension(unsigned int dimension)
{
	m_dimension = dimension;
	update_array();
}

// 次元
unsigned int vector::dimension() const
{
	return m_dimension;
}

// 値を参照する
// 列数 * row + column
std::complex<double> &vector::operator () (unsigned int i)
{
	return m_value[i];
}
const std::complex<double> &vector::operator () (unsigned int i) const
{
	return m_value[i];
}
