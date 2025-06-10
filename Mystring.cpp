#include<iostream>
#include "Mystring.h"
using namespace std;


Mystring::Mystring() {
	len = 0;
	cap = 0;
	Cs = nullptr;
}
Mystring::Mystring(const char* cs) {

	this->len = this->length(cs);
	this->cap = this->len;
	Cs = new char[len + 1] {};
	for (int i = 0; i < this->len; i++) {
		this->Cs[i] = cs[i];
	}
}

Mystring::Mystring(char a, int d)
{
	this->len = length(Cs);
	this->cap = this->len;
	len = d + 1;
	this->Cs = new char[len] {};
	for (int i = 0; i < len; i++) {
		this->Cs[i] = 'a';
	}
}
Mystring::Mystring(Mystring& s) {
	this->cap = s.cap;
	this->len = s.len;
	this->Cs = new char[len + 1] {};
	for (int i = 0; i < len; i++) {
		this->Cs[i] = s.Cs[i];
	}
	Cs[len] = '\0';
}
void  Mystring::set(int no, char f) {
	if (no > 0 && no < this->len) {
		Cs[no] = f;
	}
}
void  Mystring::replace_first(char c) {
	for (int i = 0; i < len; i++) {
		Cs[0] = c;
	}
}
int Mystring::length(const char* p) {
	int i = 0;
	while (p[i] != '\0') {
		i++;
	}
	return i;
}
bool  Mystring::vowel(int i) {
	if (Cs[i] == 'a' || Cs[i] == 'e' || Cs[i] == 'i' || Cs[i] == 'o' || Cs[i] == 'u') {
		return true;
	}
	return false;
}

Mystring::~Mystring() {
	delete[] this->Cs;
}
void  Mystring::print()const {
	for (int i = 0; i < this->len; i++) {
		cout << Cs[i];
	}
}
void  Mystring::print2(int* temp, Mystring s) {
	for (int i = 0; i < length(s.Cs); i++) {
		cout << temp[i];
	}
}
int Mystring::itos(int num) {
	int i = 0;
	char ch;
	while (num > 0) {
		num = num / 10;
		i++;
	}
	return i;
}
void  Mystring::reverse(char*& p) {
	int f = length(p);

	for (int i = 0; i < f / 2; i++) {
		char t = p[i];
		p[i] = p[f - 1 - i];
		p[f - 1 - i] = t;
	}
}
Mystring Mystring::itoos(int num) {
	this->cap = itos(num);
	this->len = itos(num);
	int i = 0;
	int no;
	char c;
	this->Cs = new char[len + 1];
	while (num > 0) {
		if (i < len) {
			no = num % 10;
			Cs[i] = no + '0';
			num = num / 10;
			i++;
		}
	}
	Cs[i] = '\0';
	reverse(Cs);

	return *this;
}
int* Mystring::stoi(const Mystring s) {
	int g = length(s.Cs);
	int* temp = new int[g];
	for (int i = 0; i < g; i++) {
		temp[i] = s.Cs[i] - '0';
	}
	return temp;
}

