#pragma once
#include <vector>
#include <memory>
#include <string>
#include <stdexcept>
#include "BlobPtr.h"

template<typename >
class BlobPtr;

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

	//Blob();
	Blob(std::initializer_list<T> il);
	//Blob():data(std::make_shared<std::vector<T>>()) {}



	BlobPtr<T> begin();
	BlobPtr<T> end();


	size_type size() const { return data->size(); }
	bool empty() const { return data->empty(); }

	void push_back(const T& t) { data->push_back(t); };
	void push_back(T&& t) { data->push_back(std::move(t)); }
	void pop_back();
	
	T& operator[] (size_type i);
	const T& operator[] (size_type i) const;

	T& front() const;
	T& back() const;
private:
	std::shared_ptr<std::vector<T>> data;
	void check(size_type i, const std::string& msg) const;
};


