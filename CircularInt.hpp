#pragma once
#include<string> 
#include <iostream>
using namespace std;

// http://31.154.73.178:8000/?backend=5670&exercise=EX2

class CircularInt {
	int min;
	int max;
	int number;
public:
	CircularInt(CircularInt &p)
	{
		this->number = p.number;
		this->max = p.max;
		this->min = p.min;
	}

	CircularInt(int x, int y) {
		this->number = 1;
		this->min = x;
		this->max = y;
	}

	const CircularInt operator ++(int)
	{
		CircularInt newone(*this);
		int num;

		if (number == max) {
			num = min;
		}
		else
			num = number + 1;
		number = num;
		return newone;
	}
	CircularInt& operator ++()
	{
		int p;
		if (number == max) {
			p = min;
			number = p;
		}
		else
			p = number + 1;
		number = p;

		return *this;
	}

	CircularInt operator / (const int a)
	{
		CircularInt newCir(min, max);
		newCir.number = number / a;
		if (newCir.number < min) {
			newCir.number = max - newCir.number;
		}
		return newCir;
	}


	CircularInt operator-() {
		CircularInt temp(min, max);
		temp.number = number;

		temp.number = (-number) % max;
		if (temp.number == 0) {
			temp.number = max;
			return temp;
		}
		temp.number = max + temp.number;

		return temp;
	}

	friend ostream &operator<<(ostream &output, const CircularInt &temp) {
		output << temp.number;
		return output;
	}

	friend CircularInt operator-(int a, CircularInt &p)
	{
		CircularInt temp(p);
		int b = a - p.number;
		if (b < 0) {
			temp.number = abs(b);
			return temp;
		}
		else if (b == 0) {
			temp.number = p.max;
			return temp;
		}
		else {
			b = b % (p.max);  
			if (b == 0) { temp.number == temp.max; }
			else { temp.number = b; }
			return temp;
		}
	}

	CircularInt operator-(CircularInt &p)
	{
		CircularInt temp(*this); 
		/*temp = temp + (-p);
		if (temp.number > max)
			temp.number = temp.number%max;

		CircularInt temp(p);
		*/
		int num = temp.number - p.number;

		if (num < 0) {
			temp.number = abs(num);
		}
		else if (num == 0) { temp.number = temp.max; }
		else {
			num = num % temp.max;
			if (num == 0) { temp.number = temp.max; }
			else { temp.number = num; }
		}

		return temp;
	}

	CircularInt& operator += (int m) {
		int num = (number + m) % max;
		if (num == 0) {
			number = max;
		}
		else
		{
			number = num;
		}
		return *this;
	}

	CircularInt operator+(CircularInt p)
	{
		CircularInt temp(p);
		temp.number = number + p.number;
		if (temp.number > 12)
			temp.number = temp.number%max;

		return temp;
	}

	CircularInt operator+(int a)
	{
		CircularInt temp(min, max);
		temp.number = number + a;
		if (temp.number > 12)
			temp.number = temp.number%max;

		return temp;
	}

	friend CircularInt operator+(int a, CircularInt &p)
	{
		CircularInt temp(p.min, p.max);
		temp.number = a + p.number;
		if (temp.number > p.max)
			temp.number = temp.number%p.max;

		return temp;
	}

	CircularInt& operator *=(int m) {
		int num = (number * m) % max;
		if (num == 0) {
			number = max;
		}
		else {
			number = num;
		}
		return *this;
	}
	int operator /=(int m) {
		int num = (number / m) % max;
		if (num == 0) {
			num = max;
		}

		return num;
	}

	CircularInt operator -=(int m) {
		int sum, num = number - m;
		num = num % (max)+min;
		if (num > 0) {
			sum = num;
		}
		else
			sum = max + num;

		number = sum;
		return *this;
	}

	bool operator ==(CircularInt &p) {
		if (this->number == p.number && this->min == p.min && this->max == p.max) { return true; }
		else { return false; }
	}

	bool operator == (int num) {
		if (this->number == num) { return true; }
		else { return false; }
	}

	friend bool operator == (int num, CircularInt &p) {
		return (num == p.number);
	}

};
