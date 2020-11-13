#pragma once

class Machine {		//class for entire program

private:
	int mbno, pcode, amt, prev;
	int adl;
	int day, month, year, hour, min, sec;
	char  fname[10], sname[10], p_name[20], city[15], email[20], dob[15], type;
	char acno[7], pin[5], temp;

public:

	void create_account();
	void show_data();
	void read_rec();
};

class Date {		//class current date and time of system 

public:
	int aday, amonth, ayear, ahour, amin, asec;
	void date_times();
};