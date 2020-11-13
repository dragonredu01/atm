#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <string>
#include <vector>

using namespace std;

/*******************************************************************
*	USER
*		@CLASS INFOUSER: hiển thị thông tin của user
*			đây là 1 chức năng nên nằm trong feature
*		@CLASS LISTINFOUSER: hiển thị danh sách thông tin user
*			đây là 1 chức năng nên nằm trong feature
*		@CLASS HISTORY: hiển thị lịch sử giao dịch của user
*		@CLASS LISTHISTORY: hiển thị danh sách lịch sử giao dịch
*
*******************************************************************/

class InfoUser {

private:

	string _sID, _sName, _sSurplus, _sParent, _sBirth, _sType, _sPlace, _sPNum, _sMail, _sTypeCurrency;

public:

	void setID(string ID);
	void setName(string name);
	void setTypeCurrency(string typeCurrency);
	void setSurplus(string surplus);
	void setParent(string parent);
	void setBirth(string birthday);
	void setType(string type);
	void setPlace(string place);
	void setPNum(string pNum);
	void setMail(string mail);

	string getID();
	string getName();
	string getSurplus();
	string getParent();
	string getBirth();
	string getType();
	string getPlace();
	string getPNum();
	string getMail();
	string getTypeCurrency();
};

class ListInfoUser {

private:

	vector<InfoUser> _vArrInfoUser;

public:

	void readFile(ListUser arrUser);
	void writeFile();
	void writeFile2(string ID);
	void takeMoney(string ID, string& s);
	void viewInfoUser(string ID);
	bool check(string ID);
	void transferMoney(string ID, string s, string ID2);
	bool checkMoney(string ID, string s);

	InfoUser getInfoUser(string ID);
};

class History {

private:

	string _sID;
	string _sTypeTransfer;
	string _sMoneyTransfer;
	string _sTime;

public:

	string getID();
	string getTime();
	string getTypeTransfer();
	string getMoneyTransfer();

	void setID(string ID);
	void setTypeTransfer(string typeTransfer);
	void setMoneyTransfer(string moneyTransfer);
	void setTime(string time);
	void viewHistory();
};

class ListHistory {

private:

	vector<History> _vArrHistory;

public:

	void readFile(ListUser arrUser);
	void writeFile(string ID);
	void writeFile2(string ID, string h);
	void add(History history);
	void showHistory(string ID);

};

