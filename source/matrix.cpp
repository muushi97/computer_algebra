#include "matrix.hpp"

using namespace little_mzk;

// 行数，及び列数変更時の配列サイズ変更 (元の値との整合性はとれない)
void matrix::update_array()
{
	m_value.resize(m_row * m_column);
}

// コンストラクタ
matrix::matrix() : matrix(1, 1)
{ }
matrix::matrix(unsigned int row, unsigned int column)
{
	change_size(row, column);
}

// 代入演算子
const matrix &matrix::operator = (const matrix &obj)
{
	m_row = obj.m_row;
	m_column = obj.m_column;
	m_value = obj.m_value;
}

// 行数を変更
void matrix::change_row(unsigned int row)
{
	m_row = row;
	update_array();
}
// 列数を変更
void matrix::change_column(unsigned int column)
{
	m_column = column;
	update_array();
}
// 行列の大きさを変更
void matrix::change_size(unsigned int row, unsigned int column)
{
	m_row = row;
	m_column = column;
	update_array();
}

// 行数
unsigned int matrix::row() const
{
	return m_row;
}
// 列数
unsigned int matrix::column() const
{
	return m_column;
}

// 値を参照する
// 列数 * row + column
std::complex<double> &matrix::operator () (unsigned int row, unsigned int column)
{
	return m_value[m_row * row + column];
}
const std::complex<double> &matrix::operator () (unsigned int row, unsigned int column) const
{
	return m_value[m_row * row + column];
}
