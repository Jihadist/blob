#pragma once
#include <vector>
#include <memory>
#include <string>
#include <stdexcept>
#include "BlobPtr.h"



template<typename T>
class Blob
{
	friend class BlobPtr<T>;
	friend bool operator==(const Blob<T>& lhs, const Blob<T>& rhs) { return *lhs.data == *rhs.data; }
	friend bool operator!=(const Blob<T>& lhs, const Blob<T>& rhs) { return *lhs.data != *rhs.data; }
	friend bool operator>(const Blob<T>& lhs, const Blob<T>& rhs) { return *lhs.data > * rhs.data; }
	friend bool operator<(const Blob<T>& lhs, const Blob<T>& rhs) { return *lhs.data < *rhs.data; }
	friend bool operator>=(const Blob<T>& lhs, const Blob<T>& rhs) { return *lhs.data >= *rhs.data; }
	friend bool operator<=(const Blob<T>& lhs, const Blob<T>& rhs) { return *lhs.data <= *rhs.data; }
public:
	typedef T value_type;
	typedef typename std::vector<T>::size_type size_type;

	Blob();

	Blob(std::initializer_list<T> il);

	template<typename It>
	Blob(It b, It e)
	{
		data(std::make_shared<std::vector<T>>(b, e));
	}

	BlobPtr<T> begin() { return BlobPtr<T>(*this); }
	BlobPtr<T> end(){ return BlobPtr<T>(*this, data->size()); };


	size_type size() const { return data->size(); }
	bool empty() const { return data->empty(); }

	void push_back(const T& t) { data->push_back(t); };
	void push_back(T&& t) { data->push_back(std::move(t)); }
	void pop_back() {
		check(0, "pop_back on empty blob");
		data->pop_back();
	}
	
	T& operator[](size_type i) {
		check(i, "subscript out of range");
		return (*data[i]);
	}
	const T& operator[](size_type i) const {
		check(i, "subscript out of range");
		return (*data[i]);
	}
	T& front() const{
		check(0, "front on empty StrBlob");
		return data->front();
	}
	T& back() const{
		check(0, "back on Empty StrBlob");
		return data->back();
	}
private:
	std::shared_ptr<std::vector<T>> data;
	void check(size_type i, const std::string& msg) const{
		if (i >= data->size())
			throw std::out_of_range(msg);
	}
};

template<typename T>
inline
Blob<T>::Blob(std::initializer_list<T> il) :
	data(std::make_shared<std::vector<T>>(il)) { }


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

