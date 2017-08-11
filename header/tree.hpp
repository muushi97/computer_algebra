#ifndef IG_TREE_HPP
#define IG_TREE_HPP

#include "node.hpp"

/*
 機能
 current				: カレントノードの値
 root					: ルートの値
 add_child			: 空の木ならルートを追加，それ以外なら現在のカレントノードに子ノードを追加(いちゃん若い子)
 							→ 木も追加可能
 add_sibling		: カレントノードの兄弟ノードを追加(いっちゃん若い子)．ルートの兄弟は作成不可
 							→ 木も追加可能
 move_root			: ルートに移動
 move_left_leaf	: いっちゃん左下のノードに移動
 move_next			: 深さ優先の後考順的に次のノードに移動

*/

namespace momiage
{
	template <typename T>
	class tree
	{
	private:
		node<T> *m_root;
		node<T> *m_current;

	public:
		tree()
		{
			m_root = m_current = nullptr;
		}
		tree(T data)
		{
			m_root = new node<T>(data);
			m_current = m_root;
		}

		T &current() const
		{
			return m_current->data;
		}
		const T &current()
		{
			return m_current->data;
		}

		T &root() const
		{
			return m_root->data;
		}
		const T &root()
		{
			return m_root->data;
		}

		// 子を追加 (ノードが存在しない場合は，rootを生成)
		void add_child(T data)
		{
			auto temp = new node<T>(data);

			if(m_current == nullptr)
			{
				m_root = temp;
				m_current = temp;
				return;
			}

			temp->parent = m_current;
			auto hoge = m_current->childs;
			while (hoge->brother[1] != nullptr)
			hoge = hoge->brother[1];
			hoge->brother[1] = temp;
			temp->brother[0] = hoge;
		}
		void add_child(T &data)
		{
			auto temp = new node<T>(data);

			if(m_current == nullptr)
			{
				m_root = temp;
				m_current = temp;
				return;
			}

			temp->parent = m_current;
			auto hoge = m_current->childs;
			while (hoge->brother[1] != nullptr)
			hoge = hoge->brother[1];
			hoge->brother[1] = temp;
			temp->brother[0] = hoge;
		}
		void add_child(tree<T> &other_tree)
		{
			auto temp = other_tree.m_root;
			other_tree.m_root = nullptr; other_tree.m_crrent = nullptr;

			if(m_current == nullptr)
			{
				m_root = temp;
				m_current = temp;
				return;
			}

			temp->parent = m_current;
			auto hoge = m_current->childs;
			while (hoge->brother[1] != nullptr)
				hoge = hoge->brother[1];
			hoge->brother[1] = temp;
			temp->brother[0] = hoge;
		}
		void add_sibling(T data)
		{
			if(m_root == m_current)
				return;

			auto temp = new node<T>(data);
			temp->parent = m_current->parent;
			auto hoge = m_current->parent->childs;
			while (hoge->brother[1] != nullptr)
				hoge = hoge->brother[1];
			hoge->brother[1] = temp;
			temp->brother[0] = hoge;
		}
		void add_sibling(T &data)
		{
			if(m_root == m_current)
				return;

			auto temp = new node<T>(data);
			temp->parent = m_current->parent;
			auto hoge = m_current->parent->childs;
			while (hoge->brother[1] != nullptr)
				hoge = hoge->brother[1];
			hoge->brother[1] = temp;
			temp->brother[0] = hoge;
		}
		void add_sibling(tree<T> &other_tree)
		{
			if(m_root == m_current)
				return;

			auto temp = other_tree.m_root;
			other_tree.m_root = nullptr; other_tree.m_crrent = nullptr;
			temp->parent = m_current->parent;
			auto hoge = m_current->parent->childs;
			while (hoge->brother[1] != nullptr)
				hoge = hoge->brother[1];
			hoge->brother[1] = temp;
			temp->brother[0] = hoge;
		}

		// topへ移動
		void move_root()
		{
			m_current = m_root;
		}

		// 今いる場所から左下に向かって移動
		void move_left_leaf()
		{
			while(m_current->childs != nullptr)
				m_current = m_current->childs;
		}

		// 深さ優先後考順での次のノードへ移動
		void move_next()
		{
			if(m_current->parent == nullptr)
				return;
			if(m_current->brother[1] == nullptr)
				m_current = m_current->parent;
			else
			{
				m_current = m_current->brother[1];
				move_left_leaf();
			}
		}

		// カレントを外して親へと移動
		tree<T> &remove()
		{
			tree<T> gomi;

			auto gomi_root = m_current;
			gomi_root->brother[0]->brother[1] = gomi_root->brother[1]->brother[0];
			m_current = gomi_root->parent;
			gomi_root = nullptr;

			gomi.m_current = gomi.m_root = gomi_root;

			return gomi;
		}

		~tree()
		{
			if (m_root == nullptr)
				return;

			move_root(); move_left_leaf();

			auto gomi = m_current;
			while (gomi != m_root)
			{
				if (gomi->brother[1] != nullptr)
					m_current = gomi->brother[1];
				else
					m_current = gomi->parent;
				delete gomi;
				gomi = m_current;
			}
		}
	};
}

#endif
