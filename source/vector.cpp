#include "vector.hpp"

using namespace little_mzk;

// 行数，及び列数変更時の配列サイズ変更 (元の値との整合性はとれない)
void vector::update_array()
{
	m_value.resize(m_demention);
}

// コンストラクタ
vector::vector() : vector(0)
{ }
vector::vector(unsigned int demention)
{
	change_demention(demention);
}

// 代入演算子
const vector &vector::operator = (const vector &obj)
{
	m_demention = obj.m_demention;
	m_value = obj.m_value;
}

// 次元を変更
void vector::change_demention(unsigned int demention)
{
	m_demention = demention;
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
