#pragma once

#include "SimpleIterator.h"

template <typename T>
class TSimpleContainer
{
private:
	size_t m_capacity;
	T* m_pBuffer;

	size_t m_size;

public:
	explicit TSimpleContainer(size_t capacity = 0);

	size_t GetCapacity() const;
	size_t GetSize() const;

	void Insert(const std::initializer_list<T>& list);
	void Insert(const T&);

	TSimpleIterator<T> begin();
	TSimpleIterator<T> end();

private:
	void ReallocateMemory();

};

template <typename T>
TSimpleContainer<T>::TSimpleContainer(size_t capacity) :
	m_capacity{ capacity },
	m_pBuffer{ new T[capacity + 1] },
	m_size{ 0 }
{

}

template <typename T>
size_t TSimpleContainer<T>::GetCapacity() const
{
	return m_capacity;
}

template <typename T>
size_t TSimpleContainer<T>::GetSize() const
{
	return m_size;
}

template <typename T>
void TSimpleContainer<T>::Insert(const std::initializer_list<T>& list)
{
	for (auto& value : list)
	{
		Insert(value);
	}

	return;
}

template <typename T>
void TSimpleContainer<T>::Insert(const T& value)
{
	if (m_size >= m_capacity)
	{
		ReallocateMemory();
	}

	if (m_size < m_capacity)
	{
		m_pBuffer[m_size++] = value;
	}
}

template <typename T>
TSimpleIterator<T> TSimpleContainer<T>::begin()
{
	return TSimpleIterator<T>(m_pBuffer);
}

template <typename T>
TSimpleIterator<T> TSimpleContainer<T>::end()
{
	return TSimpleIterator<T>(m_pBuffer + m_size);
}

template <typename T>
void TSimpleContainer<T>::ReallocateMemory()
{
	// In case of capacity == 0 we reallocate memory for 4 elements, else we double up memory
	size_t capacity = (m_capacity == 0) ? capacity = 4 : capacity = m_capacity * 2;
	T* pBuffer = new T[capacity];

	std::copy(m_pBuffer, m_pBuffer + m_size, pBuffer);

	delete[] m_pBuffer;

	m_pBuffer = pBuffer;
	m_capacity = capacity;

	return;
}