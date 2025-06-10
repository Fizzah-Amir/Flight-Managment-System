#pragma once
#ifndef MYSTRING_H
#define MYSTRING_H
#include<iostream>
using namespace std;
class Mystring {
	int len;
	int cap;
	char* Cs;
	int length(const char* p);
	bool vowel(int i);
public:
	Mystring();
	Mystring(const char* cs);
	Mystring(char a, int d);
	Mystring(Mystring& s);
	void set(int no, char f);
	void replace_first(char c);
	~Mystring();
	void print()const;
	void print2(int* temp, Mystring s);
	int itos(int num);
	Mystring itoos(int num);
	void reverse(char*& p);
	int* stoi(const Mystring s);
	Mystring trim(Mystring& s);
	char operator[](int idx)const;
	char& operator[](int idx);
	bool is_equal(Mystring& M);
	bool is_less(Mystring& M);
	bool is_greater(Mystring& M);
	Mystring* split(char delim, int& c);
	int* search(Mystring s, int c);
	int find_first(char ch);
	int find_firsts(const Mystring& s);
	int find_last(char ch);
	int find_lasts(const Mystring& s);
	int* finds_all(char ch, int& c);
	void remove_at(int index);
	void insert_at(int index, char ch);
	void remove_first(char ch);
	void last_remove(char ch);
	void remove_all(char ch);
	void clear();
	void upper_to();
	void lower_to();
	Mystring* token(const char* delim, int& c);
	Mystring& vowels1(Mystring& s1);
	bool palindrome(Mystring& s1);
	friend ostream& operator<<(ostream& os, Mystring& s1);
	friend istream& operator>>(istream& is, Mystring& s1);
	Mystring& operator=(const Mystring& s1);
};
#endif;