Mystring Mystring::trim(Mystring& s) {
	len = s.length(s.Cs);
	cap = s.length(s.Cs);
	int j = -1;
	int l = -1;
	for (int i = 0; i < s.len; i++) {
		if (s.Cs[i] != '\n' && s.Cs[i] != '\t' && s.Cs[i] != ' ') {
			j = i;
			break;
		}
	}
	for (int k = s.len - 1; k >= 0; k--) {
		if (s.Cs[k] != '\n' && s.Cs[k] != '\t' && s.Cs[k] != ' ') {
			l = k;
			break;
		}
	}
	len = l - j + 1;
	cap = l - j + 1;
	Cs = new char[len + 1] { 0 };
	for (int i = 0; i < len; i++) {
		Cs[i] = s.Cs[i + j];
	}
	Cs[len] = '\0';
	return *this;

}
char  Mystring :: operator[](int idx)const {
	for (int i = 0; i < len; i++) {
		if (idx > 0 and idx < len) {
			return Cs[idx];
		}
	}
}
char& Mystring::operator[](int idx) {
	for (int i = 0; i < len; i++) {
		if (idx > 0 and idx < len) {
			return Cs[idx];
		}
	}
}
bool  Mystring::is_equal(Mystring& M) {
	M.len = length(M.Cs);
	int count = 0;
	for (int i = 0; i < M.len; i++) {
		if (M.len == this->len) {
			if (Cs[i] == M.Cs[i]) {
				count++;
			}
		}
	}
	if (count == len) {
		return true;
	}
	return false;
}
bool  Mystring::is_less(Mystring& M) {
	M.len = length(M.Cs);
	int count = 0;
	for (int i = 0; i < M.len; i++) {
		if (Cs[i] < M.Cs[i]) {
			return true;
		}
		else {
			continue;
		}
	}
	return false;
}
bool  Mystring::is_greater(Mystring& M) {
	M.len = length(M.Cs);
	int count = 0;
	for (int i = 0; i < M.len; i++) {
		if (Cs[i] > M.Cs[i]) {
			return true;
		}
		else {
			continue;
		}
	}
	return false;
}
Mystring* Mystring::split(char delim, int& c)
{
	for (int i = 0; i < this->len; i++)
	{
		if (this->Cs[i] == delim)
			c++;
	}
	c++;
	Mystring* temp = new Mystring[c];
	int obj_c = 0;
	for (int i = 0; i < this->len; i++)
	{
		temp[obj_c].cap++;
		if (this->Cs[i] == delim)
			obj_c++;
	}
	for (int i = 0; i < c; i++)
	{
		temp[i].Cs = new char[temp[i].cap];
	}
	obj_c = 0;
	for (int i = 0; i < this->len; i++)
	{
		temp[obj_c].Cs[temp[obj_c].len] = this->Cs[i];
		temp[obj_c].len++;
		if (this->Cs[i] == delim)
			obj_c++;
	}

	return temp;
}

int* Mystring::search(Mystring s, int c) {
	for (int i = 0; i < s.len; i++) {
		if (s.Cs[i] == 'i' && s.Cs[i + 1] == 's') {
			c++;
		}
	}
	int* si = new int[c];
	int j = 0;
	for (int i = 0; i < s.len; i++) {
		if (s.Cs[i] == 'i' && s.Cs[i + 1] == 's') {
			si[j] = i;
			j++;
		}
	}
	for (int i = 0; i < c; i++) {
		cout << si[i];
	}
	return si;
}
int  Mystring::find_first(char ch) {
	len = length(Cs);
	for (int i = 0; i < this->len; i++) {
		if (Cs[i] == ch) {
			return i;
		}
	}
}
int  Mystring::find_firsts(const Mystring& s) {
	this->len = length(Cs);
	for (int i = 0; i < len - s.len; i++) {
		int j = 0;
		while (j < s.len && Cs[i + j] == s.Cs[j]) {
			j++;
		}
		if (j == s.len) {
			return i;
		}

	}

	return -1;
}
int  Mystring::find_last(char ch) {
	for (int i = this->len; i >= 0; i--) {
		if (Cs[i] == ch) {
			return i;
		}
	}
	return -1;
}
int Mystring::find_lasts(const Mystring& s) {
	int j = 0;
	for (int i = this->len - s.len; i >= 0; i--) {
		if (j < s.len && Cs[i + j] == s.Cs[j]) {
			j++;
		}
		if (j == s.len) {
			return i;
		}
	}
	return -1;
}
int* Mystring::finds_all(char ch, int& c) {

	for (int i = 0; i < this->len; i++) {
		if (Cs[i] == ch) {
			c++;
		}
	}
	int* arr = new int[c];
	int j = 0;
	for (int i = 0; i < this->len; i++) {
		if (Cs[i] == ch) {
			arr[j] = i;
			j++;
		}
	}
	return arr;
}

