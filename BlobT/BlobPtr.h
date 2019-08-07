#pragma once
#include "Blob.h"
#include <vector>
#include <memory>
#include <string>
template<typename T>
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

	T& operator[](size_t n){
		auto p = check(n, "dereference out of range.");
		return (*p)[n];
	}
	const T& operator[](size_t n) const{
		auto p = check(n, "dereference out of range.");
		return (*p)[n];
	}
	T& operator*() const{
		auto p = check(curr, "derefernce past end");
		return (*p)[curr];
	}
	T* operator->() const{ return &this->operator*(); }

	BlobPtr& operator++(){
		check(curr, "increment past end of StrBlobPtr");
		++curr;
		return *this;
	}
	BlobPtr& operator--(){
		check(curr, "decrement past end of StrBlobPtr");
		--curr;
		return *this;
	}
	BlobPtr& operator++(int){
		BlobPtr ret = *this;
		++* this;
		return  ret;
	}
	BlobPtr& operator--(int){
		BlobPtr<T> ret = *this;
		--* this;
		return ret;
	}
	BlobPtr& operator+=(size_t n){
		curr += n;
		check(curr, "increment past end of BlobPtr");
		return *this;
	}
	BlobPtr& operator-=(size_t n){
		curr -= n;
		check(curr, "decrement past end of StrBlobPtr");
		return *this;
	}
	BlobPtr operator+(size_t n) const{
		BlobPtr<T> ret = *this;
		ret += n;
		return ret;
	}
	BlobPtr operator-(size_t n) const{
		BlobPtr<T> ret = *this;
		ret += n;
		return ret;
	}

	T& deref() const{
		auto p = check(curr, "dereference past end");
		return (*p)[curr];
	}
	BlobPtr& incr(){
		check(curr, "increment past end of StrBlobPtr");
		++curr;
		return *this;
	}
	BlobPtr& decr(){
		check(curr, "decrement past end of StrBlobPtr");
		--curr;
		return *this;
	}
private:
	std::shared_ptr<std::vector<T>>
		check(size_t i, const std::string& msg) const
	{
		auto ret = wptr.lock();
		if (!ret)
			throw std::runtime_error("unbound StrBlobPtr");
		if (i >= ret->size())
			throw std::out_of_range(msg);
		return ret;
	}
	std::weak_ptr<std::vector<T>> wptr;
	size_t curr;
};