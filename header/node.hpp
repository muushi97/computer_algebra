#ifndef IG_NODE_HPP
#define IG_NODE_HPP

#include <array>

namespace momiage
{
	template <typename T>
	class node
	{
	public:
		T data;					// データ

		node *parent;						// 親のポインタ
		node *childs;						// 子供の先頭
		std::array<node *, 2> brother;	// 兄弟

		node();
		node(T &data);

		~node();
	};
}

template <typename T>
momiage::node<T>::node()
{
	parent = childs = brother[0] = brother[1] = nullptr;
}

template <typename T>
momiage::node<T>::node(T &obj)
{
	parent = childs = brother[0] = brother[1] = nullptr;
	data = obj;
}

template <typename T>
momiage::node<T>::~node()
{ }

#endif
