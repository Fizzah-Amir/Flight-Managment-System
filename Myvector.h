#pragma once
#ifndef MYVECTOR_H
#define MYVECTOR_H
#include <iostream>
using namespace std;
template <typename V>
class MyVector {
private:
	V* arr;
	int len;
	int cap;
void double_capacity()
	{
		V* temp;
		int l = this->len;
		int cp = this->cap + this->cap + 1;
		temp = new V[cp];
		for (int i = 0; i < l; i++)
		{
			temp[i] = this->arr[i];
		}
		delete[] this->arr;
		this->cap = cp;
		this->len = l;
		this->arr = temp;
	}
public:
	MyVector()
	{
		this->cap = 0;
		this->len = 0;
		this->arr = nullptr;
	}
	MyVector(const V* a1, int l)
	{
		this->cap = l;
		this->len = l;
		this->arr = new V[l];
		for (int i = 0; i < this->len; i++)
			this->arr[i] = a1[i];
	}
	MyVector(int count, V value)
	{
		this->cap = count;
		this->arr = new V[this->cap];
		for (this->len = 0; this->len < this->cap; this->len++)
		{
			this->arr[this->len] = value;
		}
	}
	MyVector(const MyVector& other)
	{
		this->cap = other.cap;
		this->len = other.len;
		this->arr = new V[this->cap];
		for (int i = 0; i < this->len; i++)
		{
			this->arr[i] = other.arr[i];
		}
	}
	~MyVector()
	{
		delete[] arr;

	}
	void Print()const
	{
		cout << "{";
		for (int i = 0; i < this->len; i++)
		{
			if (i != this->len - 1)
				cout << this->arr[i] << " , ";
			else
				cout << this->arr[i];
		}
		cout << "}";
	}
	int get_len()const
	{
		return this->len;
	}

	MyVector& operator=(const MyVector& other)
	{
		if (this != &other) {
			delete[] this->arr;
			this->cap = other.cap;
			this->len = other.len;
			this->arr = new	V[this->cap];
			for (int i = 0; i < this->len; i++)
				this->arr[i] = other.arr[i];
		}
		return *this;
	}
	V& operator[](int index)
	{
		return this->arr[index];
	}
	const V& operator[](int index) const
	{
		return this->arr[index];
	}
	bool operator==(const MyVector& other) const
	{
		if (this->len != other.len)
			return 0;
		for (int i = 0; i < this->len; i++)
		{
			if (this->arr[i] != other.arr[i])
				return 0;
		}
		return 1;
	}
	bool operator!=(const MyVector& other) const
	{
		if (this->len != other.len)
			return 1;
		for (int i = 0; i < this->len; i++)
		{
			if (this->arr[i] != other.arr[i])
				return 1;
		}
		return 0;
	}
	MyVector operator+(const MyVector& other) const
	{
		MyVector res(this->len + other.len, V());
		res.len = 0;
		for (int i = 0; i < this->len; i++)
		{
			res.arr[i] = this->arr[i];
			res.len++;
		}
		for (int i = 0; i < other.len; i++)
		{
			res.arr[res.len] = other.arr[i];
			res.len++;
		}
		return res;
	}
	MyVector& operator+=(const MyVector& other)
	{
		for (int i = 0; i < other.cap; i++)
		{
			if (this->len == this->cap)
				this->double_capacity();
			this->arr[this->len] = other.arr[i];
			this->len++;
		}
		return *this;
	}


	void push(V value)
	{
		if (this->len == this->cap)
			this->double_capacity();
		this->arr[this->len] = value;
		this->len++;
	}
	void pop()
	{
		this->arr[this->len - 1] = V();
		this->len--;

	}
	void insert_at(int index, V value)
	{
		if (index < 0 || index > this->cap)
			return;
		if (this->cap == this->len)
			this->double_capacity();
		for (int i = this->len + 1; i > index; i--)
		{
			this->arr[i] = this->arr[i - 1];
		}
		this->arr[index] = value;

	}
	void delete_at(int index)
	{
		for (int i = index; i < this->len - 1; i++)
		{
			this->arr[i] = this->arr[i + 1];
		}
		this->len--;
	}
	void reserve(int new_capacity)
	{
		V* temp = new V[this->cap + new_capacity];
		for (int i = 0; i < this->len; i++)
			temp[i] = this->arr[i];
		delete[] this->arr;

		this->cap += new_capacity;
		this->arr = temp;
	}
	void clear()
	{
		for (int i = 0; i < this->len; i++)
		{
			this->arr[i] = V();
		}
		this->len = 0;
	}
	void swap(MyVector& other) {
		V* temp = this->arr;
		this->arr = other.arr;
		other.arr = temp;

		int t = this->len;
		this->len = other.len;
		other.len = t;

		t = this->cap;
		this->cap = other.cap;
		other.cap = t;
	}
	void shrink_to_fit()
	{
		V* temp = new V[this->len];

		for (int i = 0; i < this->len; i++)
			temp[i] = this->arr[i];
		this->arr = temp;
	}
	void reverse()
	{
		V* temp = new V[this->len];
		for (int i = 0; i < this->len; i++)
			temp[i] = this->arr[i];
		int j = this->len - 1;

		for (int i = 0; i < this->len; i++)
		{
			arr[j] = temp[i];
			j--;
		}

	}
	bool empty() const
	{
		if (this->len == 0)
			return 1;
		return 0;
	}
	int size() const
	{
		return this->len;
	}

	V& at(int index)
	{
		if (index < 0 || index >= this->cap)
		{
			cout << "Invalid Index!" << endl;
			return this->arr[0];
		}
		return this->arr[index];
	}
	const V& at(int index) const
	{
		if (index < 0 || index >= this->cap)
		{
			cout << "Invalid Index!" << endl;
			return this->arr[0];
		}
		return this->arr[index];
	}

	V& front()
	{
		return this->arr[0];

	}
	const V& front() const
	{
		return this->arr[0];
	}

	V& back()
	{
		if (this->len != 0)
		{
			return this->arr[this->len - 1];
		}
	}
	const V& back() const
	{
		if (this->len != 0)
		{
			return this->arr[this->len - 1];
		}
	}

	int find(V value) const
	{
		for (int i = 0; i < this->len; i++)
		{
			if (this->arr[i] == value)
				return i;
		}
		return -1;
	}
};

#endif 
