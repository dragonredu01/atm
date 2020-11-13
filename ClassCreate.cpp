#define _CRT_SECURE_NO_WARNINGS
#include <iostream> 
#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<dos.h>
#include<windows.h>
#include<iomanip>
#include<fstream>
#include<string.h>
#include<math.h>
#include<time.h>
#include <cstdlib>
#include "ClassCreate.h"
#include "Menu.h"

using namespace std;

COORD coord = { 0, 0 };
FILE* ff, * fs, * fp, * fg;

void Date::date_times()
{
	SYSTEMTIME t;		//pre defined in time.h header
	GetLocalTime(&t);
	aday = t.wDay, amonth = t.wMonth, ayear = t.wYear, ahour = t.wHour, amin = t.wMinute, asec = t.wSecond;

}

void goToXY(int x, int y)	//defining/initializing to predefined objects
{
	coord.X = x;
	coord.Y = y; // X and Y coordinates
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

void Machine::create_account()		//create account on selecting the option on main menu
{
	Machine a;
	system("cls");
	goToXY(34, 2);
	cout << "APPLICATION FORM";
	goToXY(10, 5);
	cout << "Enter Full Name : ";
	cin >> a.fname >> a.sname;
	goToXY(10, 7);
	cout << "Father/Guardian : ";
	cin >> a.p_name;
	goToXY(10, 9);
	cout << "Date Of Birth (dd/mm/yyyy) : ";
	cin >> a.dob;
	goToXY(10, 11);
	cout << "Account Type (S/C): ";
	cin >> a.type;
	goToXY(10, 13);
	cout << "City : ";
	cin >> a.city;
	goToXY(10, 15);
	cout << "Email Id : ";
	cin >> a.email;
	goToXY(10, 17);
	cout << "Enter initial amount( >= 50.000) ";
	cin >> a.amt;

	strcpy(a.pin, "1234");
	fs = fopen("TheTu.txt", "rb+");
	//initially there must be a valid user who have created account already
	//so that on using his account information, card details are given for next 
	//for initail account there must be a file with his deatails 

	Machine b;
	while (fscanf(fs, "%s%s\n", b.acno, b.pin) != EOF);
	strcpy(a.acno, b.acno);
	if (a.acno[5] != '9')
		a.acno[5] = a.acno[5] + 1;
	else
	{
		if (a.acno[4] != '9')	//incrementing the account number..actualyy thought of creating a random one but involves some complexity 
		{					//but you can try it
			a.acno[4] = a.acno[4] + 1;
			a.acno[5] = '0';
		}
	}
	fprintf(fs, "%s\n%s\n", a.acno, a.pin);
	fclose(fs);

	//inital account details posting to atm_users file

	ff = fopen("atm_users.txt", "a");
	fprintf(ff, "%s %s %s %s %s %c %s %d %s %d \n", a.acno, a.fname, a.sname, a.p_name, a.dob, a.type, a.city, a.pcode, a.email, a.amt);
	fclose(ff);
	//initialize amount,time & date of account opened and APPENDING to transactions file	
	a.adl = a.amt;	//adl = additional amount either deposit/credit
	a.prev = 0;		//prev = available balance before transaction
	Date d;
	d.date_times();
	a.day = d.aday; a.month = d.amonth; a.year = d.ayear;
	a.hour = d.ahour; a.min = d.amin; a.sec = d.asec;
	//to transactions file
	fp = fopen("transactions.txt", "a");
	fprintf(fp, "%s %s %d %d %d %d %d %d %d %d %d \n", a.acno, a.fname, a.prev, a.adl, a.amt, a.day, a.month, a.year, a.hour, a.min, a.sec);
	fclose(fp);

	goToXY(35, 19);
	cout << " SUBMIT";
	char c;
	c = _getch();
	goToXY(10, 23);
	cout << "Loading";
	Sleep(400);
	cout << ".";
	Sleep(400);
	cout << ".";
	Sleep(400);
	cout << ".";
	Sleep(400);

	system("cls");
	system("COLOR B0");
	goToXY(22, 5);
	cout << "YOUR ACCOUNT HAS SUCCESSFULLY CREATED ";
	goToXY(29, 8);		//giving account deatails on that particular user 
	cout << "ACCOUNT NUMBER  : " << a.acno;
	goToXY(29, 12);
	cout << "ATM PIN	      : " << a.pin;
	goToXY(8, 19);
	cout << "NOTE : THESE ARE THE ACCOUNT CREDENTIALS FOR USING ATM SERVICES.";
	goToXY(28, 23);
	cout << "MAIN MENU : PRESS ENTER";
	char op;
	op = _getch();
	Bank bank;
	system("cls");
	bank.create();
}

void Machine::show_data()
{
	Machine a;
	system("cls");
	cout << " : ACCOUNT DETAILS : ";
	cout << "\n\nAccount Number: " << a.acno << endl;
	cout << "-------------------------" << endl;
	cout << "\nFirst Name: " << a.fname << endl;
	cout << "-------------------------" << endl;
	cout << "\nLast Name: " << a.sname << endl;
	cout << "-------------------------" << endl;
	cout << "\Parent Name: " << a.p_name << endl;
	cout << "-------------------------" << endl;
	cout << "\Birthday: " << a.dob << endl;
	cout << "-------------------------" << endl;
	cout << "\Type: " << a.type << endl;
	cout << "-------------------------" << endl;
	cout << "\City: " << a.city << endl;
	cout << "-------------------------" << endl;
	cout << "\PassCode: " << a.pcode << endl;
	cout << "-------------------------" << endl;
	cout << "\Email: " << a.email << endl;
	cout << "-------------------------" << endl;
	cout << "\nCurrent Balance: Rs.  " << a.amt << endl;
	cout << "-------------------------------" << endl;
	system("PAUSE");
}

void Machine::read_rec() {
	system("cls");
	ifstream infile;
	infile.open("atm_users.txt", ios::binary);
	if (!infile)
	{
		cout << "Error in Opening! File Not Found!!" << endl;
		return;
	}
	cout << "\n****Data from file****" << endl;
	while (!infile.eof())
	{
		show_data();
	}
	infile.close();
	system("PAUSE");
}