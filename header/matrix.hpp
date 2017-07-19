#ifndef IG_MATRIX_HPP
#define IG_MATRIX_HPP

#include <vector>
#include <complex>

namespace cut_cut_cut
{
	class matrix
	{
	private:
		unsigned int m_row;								// 行数
		unsigned int m_column;							// 列数
		std::vector<std::complex<double>> m_value;		// 値リスト

		// 行数，及び列数変更時の配列サイズ変更 (元の値との整合性はとれない)
		void update_array();

	public:
		// コンストラクタ
		matrix();
		matrix(unsigned int row, unsigned int column);

		// 行数を変更
		void change_row(unsigned int row);
		// 列数を変更
		void change_column(unsigned int column);
		// 行列の大きさを変更
		void change_size(unsigned int row, unsigned int column);

		// 値を参照する
		std::complex<double> &operator () (unsigned int row, unsigned int column);
	};
}

#endif
