#include "matrix.hpp"

using namespace cut_cut_cut;

// 行数，及び列数変更時の配列サイズ変更 (元の値との整合性はとれない)
void matrix::update_array()
{
	m_value.resize(m_row * m_column);
}

// コンストラクタ
matrix::matrix() : matrix(0, 0)
{ }
matrix::matrix(unsigned int row, unsigned int column)
{
	change_size(row, column);
}

// 行数を変更
void matrix::change_row(unsigned int row);
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

// 値を参照する
// 列数 * row + column
std::complex &matrix::operator () (unsigned int row, unsigned int column)
{
	return m_value[m_row * row + column];
}
