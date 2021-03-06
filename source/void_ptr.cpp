#include "void_ptr.hpp"

using namespace momiage;

void_ptr::void_ptr()
{
	m_pointer = nullptr;
}
void_ptr::void_ptr(void_ptr &obj)
{
	m_pointer = obj.m_pointer;
	deleter = obj.deleter;
	obj.m_pointer = nullptr;
}
void void_ptr::operator = (void_ptr &obj)
{
	m_pointer = obj.m_pointer;
	deleter = obj.deleter;
	obj.m_pointer = nullptr;
}

void *void_ptr::release()
{
	void *p = m_pointer;
	m_pointer = nullptr;
	return p;
}
void void_ptr::clear()
{
	if (m_pointer != nullptr)
		deleter(m_pointer);
	m_pointer = nullptr;
}

void *void_ptr::get()
{
	return m_pointer;
}

void_ptr::~void_ptr()
{
	if (m_pointer != nullptr)
		deleter(m_pointer);
}
