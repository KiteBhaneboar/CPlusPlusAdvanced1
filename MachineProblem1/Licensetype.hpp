#pragma once
#include <iostream>
#include <string>

using namespace std;

enum License
{
	NoType,
	Motorcycle,
	Construction,
	Agricultural,
	Private,
	Commercial,
	Minibus,
	Bus,
	Trailer,
	EquippedDisabled
};



class LicenseType
{
	License type;
	string description;

public:
	static string descriptions[9];
	LicenseType(License t = License::NoType, string d = "")
	{
		type = t;
		description = d;
	};

	void setValues(License t, string d) { type = t; description = d; };
	License getType() { return type; };
	string getDescription() { return description; };
	void outputData();

};