void  Mystring::remove_at(int index) {
	if (index >= 0 && index < this->len)
	{
		for (int j = index + 1; j < len; j++) {
			Cs[j - 1] = Cs[j];
		}
		len--;
	}
	return;
}
void  Mystring::insert_at(int index, char ch) {
	for (int i = len - 1; i >= index; i--) {
		Cs[i + 1] = Cs[i];
	}
	Cs[index] = ch;
}
void  Mystring::remove_first(char ch) {
	int k;
	for (int i = 0; i < len; i++) {
		if (Cs[i] == ch) {
			k = i;
			break;
		}
	}
	remove_at(k);
}
void  Mystring::last_remove(char ch) {
	int s = find_last(ch);
	remove_at(s);
}
void  Mystring::remove_all(char ch) {
	int c;
	int* s = finds_all(ch, c = 0);
	for (int i = 0; i < c; i++) {
		remove_at(s[i]);
	}
}
void  Mystring::clear() {
	len = 0;
}
void  Mystring::upper_to() {
	for (int i = 0; i < len; i++) {
		if (Cs[i] >= 65 && Cs[i] <= 90) {
			Cs[i] = Cs[i] + 32;
		}
	}
}
void  Mystring::lower_to() {
	for (int i = 0; i < len; i++) {
		if (Cs[i] >= 97 && Cs[i] <= 122) {
			Cs[i] = Cs[i] - 32;
		}
	}
}
Mystring* Mystring::token(const char* delim, int& c) {
	int i = 0;
	while (delim[i] != '\0') {
		i++;
	}
	for (int i = 0; i < this->len; i++) {
		for (int j = 0; j < 3; j++)
			if (Cs[i] == delim[j])
				c++;

	}
	Mystring* temp;
	temp = new Mystring[c];
	int obj_c = 0;
	for (int i = 0; i < this->len; i++) {
		temp[obj_c].cap++;
		if (Cs[i] == '.' || Cs[i] == ',' || Cs[i] == ' ')
			obj_c++;//har array ki cap brhti jaye

	}

	for (int i = 0; i < c; i++) {
		temp[i].Cs = new char[temp[i].cap];
	}
	obj_c = 0;
	for (int i = 0; i < this->len; i++) {
		temp[obj_c].Cs[temp[obj_c].len] = Cs[i];
		temp[obj_c].len++;
		if (Cs[i] == '.' || Cs[i] == ',' || Cs[i] == ' ') {
			obj_c++;
		}
	}
	return temp;
}



Mystring& Mystring::vowels1(Mystring& s1) {
	int count = 0;
	for (int i = 0; i < s1.len; i++) {
		if (s1.vowel(i)) {
			count++;
		}
	}
	int* idx = new int[count];
	int j = 0;
	if (count < s1.len)
	{
		for (int i = 0; i < s1.len; i++) {
			if (j < count)
			{
				if (s1.vowel(i))
				{
					idx[j] = i;
					j++;
				}
			}
		}
		for (int i = count - 1; i >= 0; i--) {
			remove_at(idx[i]);
		}
	}
	delete[] idx;
	return s1;
}
bool  Mystring::palindrome(Mystring& s1) {
	int i = 0;
	int j = len - 1;
	while (i < len / 2) {
		if (Cs[i] == Cs[j]) {
			j--;
			i++;
		}
	}
	if (i == j) {
		return true;
	}
	return false;
}
ostream& operator<<(ostream& os, Mystring& s1) {
	os << s1.Cs;
	return os;
}
istream& operator>>(istream& is, Mystring& s1) {
	is >> s1.Cs;
	return is;
}


Mystring& Mystring::operator=(const Mystring& s1) {
	if (this != &s1) {
		delete[] this->Cs;
		for (int i = 0; i < this->len; i++) {
			this->Cs[i] = s1.Cs[i];
		}
	}
	return *this;
}
