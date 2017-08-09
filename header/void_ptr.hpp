#ifndef IG_VOID_PTR_HPP
#define IG_VOID_PTR_HPP

#include <functional>

namespace momiage
{
	class void_ptr
	{
	private:
		void *m_pointer;
		std::function<void(void*)> deleter;

	public:
		void_ptr();
		void_ptr(const void_ptr&) = delete;
		void_ptr& operator = (const void_ptr&) = delete;

		void *release();
		template <typename T> void reset(T *pointer);
		void reset();

		void *get();

		~void_ptr();
	};
}

template <typename T>
void momiage::void_ptr::reset(T *pointer)
{
	if (m_pointer != nullptr)
		deleter(m_pointer);
	m_pointer = static_cast<void *>(pointer);
	deleter = [](void* p){delete static_cast<T *>(p);};
}

#endif
