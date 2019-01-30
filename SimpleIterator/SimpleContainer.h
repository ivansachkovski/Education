#pragma once

template <typename T>
class TSimpleContainer
{
private:
	size_t m_capacity;
	T* m_pBuffer;

	size_t m_size;

public:
	explicit TSimpleContainer(size_t capacity);

	void Insert(const T& value);

	TSimpleIterator<T> begin();
	TSimpleIterator<T> end();

};

template <typename T>
TSimpleContainer<T>::TSimpleContainer(size_t capacity) :
	m_capacity{ capacity },
	m_pBuffer{ new T[capacity + 1] },
	m_size{ 0 }
{

}

template <typename T>
void TSimpleContainer<T>::Insert(const T& value)
{
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