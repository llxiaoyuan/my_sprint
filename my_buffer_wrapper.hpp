#pragma once
#include "AllocFree.h"

class my_buffer_wrapper
{
public:
	my_buffer_wrapper(void* buffer) { m_buffer = buffer; }
	~my_buffer_wrapper() { if (m_buffer) { Free(m_buffer); } }
	char* as_str() { return (char*)m_buffer; }
	wchar_t* as_wstr() { return (wchar_t*)m_buffer; }
private:
	void* m_buffer;
};

/*
	printf("%s\n", my_buffer_wrapper(my_sprintf_alloc("hello %d", 1)).as_str());
	printf("%S\n", my_buffer_wrapper(my_wsprintf_alloc(L"hello %d", 1)).as_wstr());
*/