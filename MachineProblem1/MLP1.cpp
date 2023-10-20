#include <iostream>
#include <string>
#include <sstream>
#include <format>

using namespace std;

// Name.hpp

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

// Name.cpp

void Name::outputData()
{
	cout << first << " " << father << " " << family << endl;
}

// Date.hpp

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

// Date.cpp

void Date::outputData()
{
	cout << day << "/" << month << "/" << year << endl;

}

// LicenseType.hpp

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

// LicenseType.cpp

string LicenseType::descriptions[9] = { "All types of motorcycles", "Construction vehicle", "Agricultural vehicle", "Private passenger vehicle" , "Commercial passenger vehicle", "Minibus", "Buses", "Trailer and semi-trailer", "Vehicle eqiupped for disabled" };


void LicenseType::outputData()
{
	cout << type << " -- " << description << "\n";
};


// LicenseRestrictions.hpp

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

// LicenseRestrictions.cpp

string LicenseRestrictions::restrictions[7] = { "None", "Glasses", "Earphones", "Automatic", "Disabled", "Lenses", "Deaf" };

void LicenseRestrictions::outputData()
{
	cout << number << " -- " << restriction << "\n";
};

// DrivingLicense.hpp

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

streambuf* originalReadBuffer;

void redirectStdout(stringstream& ss) {  //captures cout into a variable
	ss.str(string());
	originalReadBuffer = cout.rdbuf();
	cout.rdbuf(ss.rdbuf());
}

void undirectStdout(stringstream& ss) { //resets cout back to it's orginal stream buffer
	cout.rdbuf(originalReadBuffer);
}

int main() 
{
	Name name{ "Bartholomew", "Barty", "Barton" }; //test name

	if (name.getFamily() == "Barton") cout << "Family Name : " << name.getFamily() << endl;
	if (name.getFather() == "Barty") cout << "Father name: " << name.getFather() << endl;
	if (name.getFirst() == "Bartholomew") cout << "Name: " << name.getFirst() << endl;

	stringstream ss;

	redirectStdout(ss);
	name.outputData();
	undirectStdout(ss);

	string output = ss.str();
	if (output == "Bartholomew Barty Barton\n") cout << "Name output correct. " << output << endl;
	name.setValues("Martholomew", "Marty", "Marton");

	redirectStdout(ss);
	name.outputData();
	undirectStdout(ss);

	output = ss.str();
	if (output == "Martholomew Marty Marton\n") cout << "Name setValues correct. " << output << endl;

	Date date{ 20, 10, 1403 }; //test date

	if (date.getDay() == 20) cout << "Day: " << date.getDay() << endl;
	if (date.getMonth() == 10) cout << "Month: " << (date.getMonth()) << endl;
	if (date.getYear() == 1403) cout << "Year: " << date.getYear() << endl;


	redirectStdout(ss);
	date.outputData();
	undirectStdout(ss);

	output = ss.str();
	
	if (output == format("{}/{}/{}\n", date.getDay(), date.getMonth(), date.getYear())) cout << "Date output correct. " << format("{}/{}/{}\n", date.getDay(), date.getMonth(), date.getYear()) << endl;
	date.SetValues(30, 12, 1529);

	redirectStdout(ss);
	date.outputData();
	undirectStdout(ss);

	output = ss.str();
	if (output == format("{}/{}/{}\n", date.getDay(), date.getMonth(), date.getYear())) cout << "Date setvalues correct. " << format("{}/{}/{}\n", date.getDay(), date.getMonth(), date.getYear()) << endl;
	
	LicenseType type{License::Agricultural, LicenseType::descriptions[2]}; //test license type

	if (type.getType() == License::Agricultural) cout << "License Type: " << type.getType() << endl;
	if (type.getDescription() == LicenseType::descriptions[2]) cout << "License Description: " << type.getDescription() << endl;


	redirectStdout(ss);
	type.outputData();
	undirectStdout(ss);

	output = ss.str();

	if (output == format("{} -- {}\n", (int)type.getType(), type.getDescription()))  cout << "License Type output correct. " << output << endl;
	type.setValues(License::Bus, LicenseType::descriptions[6]);

	redirectStdout(ss);
	type.outputData();
	undirectStdout(ss);

	output = ss.str();
	if (output == format("{} -- {}\n", (int)type.getType(), type.getDescription())) cout << "License Type setvalues correct. " << output << endl;

	LicenseRestrictions restriction{ Restrictions::Glasses, LicenseRestrictions::restrictions[1] }; //test license restriction

	if (restriction.getNumber() == Restrictions::Glasses) cout << "Restriction Type correct. " << restriction.getNumber() << endl;
	if (restriction.getRestriction() == LicenseRestrictions::restrictions[1]) cout << "Restriction Description correct. " << restriction.getRestriction() << endl;


	redirectStdout(ss);
	restriction.outputData();
	undirectStdout(ss);

	output = ss.str();

	if (output == format("{} -- {}\n", (int)restriction.getNumber(), restriction.getRestriction()))  cout << "Restriction Type output correct. " << output << endl;
	restriction.setValues(Restrictions::Automatic, LicenseRestrictions::restrictions[3]);

	redirectStdout(ss);
	restriction.outputData();
	undirectStdout(ss);

	output = ss.str();
	if (output == format("{} -- {}\n", (int)restriction.getNumber(), restriction.getRestriction())) cout << "Restriction Type setvalues correct. " << output << endl;
}
