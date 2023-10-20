#pragma once
#include <iostream>
#include <string>

using namespace std;


enum Restrictions
{
	None,
	Glasses,
	Earphones,
	Automatic,
	Disabled,
	Lenses,
	Deaf
};



class LicenseRestrictions
{
	Restrictions number;
	string restriction;

public:
	static string restrictions[7];
	LicenseRestrictions()
	{
		number = (Restrictions)0;
		restriction = "";
		
	};
	LicenseRestrictions(Restrictions n, string r)
	{
		number = n;
		restriction = r;
	};



	void setValues(Restrictions  n, string r) { number = n; restriction = r; };
	Restrictions getNumber() { return number; };
	string getRestriction() { return restriction; };
	void outputData();

};