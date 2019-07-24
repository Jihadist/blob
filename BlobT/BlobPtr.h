#pragma once
#include "Blob.h"
#include <vector>
#include <memory>
#include <string>
template<typename >
class Blob;

template <typename T>
class BlobPtr
{
	friend bool eq(const BlobPtr&, const BlobPtr&);
public:
	BlobPtr():curr(0){}
	BlobPtr(Blob<T>& a, std::size_t sz = 0) :
		wptr(a.data), curr(sz) { }
	BlobPtr(const Blob<T>& a, const size_t sz = 0) : wptr(a.data), curr(sz) { }


	friend bool operator==(const BlobPtr&lhs, const BlobPtr<T>&rhs){ return lhs.curr==rhs.curr; }
	friend bool operator!=(const BlobPtr& lhs, const BlobPtr<T>& rhs) { return lhs.curr != rhs.curr; }
	friend bool operator<(const BlobPtr& lhs, const BlobPtr<T>& rhs) { return lhs.curr < rhs.curr; }
	friend bool operator>(const BlobPtr& lhs, const BlobPtr<T>& rhs) { return lhs.curr > rhs.curr; }
	friend bool operator<=(const BlobPtr& lhs, const BlobPtr<T>& rhs) { return lhs.curr <= rhs.curr; }
	friend bool operator>=(const BlobPtr& lhs, const BlobPtr<T>& rhs) { return lhs.curr >= rhs.curr; }

	T& operator[](size_t n);
	const T& operator[](size_t n) const;
	T& operator*() const;
	T* operator->() const;

	BlobPtr& operator++();
	BlobPtr& operator--();
	BlobPtr& operator++(int);
	BlobPtr& operator--(int);
	BlobPtr& operator+=(size_t);
	BlobPtr& operator-=(size_t);
	BlobPtr operator+(size_t) const;
	BlobPtr operator-(size_t) const;

	T& deref() const;
	BlobPtr& incr();
	BlobPtr& decr();
private:
	std::shared_ptr<std::vector<T>>
		check(size_t, const std::string&) const;
	std::weak_ptr<std::vector<T>> wptr;
	size_t curr;
};


