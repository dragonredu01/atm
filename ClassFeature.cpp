/*
	đây là class feature, trong này sẽ thực hiện toàn bộ chức năng của user và admin
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
#include "ClassUA.h"
#include "ClassFeature.h"
#include "Menu.h"
#include "ClassCreate.h"

using namespace std;

/*******************************************************************
*
*	CLASS INFOUSER
*
*******************************************************************/

void InfoUser::setID(string ID) {
	this->_sID = ID;
}

void InfoUser::setName(string name) {
	this->_sName = name;
}

void InfoUser::setTypeCurrency(string typeCurrency) {
	this->_sTypeCurrency = typeCurrency;
}

void InfoUser::setSurplus(string surplus) {
	this->_sSurplus = surplus;
}

void InfoUser::setParent(string parent) {
	this->_sParent = parent;
}

void InfoUser::setBirth(string birthday) {
	this->_sBirth = birthday;
}

void InfoUser::setType(string type) {
	this->_sType = type;
}

void InfoUser::setPNum(string pNum) {
	this->_sPNum = pNum;
}

void InfoUser::setMail(string mail) {
	this->_sMail = mail;
}

string InfoUser::getID() {
	return _sID;
}

string InfoUser::getName() {
	return _sName;
}

string InfoUser::getSurplus() {
	return _sSurplus;
}

string InfoUser::getParent() {
	return _sParent;
}

string InfoUser::getBirth() {
	return _sBirth;
}

string InfoUser::getType() {
	return _sType;
}

string InfoUser::getPlace() {
	return _sPlace;
}

string InfoUser::getPNum() {
	return _sPNum;
}

string InfoUser::getMail() {
	return _sMail;
}

string InfoUser::getTypeCurrency() {
	return _sTypeCurrency;
}

/*******************************************************************
*
*	CLASS LISTINFOUSER
*
*******************************************************************/

void ListInfoUser::readFile(ListUser arrUser) {
	for (int i = 0; i < arrUser.getListUser().size(); i++) {
		InfoUser infoUser;
		int count = 1;
		string temp, path;
		path = (arrUser.getListUser())[i].getID() + ".txt";
		ifstream  file;
		file.open(path);

		while (!file.eof()) {
			if (count == 1) {
				getline(file, temp);
				infoUser.setID(temp);
			}

			if (count == 2) {
				getline(file, temp);
				infoUser.setName(temp);
			}

			if (count == 3) {
				getline(file, temp);
				infoUser.setSurplus(temp);
			}


			if (count == 4) {
				getline(file, temp);
				infoUser.setTypeCurrency(temp);
				_vArrInfoUser.push_back(infoUser);
				count = 0;
			}
			count++;
		}
		file.close();

	}
}

void ListInfoUser::writeFile() {
	ofstream file;
	for (int i = 0; i < _vArrInfoUser.size(); i++) {
		file.open(_vArrInfoUser[i].getID() + ".txt");
		file << _vArrInfoUser[i].getID() << endl << _vArrInfoUser[i].getName() << endl << _vArrInfoUser[i].getSurplus() << endl << _vArrInfoUser[i].getTypeCurrency();
		if (i < _vArrInfoUser.size() - 1) file << endl;
	}
	file.close();
}

void ListInfoUser::writeFile2(string ID) {
	for (int i = 0; i < _vArrInfoUser.size(); i++) {
		if (ID == _vArrInfoUser[i].getID()) {
			ofstream file;
			file.open(ID + ".txt");
			file << _vArrInfoUser[i].getID() << endl << _vArrInfoUser[i].getName() << endl << _vArrInfoUser[i].getSurplus() << endl << _vArrInfoUser[i].getTypeCurrency();
			if (i < _vArrInfoUser.size() - 1) file << endl;
			file.close();
			break;
		}
	}
}

void ListInfoUser::takeMoney(string ID, string& s) {
	for (int i = 0; i < _vArrInfoUser.size(); i++) {
		if (_vArrInfoUser[i].getID() == ID) {
			while (true) {
				cout << "Enter balance to withdraw: ";
				cin >> s;
				if (stoi(_vArrInfoUser[i].getSurplus()) - stoi(s) >= stoi(s) && stoi(_vArrInfoUser[i].getSurplus()) >= 50000) {
					cout << "Withdraw successfully!" << endl << endl;
					_vArrInfoUser[i].setSurplus(to_string(stoi(_vArrInfoUser[i].getSurplus()) - stoi(s)));
					break;
				}
				else cout << "Fail to withdraw!" << endl;
			}
		}
	}
}

void ListInfoUser::viewInfoUser(string ID) {
	for (int i = 0; i < _vArrInfoUser.size(); i++) {
		if (ID == _vArrInfoUser[i].getID()) {
			cout << "	Id: " << _vArrInfoUser[i].getID() << endl;
			cout << "	Username: " << _vArrInfoUser[i].getName() << endl;
			cout << "	Balance: " << _vArrInfoUser[i].getSurplus() << endl;
			cout << "	Type: " << _vArrInfoUser[i].getTypeCurrency() << endl << endl << endl;
			break;
		}
	}
}

