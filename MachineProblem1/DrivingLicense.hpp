#pragma once
#include <string>

using namespace std;


class DrivingLicense
{
	string name;
	string nationality;
	int nationalNumber;
	string birthDate;
	string gender;
	string address;
	string bloodType;
	string licenseCenter;
	int licenseNumber;
	string issueDate;
	string expiryDate;
	int type;
	string restriction;
	static int HowManyLicenses;

	DrivingLicense()
	{
		name = "";
		nationality = "";
		nationalNumber = 0;
		birthDate = "";
		gender = "";
		address = "";
		bloodType = "";
		licenseCenter = "";
		licenseNumber = 0;
		issueDate = "";
		expiryDate = "";
		type = 0;
		restriction = "";
		HowManyLicenses++;
	};
	DrivingLicense(string n, string nt, int nn, string bd, string g, string a, string bt, string lc, int ln, string id, string ed, int t, string r)
	{
		name = n;
		nationality = nt;
		nationalNumber = nn;
		birthDate = bd;
		gender = g;
		address = a;
		bloodType = bt;
		licenseCenter = lc;
		licenseNumber = ln;
		issueDate = id;
		expiryDate = ed;
		type = t;
		restriction = r;
		HowManyLicenses++;
	};

	~DrivingLicense()
	{
		if (HowManyLicenses > 0) HowManyLicenses--;
	}

};