#pragma once

#include <iterator>

template <typename T>
class TSimpleIterator:
	public std::iterator<std::input_iterator_tag, T>
{
private:
	T* m_pObject;

public:
	explicit TSimpleIterator(T*);

	TSimpleIterator<T>& operator++();
	
	bool operator!=(const TSimpleIterator&) const;

	T& operator*() const;

};

template <typename T>
TSimpleIterator<T>::TSimpleIterator(T* pObject) :
	m_pObject{ pObject }
{

}

template <typename T>
TSimpleIterator<T>& TSimpleIterator<T>::operator++()
{
	++m_pObject;
	
	return *this;
}

template <typename T>
bool TSimpleIterator<T>::operator!=(const TSimpleIterator& iter) const
{
	return m_pObject != iter.m_pObject;
}

template <typename T>
T& TSimpleIterator<T>::operator*() const
{
	return *m_pObject;
}