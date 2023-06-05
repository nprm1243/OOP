#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <math.h>
using namespace std;

class Vector {
private:
	vector<int> vec;
public:
	Vector(vector<int> vec) {
		this->vec = vec;
	}
	Vector(int n) {
		vector<int> tmp;
		for (int i=0; i<n; i++) tmp.push_back(0);
		this->vec = tmp;
	}
	Vector() {
	}

	// setters/ getters
	int getLen() {
		return int(this->vec.size());
	}
	int getValue(int i) {
		return this->vec[i];
	}
	void resize(int n) {
		this->vec.clear();
		for (int i=0; i<n; i++) this->vec.push_back(0);
	}

	// overloading operator []
	int operator[] (const int& i) {
		if (i > this->getLen())
			throw std::invalid_argument("getting value that not appear in vectors!");
		else 
			return this->getValue(i);
	}
	
	// overloading assign operator
	void operator= (const Vector& otherVector) {
		this->vec = otherVector.vec;
	}
	
	// overloading operators +
	Vector operator+ (const Vector& otherVector) {
		if (this->vec.size() != otherVector.vec.size())
			throw std::invalid_argument("2 vectors must have the same size!");
		else {
			Vector ret(this->vec.size());
			for (int i=0; i<int(this->vec.size()); i++) ret.vec[i] = this->vec[i] + otherVector.vec[i];
			return ret;
		}
	}
	Vector operator+ (const int& number) {
		Vector ret(this->vec.size());
		for (int i=0; i<int(this->vec.size()); i++) ret.vec[i] = this->vec[i] + number;
		return ret;
	}
	Vector& operator++() {
		for (int i=0; i<int(this->vec.size()); i++) this->vec[i]++;
		return *this;
	}
	Vector operator++(int) {
		Vector temp = *this;
		for (int i=0; i<int(this->vec.size()); i++) this->vec[i]++;
		return temp;
	}
	Vector& operator+=(const Vector& otherVector) {
		if (this->vec.size() != otherVector.vec.size())
			throw std::invalid_argument("2 vectors must have the same size!");
		else
			for (int i=0; i<int(this->vec.size()); i++) this->vec[i] += otherVector.vec[i];
		return *this;
	}
	Vector& operator+=(const int& number) {
		for (int i=0; i<int(this->vec.size()); i++) this->vec[i] += number;
		return *this;
	}

	// overloading operators -
	Vector operator- (const Vector& otherVector) {
		if (this->vec.size() != otherVector.vec.size())
			throw std::invalid_argument("2 vectors must have the same size!");
		else {
			Vector ret(this->vec.size());
			for (int i=0; i<int(this->vec.size()); i++) ret.vec[i] = this->vec[i] - otherVector.vec[i];
			return ret;
		}
	}
	Vector operator- (const int& number) {
		Vector ret(this->vec.size());
		for (int i=0; i<int(this->vec.size()); i++) ret.vec[i] = this->vec[i] - number;
		return ret;
	}
	Vector& operator--() {
		for (int i=0; i<int(this->vec.size()); i++) this->vec[i]--;
		return *this;
	}
	Vector operator--(int) {
		Vector temp = *this;
		for (int i=0; i<int(this->vec.size()); i++) this->vec[i]--;
		return temp;
	}
	Vector& operator-=(const Vector& otherVector) {
		if (this->vec.size() != otherVector.vec.size())
			throw std::invalid_argument("2 vectors must have the same size!");
		else
			for (int i=0; i<int(this->vec.size()); i++) this->vec[i] -= otherVector.vec[i];
		return *this;
	}
	Vector& operator-=(const int& number) {
		for (int i=0; i<int(this->vec.size()); i++) this->vec[i] -= number;
		return *this;
	}

	// overloading operators *
	int operator* (const Vector& otherVector) {
		if (this->vec.size() != otherVector.vec.size())
			throw std::invalid_argument("2 vectors must have the same size!");
		else {
			int ret = 0;
			for (int i=0; i<int(this->vec.size()); i++) ret += this->vec[i] * otherVector.vec[i];
			return ret;
		}
	}
	int operator* (const int& number) {
		int ret = 0;
		for (int i=0; i<int(this->vec.size()); i++) ret += this->vec[i] * number;
		return ret;
	}
	Vector& operator*=(const Vector& otherVector) {
		if (this->vec.size() != otherVector.vec.size())
			throw std::invalid_argument("2 vectors must have the same size!");
		else {
			for (int i=0; i<int(this->vec.size()); i++) this->vec[i] *= otherVector.vec[i];
			return *this;
		}
	}
	Vector& operator*=(const int& number) {
		for (int i=0; i<int(this->vec.size()); i++) this->vec[i] *= number;
		return *this;
	}

	// overloading compare operators
	bool operator== (const Vector& otherVector) {
		if (this->vec.size() != otherVector.vec.size())
			throw std::invalid_argument("2 vectors must have the same size!");
		else {
			int ret = 0;
			for (int i=0; i<int(this->vec.size()); i++) 
				if (this->vec[i] != otherVector.vec[i])
					return false;
			return true;
		}
	}
	bool operator!= (const Vector& otherVector) {
		if (this->vec.size() != otherVector.vec.size())
			throw std::invalid_argument("2 vectors must have the same size!");
		else {
			int ret = 0;
			for (int i=0; i<int(this->vec.size()); i++) 
				if (this->vec[i] != otherVector.vec[i])
					return true;
			return false;
		}
	}

	// overloading stream operators
	friend istream &operator>>(istream &input, Vector &v) {
		int n;
		input >> n;
		v.resize(n);
		for (int i=0; i<n; i++) input >> v.vec[i];
		return input;
	}
	friend ostream &operator<<(ostream &output, Vector &v) {
		output << "(";
		for (int i=0; i<int(v.vec.size())-1; i++) output << v.vec[i] << " ";
		cout << v.vec[int(v.vec.size())-1] << ")";
		return output;
	}

	// overloading new/delete operators
	void * operator new(size_t size) {
        void * p = ::operator new(size);
        return p;
    }
    void operator delete(void * p) {
        free(p);
    }
};

// test class Vector
int main()
{
	Vector hihi;
	Vector huhu;
	cin >> hihi;
	cin >> huhu;
	for (int i=0; i<hihi.getLen(); i++) cout << hihi[i] << " ";
}
