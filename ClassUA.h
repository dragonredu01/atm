#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <string>
#include <vector>

using namespace std;

/*******************************************************************
*
*	CLASS USER & ADMIN
*
*******************************************************************/

class Admin {

private:

	string _sUser;
	string _sPass;

public:

	string getUser(); //lấy tên admin
	string getPass(); //lấy mật khẩu

	void setUser(string user); //hàm để gán user từ biến
	void setPass(string pass); //hàm để gán mật khẩu từ biến

	bool compare(vector<Admin> List); //tạo 1 hàm để so sánh

};

class User {

private:

	string _sID;
	string _sPIN;
	bool status = false; //mở là 0, khóa là 1

public:

	string getID(); //lấy tên người dùng
	string getPIN(); //lấy mật khẩu

	void setID(string ID); //hàm để gán người dùng từ biến
	void setPIN(string PIN); //hàm gán mật khẩu từ biến
	//chỉ dành cho người dùng nếu nhập sai quá số lần quy định sẽ khóa
	void lock(); //hàm khóa tài khoản
	void unlock(); //hàm mở tài khoản

	bool compare(vector<User>arrUser); //tạo 1 hàm để so sánh và lấy đúng người dùng
};

/*******************************************************************
*
*	CLASS LISTUSER & LISTADMIN
*
*******************************************************************/

class ListAdmin {

private:

	vector<Admin>_vArrAdmin;

public:

	void readFile(); //đọc dữ liệu từ file admin

	vector<Admin> getListAdmin(); //gán danh sách admin vô vector
};

class ListUser {

private:

	vector<User>_vArrUser;

public:

	void readFile(); //hàm đọc file user
	void writeFile(); //in ra file thetu
	void lockUser(string ID); //hàm khóa user
	void unlockUser(string ID); //mở khóa user
	void deleteUser(string ID); //xóa user
	void addUser(User user); //thêm user
	bool search(string ID); //tìm kiếm
	void changePIN(string ID, string PIN); //thay đổi mật khẩu
	bool checkPIN(string ID, string PIN); //kiểm tra mật khẩu
	void viewListUser(); //xem danh sách user

	vector<User> getListUser(); //gán danh sách user vô vector
};