bool ListInfoUser::check(string ID) {
	for (int i = 0; i < _vArrInfoUser.size(); i++)
		if (_vArrInfoUser[i].getID() == ID) return true;
	return false;
}

void ListInfoUser::transferMoney(string ID, string s, string ID2) {
	int t = 0;
	for (int i = 0; i < _vArrInfoUser.size(); i++) {
		if (_vArrInfoUser[i].getID() == ID) {
			if (stoi(_vArrInfoUser[i].getSurplus()) - stoi(s) >= stoi(s) && stoi(_vArrInfoUser[i].getSurplus()) >= 50000) {
				_vArrInfoUser[i].setSurplus(to_string(stoi(_vArrInfoUser[i].getSurplus()) - stoi(s)));
			}
			else t = 1;
		}
	}
	if (t == 0) {
		for (int i = 0; i < _vArrInfoUser.size(); i++) {
			if (_vArrInfoUser[i].getID() == ID2) {
				_vArrInfoUser[i].setSurplus(to_string(stoi(_vArrInfoUser[i].getSurplus()) + stoi(s)));
			}
		}
	}
}

bool ListInfoUser::checkMoney(string ID, string s) {
	for (int i = 0; i < _vArrInfoUser.size(); i++) {
		if (_vArrInfoUser[i].getID() == ID) {
			if (stoi(_vArrInfoUser[i].getSurplus()) - stoi(s) >= stoi(s) && stoi(_vArrInfoUser[i].getSurplus()) >= 50000) return true;
		}
	}
	return false;
}

InfoUser ListInfoUser::getInfoUser(string ID) {
	for (int i = 0; i < _vArrInfoUser.size(); i++) {
		if (_vArrInfoUser[i].getID() == ID) return _vArrInfoUser[i];
	}
}

/*******************************************************************
*
*	CLASS HISTORY
*
*******************************************************************/

string History::getID() {
	return _sID;
}

string History::getTime() {
	return _sTime;
}

string History::getTypeTransfer() {
	return  _sTypeTransfer;
}

string History::getMoneyTransfer() {
	return _sMoneyTransfer;
}

void History::setID(string ID) {
	this->_sID = ID;
}

void History::setTypeTransfer(string typeTransfer) {
	this->_sTypeTransfer = typeTransfer;
}

void History::setMoneyTransfer(string moneyTransfer) {
	this->_sMoneyTransfer = moneyTransfer;
}

void History::setTime(string time) {
	this->_sTime = time;
}

void History::viewHistory() {
	cout << "	ID: " << _sID << endl;
	cout << "	Trading Type: " << _sTypeTransfer << endl;
	cout << "	Trading Money: " << _sMoneyTransfer << endl;
	cout << "	Time: " << time << endl << endl;
}

/*******************************************************************
*
*	CLASS LISTHISTORY
*
*******************************************************************/

void ListHistory::readFile(ListUser arrUser) {
	for (int i = 0; i < arrUser.getListUser().size(); i++) {
		History history;
		int count = 1;
		string temp, path;
		path = "LichSu" + (arrUser.getListUser())[i].getID() + ".txt";
		ifstream  file;
		file.open(path);
		while (!file.eof()) {
			if (count == 1) {
				getline(file, temp);
				history.setID(temp);
			}

			if (count == 2) {
				getline(file, temp);
				history.setTypeTransfer(temp);
			}
			if (count == 3) {
				getline(file, temp);
				history.setMoneyTransfer(temp);
			}
			if (count == 4) {
				getline(file, temp);
				history.setTime(temp);
				_vArrHistory.push_back(history);
				count = 0;
			}
			count++;
		}
		file.close();
	}
}

void ListHistory::writeFile(string ID) {
	string path = "LichSu" + ID + ".txt";
	ofstream file;
	file.open(path);
	for (int i = 0; i < _vArrHistory.size(); i++) {
		if (_vArrHistory[i].getID() == ID) {
			file << _vArrHistory[i].getID() << endl << _vArrHistory[i].getTypeTransfer() << endl << _vArrHistory[i].getMoneyTransfer() << endl << _vArrHistory[i].getTime();
			if (i < _vArrHistory.size() - 1) file << endl;
		}
	}
	file.close();
}

void ListHistory::writeFile2(string ID, string h) {
	string path = "LichSu" + ID + ".txt";
	ofstream file;
	file.open(path);
	for (int i = 0; i < _vArrHistory.size(); i++) {
		if (_vArrHistory[i].getID() == h || _vArrHistory[i].getID() == ID) {
			file << _vArrHistory[i].getID() << endl << _vArrHistory[i].getTypeTransfer() << endl << _vArrHistory[i].getMoneyTransfer() << endl << _vArrHistory[i].getTime();
			if (i < _vArrHistory.size() - 1) file << endl;

		}
	}
	file.close();
}

void ListHistory::add(History history) {
	_vArrHistory.push_back(history);
}

void ListHistory::showHistory(string ID) {
	for (int i = 0; i < _vArrHistory.size(); i++) {
		if (_vArrHistory[i].getID() == ID) _vArrHistory[i].viewHistory();
	}
}