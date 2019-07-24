#include "BlobPtr.h"

template<typename T>
T& BlobPtr<T>::operator[](size_t n)
{
	auto p = check(n, "dereference out of range.");
	return (*p)[n];
}

template<typename T>
const T& BlobPtr<T>::operator[](size_t n) const
{
	auto p = check(n, "dereference out of range.");
	return (*p)[n];
}

template <typename T>
T& BlobPtr<T>::operator*() const
{
	auto p = check(curr, "derefernce past end");
	return (*p)[curr];
}

template<typename T>
T* BlobPtr<T>::operator->() const
{
	return &this->operator*();
}

template<typename T>
BlobPtr<T>& BlobPtr<T>::operator++()
{
	check(curr, "increment past end of StrBlobPtr");
	++curr;
	return *this;
}

template<typename T>
BlobPtr<T>& BlobPtr<T>::operator--()
{
	check(curr, "decrement past end of StrBlobPtr");
	--curr;
	return *this;
}

template<typename T>
BlobPtr<T>& BlobPtr<T>::operator++(int)
{
	BlobPtr ret = *this;
	++* this;
	return  ret;
	// TODO: вставьте здесь оператор return
}

template<typename T>
BlobPtr<T>& BlobPtr<T>::operator--(int)
{
	BlobPtr<T> ret = *this;
	--* this;
	return ret;
}

template<typename T>
BlobPtr<T>& BlobPtr<T>::operator+=(size_t n)
{
	curr += n;
	check(curr, "increment past end of BlobPtr");
	return *this;
}

template<typename T>
BlobPtr<T>& BlobPtr<T>::operator-=(size_t n)
{
	curr -= n;
	check(curr, "decrement past end of StrBlobPtr");
	return *this;
}

template<typename T>
BlobPtr<T> BlobPtr<T>::operator+(size_t n) const
{
	BlobPtr<T> ret = *this;
	ret += n;
	return ret;
}

template<typename T>
BlobPtr<T> BlobPtr<T>::operator-(size_t n) const
{
	BlobPtr<T> ret = *this;
	ret += n;
	return ret;
}

template<typename T>
T& BlobPtr<T>::deref() const
{
	auto p = check(curr, "dereference past end");
	return (*p)[curr];
}

template<typename T>
BlobPtr<T>& BlobPtr<T>::incr()
{
	check(curr, "increment past end of StrBlobPtr");
	++curr;
	return *this;
}

template<typename T>
BlobPtr<T>& BlobPtr<T>::decr()
{
	check(curr, "decrement past end of StrBlobPtr");
	--curr;
	return *this;
}

template<typename T>
std::shared_ptr<std::vector<T>> BlobPtr<T>::check(size_t i, const std::string &msg) const
{

	auto ret = wptr.lock();
	if (!ret)
		throw std::runtime_error("unbound StrBlobPtr");
	if (i >= ret->size())
		throw std::out_of_range(msg);
	return ret;
}
template <typename T>
bool operator==(const BlobPtr<T>& lhs, const BlobPtr<T>& rhs)
{
	return lhs.curr == rhs.curr;
}
template <typename T>
bool operator!=(const BlobPtr<T>& lhs, const BlobPtr<T>& rhs)
{
	return !(lhs == rhs);
}
template <typename T>
bool operator<(const BlobPtr<T>& lhs, const BlobPtr<T>& rhs)
{
	return lhs.curr < rhs.curr;
}
template <typename T>
bool operator>(const BlobPtr<T>& lhs, const BlobPtr<T>& rhs)
{
	return lhs.curr > rhs.curr;
}
template <typename T>
bool operator<=(const BlobPtr<T>& lhs, const BlobPtr<T>& rhs)
{
	return lhs.curr <= rhs.curr;
}
template <typename T>
bool operator>=(const BlobPtr<T>& lhs, const BlobPtr<T>& rhs)
{
	return lhs.curr >= rhs.curr;
}
