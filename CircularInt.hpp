#pragma once
#include<string> 
#include <iostream>
using namespace std;



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
			this->max= y;
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
			number=num;
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

		int operator-() {
			int num = (-number)%max;
			if (num == 0) {
				num = max;
				return num;
			}
			num = max + num;
			return num;
		}

		friend ostream &operator<<(ostream &output, const CircularInt &temp) {
			output << temp.number;
			return output;
		}

		friend CircularInt operator-(int a,CircularInt &p)
		{
			CircularInt temp(p);
			int b = a - p.number;
			if (b > 0) {
				temp.number = b;
				return temp;
			}
			else if (b == 0) {
				temp.number = p.max;
				return temp;
			}
			else {
				b = b%(p.max);
				b = p.max + b;
				temp.number = b;
				return temp;
			}
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

		CircularInt operator+(CircularInt &p)
		{
			CircularInt temp(p);
			temp.number = number + p.number;
			if (temp.number > 12)
				temp.number = temp.number%max;

			return temp;
		}
		
		CircularInt& operator *=(int m) {
			int num = (number * m)%max;
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



		};