#ifndef IG_VECTOR_HPP
#define IG_VECTOR_HPP

#include <vector>
#include <complex>

namespace little_mzk
{
	class vector
	{
	private:
		unsigned int m_dimension;						// 次元
		std::vector<std::complex<double>> m_value;		// 値リスト

		// 次元変更時の配列サイズ変更 (元の値との整合性はとれない)
		void update_array();

	public:
		// コンストラクタ
		vector();
		vector(unsigned int dimension);

		// 代入演算子
		const vector &operator = (const vector &obj);

		// 次元を変更
		void change_dimension(unsigned int dimension);

		// 次元
		unsigned int dimension() const;

		// 値を参照する
		std::complex<double> &operator () (unsigned int i);
		const std::complex<double> &operator () (unsigned int i) const;
	};
}

#endif
