#include "Blob.h"



template<typename T>
BlobPtr<T> Blob<T>::begin()
{
	return BlobPtr<T>(*this);
}

template<typename T>
BlobPtr<T> Blob<T>::end()
{
	return BlobPtr<T>(*this, data->size());
}

template<typename T>
void Blob<T>::pop_back()
{
	check(0, "pop_back on empty blob");
	data->pop_back();
}

template<typename T>
T& Blob<T>::operator[](size_type i)
{
	check(i, "subscript out of range");
	return (*data[i]);
	// TODO: вставьте здесь оператор return
}

template<typename T>
const T& Blob<T>::operator[](size_type i) const
{
	check(i, "subscript out of range");
	return (*data[i]);
	// TODO: вставьте здесь оператор return
}

template<typename T>
T& Blob<T>::front() const
{
	// TODO: вставьте здесь оператор return
	check(0, "front on empty StrBlob");
	return data->front();
}

template<typename T>
T& Blob<T>::back() const
{
	check(0, "back on Empty StrBlob");
	return data->back();
	// TODO: вставьте здесь оператор return
}

template<typename T>
void Blob<T>::check(size_type i, const std::string& msg) const
{
	if (i >= data->size())
		throw std::out_of_range(msg);
}
template<typename T>
bool operator==(const Blob<T>& lhs, const Blob<T>& rhs)
{
	return *lhs.data == *rhs.data;
}
template<typename T>
bool operator!=(const Blob<T>& lhs, const Blob<T>& rhs)
{
	return !(lhs == rhs);
}
template<typename T>
bool operator>(const Blob<T>& lhs, const Blob<T>& rhs)
{
	return rhs < lhs;
}
template<typename T>
bool operator<(const Blob<T>& lhs, const Blob<T>& rhs)
{
	return std::lexicographical_compare(lhs.data->begin(), lhs.data->end(), rhs.data->begin(), rhs.data->end());
}
template<typename T>
bool operator<=(const Blob<T>& lhs, const Blob<T>& rhs)
{
	return !(rhs < lhs);
}
template<typename T>
bool operator>=(const Blob<T>& lhs, const Blob<T>& rhs)
{
	return !(lhs < rhs);
}
