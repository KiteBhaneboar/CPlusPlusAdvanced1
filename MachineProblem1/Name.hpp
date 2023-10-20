#pragma once
#include <string>

using namespace std; 


class Name
{
private:
	string first = "";
	string father = "";
	string family = "";
public:
	Name(string f, string r, string m)
	{
		first = f;
		father = r;
		family = m;
	};
	void setValues(string f, string r, string m) { first = f; father = r; family = m; };
	string getFirst() { return first; };
	string getFather() { return father; };
	string getFamily() { return family; };
	void outputData();
};