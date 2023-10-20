#pragma once
#include <iostream>
using namespace std;

class Date
{
private:
	int day = 1;
	int month = 1;
	int year = 1990;
public:
	Date(int d, int m, int y)
	{
		day = d;
		month = m;
		year = y;
	};
	void SetValues(int d, int m, int y) { day = d; month = m; year = y; };
	int getDay() { return day; };
	int getMonth() { return month; };
	int getYear() { return year; };
	void outputData();


};