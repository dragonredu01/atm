/* 
	Trong class này mục đích khai báo cho admin và user, các hình thức cơ bản để thực hiện nhập vào cho admin và user cũng như là tạo ra danh sách admin và user
	về thực hiện các chức năng sẽ nằm trong ClassFeature.h & ClassFeature.cpp
*/

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>
#include <windows.h>
#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <ctime>
#include <conio.h>
#include "ClassUA.h"
#include "Menu.h"
#include "ClassFeature.h"
#include "ClassCreate.h"

using namespace std;

/*******************************************************************
*
*	CLASS ADMIN
*
*******************************************************************/

string Admin::getUser() {
	return _sUser;
}

string Admin::getPass() {
	return _sPass;
}

void Admin::setUser(string user) {
	this->_sUser = user;
}

void Admin::setPass(string pass) {
	this->_sPass = pass;
}

bool Admin::compare(vector<Admin> List) {
	for (int i = 0; i < List.size(); i++)
		if (List[i].getUser() == _sUser && List[i].getPass() == _sPass) return true;
	return false;
}

/*******************************************************************
*
*	CLASS USER
*
*******************************************************************/

string User::getID() {
	return _sID;
}

string User::getPIN() {
	return _sPIN;
}

void User::setID(string ID) {
	this->_sID = ID;
}

void User::setPIN(string PIN) {
	this->_sPIN = PIN;
}

void User::lock() {
	status = true;
}

void User::unlock() {
	status = 0;
}

bool User::compare(vector<User>arrUser) {
	for (int i = 0; i < arrUser.size(); i++)
		if (arrUser[i].getID() == _sID && arrUser[i].getPIN() == _sPIN && status == false) return true;
	return false;
}

/*******************************************************************
*
*	CLASS LISTUSER & LISTADMIN
*
*******************************************************************/

void ListAdmin::readFile() {
	Admin admin;
	bool isUser = true;
	ifstream  file;
	file.open("Admin.txt");
	while (!file.eof()) {
		string temp;
		if (isUser) {
			getline(file, temp);
			admin.setUser(temp);
		}
		else {
			getline(file, temp);
			admin.setPass(temp);
			_vArrAdmin.push_back(admin);
		}
		isUser = !isUser;
	}
	file.close();
}

vector<Admin> ListAdmin::getListAdmin() {
	return _vArrAdmin;
}


void ListUser::readFile() {
	User user;
	bool isID = true;
	ifstream  file;
	file.open("TheTu.txt");
	while (!file.eof()) {
		string temp;
		if (isID) {
			getline(file, temp);
			user.setID(temp);
		}
		else {
			getline(file, temp);
			user.setPIN(temp);
			_vArrUser.push_back(user);
		}
		isID = !isID;
	}
	file.close();
}

void ListUser::writeFile() {
	ofstream file;
	file.open("TheTu.txt");
	for (int i = 0; i < _vArrUser.size(); i++) {
		file << _vArrUser[i].getID() << endl << _vArrUser[i].getPIN();
		if (i < _vArrUser.size() - 1) file << endl;
	}
	file.close();
}

void ListUser::lockUser(string ID) {
	for (int i = 0; i < _vArrUser.size(); i++) {
		if (_vArrUser[i].getID() == ID) _vArrUser[i].lock();
	}
}

void ListUser::unlockUser(string ID) {
	for (int i = 0; i < _vArrUser.size(); i++) {
		if (_vArrUser[i].getID() == ID) _vArrUser[i].unlock();
	}
}

void ListUser::deleteUser(string ID) {
	int count;
	for (int i = 0; i < _vArrUser.size(); i++)
		if (ID == _vArrUser[i].getID()) count = i;
	_vArrUser.erase(_vArrUser.begin() + count);
}

void ListUser::addUser(User user) {
	_vArrUser.push_back(user);
}

bool ListUser::search(string ID) {
	for (int i = 0; i < _vArrUser.size(); i++)
		if (_vArrUser[i].getID() == ID) return true;
	return false;
}

void ListUser::changePIN(string ID, string PIN) {
	for (int i = 0; i < _vArrUser.size(); i++) {
		if (_vArrUser[i].getID() == ID) _vArrUser[i].setPIN(PIN);
	}
}

bool ListUser::checkPIN(string ID, string PIN) {
	for (int i = 0; i < _vArrUser.size(); i++)
		if (_vArrUser[i].getID() == ID && _vArrUser[i].getPIN() == PIN) return true;
	return false;
}

void ListUser::viewListUser() {
	for (int i = 0; i < _vArrUser.size(); i++) {
		cout << "	ID: " << _vArrUser[i].getID() << endl;
		cout << "	PIN: " << _vArrUser[i].getPIN() << endl;
	}
}

vector<User> ListUser::getListUser() {
	return _vArrUser;
}
