#include <iostream>
#include <string>
#include <cstring>
#include <algorithm>
#include <conio.h>
#include <regex>
#include <map>
#include <fstream>
#include <istream>
#include <cstdio>





















 
using namespace std;

struct profile
{
	string fname, lname, email, gender, password, number;
};

profile user;

string pass1, pass2;

void f_inst();
void f_again();
bool f_compare(string, string);
int f8(string pass);
string pass_input();
void personal_info_input();
int login();
void Register();
int check(char arr1[], char arr2[]);
void encrypt(string& password);
//int n_lines();
//void load_files_to_system();
//void save_to_map();
//void save_to_userfile();
void update_file(string new_, int line);






int main(){
	/*string pss = "!@#$%^&*()";
	encrypt(pss);
	cout << pss << endl;*/
	int x;
	//char h1[15], h2[15];
	string choice, new_ , pass4;
	while(true) {
		cout << "Enter '1' for Reister OR '2' for Login OR '3' for Change Password OR '4' for Exit => ";
		cin >> choice;
		if (choice == "1")
		{
			Register();
			break;
		}
		else if (choice == "2") {
			if (login() == true)
			{break;}	
		}
		else if (choice == "3") {
			x = login();
			if (x != 0) {
				new_ = pass_input();
				f_again();
				pass4 = pass_input();
				while (true) {
					int a = f_compare(new_, pass4);
					if (a != 0) {
						break;

					}
					else {
						cout << "password not matching the first ...!\n";
						pass2 = pass_input();
					}


				}
				encrypt(new_);
				update_file(new_, x);
				/*string y = "NData.txt";
				#pragma warning(suppress : 4996);
				std::strcpy(h1, y.c_str());
				string y = "Data.txt";
				#pragma warning(suppress : 4996);
				std::strcpy(h2, y.c_str());*/
				remove("Data.txt");
				if (rename("NData.txt", "Data.txt") == 0) {
					cout << "password has changed successfully..(^_^)\n";
				}
				else {
					cout << "there is a problem .. call the programmer to fix..!";
				}
				

			}
			else { continue; }
		}
		else if (choice == "4") {
			break;
		}
		else {
			cout << "not defined choice...!\n"; 
		}


	}

}








void update_file(string new_ , int line){
	fstream oldfile;
	fstream newfile;
	char dodo[120];
	int count = 1;
	oldfile.open("Data.txt", ios::in);
	newfile.open("NData.txt", ios::app);
	while (!oldfile.eof()) {
		if (count == line) {
			oldfile >> dodo;
			newfile << dodo << " ";
			newfile << new_ << "~";
			oldfile.getline(dodo, 100, '~');
			oldfile.getline(dodo,100,'\n');
			newfile << dodo << "\n";
		}
		
		else{
			oldfile.getline(dodo, 119, '\n');
			newfile << dodo << "\n";
		}
		
		

		count++;


	}





}

















void f_inst() {
	cout << "password conditions: " << endl;
	cout << "1- should be at least 8 character" << endl;
	cout << "2- include upper and lower case alphaptic" << endl;
	cout << "3- include at least one number" << endl;
	cout << "4-not contain sequential like (123) or (ABC) " << endl;
	cout << "5-include at least one sympol" << endl;
	cout << "6-not contain your personal information(id,name,mobilnumber,)" << endl;
}


void f_again() {
	cout << "enter the password again to confirm\n";
}



bool f_compare(string pass1, string pass2) {
	if (pass1 == pass2) {
		return true;
	}
	else { return false; }

}

int f8(string pass) {

	/*	func return   how it work?..


		retrun 1 if little than 8 char  or greatear than 30
		return 2 if not include upper or lower case
		return 3 if there is no number
		return 4 if include 3 sequntial numbers or letter "abc" or "123"
		return 5 if not include sympol

			  ++ if there is value from 1 to 5 you should print rules of strong pass on f6 function ++
						-- if there is zero returned >> continue password is strong enough --
		*/



	int up = 0;
	int low = 0;


	if (pass.length() < 8 || pass.length() > 30) {
		return 1;
	}

	for (int i = 0; i < pass.length(); i++) {
		if (isupper(pass[i])) {
			++up;

		}
		else if (islower(pass[i])) {
			++low;
		}
		if (up > 0 && low > 0) {
			break;
		}

	}
	if (up <= 0 || low <= 0) {
		return 2;
	}


	low = 0;
	for (int i = 0; i < pass.length(); i++)
	{
		if (isdigit(pass[i])) {
			break;
		}
		else if (!isdigit(pass[i])) {
			++low;
		}
	}
	if (low == pass.length())
	{
		return 3;
	}




	for (size_t i = 0; i < pass.length() - 2; i++)
	{
		if ((int)pass[i] == (int)pass[i + 1] - 1 && (int)pass[i + 1] - 1 == (int)pass[i + 2] - 2) {
			return 4;
			break;
		}
	}

	up = 0;
	for (size_t i = 0; i < pass.length(); i++)
	{
		if (!isalnum(pass[i])) {
			break;
		}
		else if (isalnum(pass[i])) {
			++up;
		}


	}
	if (up == pass.length()) { return 5; }




	return 0;

}




string pass_input() {

	char pass[30] = "";
	char ch;
	const char* theval;
	cout << "Enter  your new password: ";
	ch = _getch();
	while (ch != 13) {//character 13 is enter
		string sym(1, ch);
		theval = sym.c_str();
#pragma warning(suppress : 4996)  
		strcat(pass, theval);
		//pass.push_back(ch);
		cout << '*';
		ch = _getch();
	}
	cout << endl;
	//cout << pass;

	//user.password = pass;
	return pass;
}



void personal_info_input() {
	while (true) {
		cout << "enter your first name: ";
		cin >> user.fname;
		cout << "enter your surname: ";
		cin >> user.lname;
		regex match_name("[A-Za-z\\–]+");
		if ((regex_match(user.fname, match_name)) && (regex_match(user.lname, match_name)))
		{
			break;
		}
		else
		{
			cout << "please enter name without digits or other special characters" << endl;
		}

	}
	while (true)
	{
		cout << "enter yoru email: ";
		cin >> user.email;
		//regex match_email("([A-Za-z0-9#!%$‘&+*–/=?^_`.{|}?~]+@([A-Za-z0-9])+(\\.)+[A-Za-z0-9]+)");
		regex match_email("([A-Za-z0-9#!%$‘&+*–/=?^_`.{|}?~]+@([A-Za-z0-9])+\\.([A-Za-z0-9])+)");
		if (regex_match(user.email, match_email))
		{
			break;
		}
		else
		{
			cout << "please enter a vaild email address" << endl;
		}
	}
	while (true)
	{
		cout << "enter your mobile number: ";
		cin >> user.number;
		regex match_num("(01)+([0-2]|5)+[0-9]+");
		if (regex_match(user.number, match_num))
		{
			int counter = 0;
			for (size_t i = 0; i < user.number.size(); i++)
			{
				counter++;
			}
			if (counter == 11)
			{
				break;
			}
			else
			{
				cout << "please enter a vaild mobile number" << endl;
			}
		}
		else
		{
			cout << "please enter a vaild mobile number" << endl;
		}
	}
	cout << "What's your gender: ";
	cin >> user.gender;


}


int n_lines() {
	int number_of_lines = 0;

	string line;
	ifstream myfile("users_file.txt");

	if (myfile.is_open()) {
		while (!myfile.eof()) {
			getline(myfile, line);
			number_of_lines++;
		}
		myfile.close();
	}

	return number_of_lines;
}



//void load_files_to_system() {
//	char ch ;
//	string word;
//	char user_name_password[100];
//	//word.clear(); // word = "";
//	fstream file;
//	file.open("Data.txt", ios::in);
//	while(!file.eof()) {
//		 
//		file.getline(user_name_password, 100, '~');
//		/*strcat(x, ' ')
//		strcat(x,y)*/
//		/*while (true) {
//
//			file.get(ch);
//			word += ch;
//			if (ch == ' ') { break; }
//
//		}
//		user.email = word;
//		word.clear();
//		while (true) {
//			file.get(ch);
//			word += ch;
//			if (ch == ' ') { break; }
//		}
//		user.number = word;
//		word.clear();
//		while (true) {
//			file.get(ch);
//			word += ch;
//			if (ch == ' ') { break; }
//
//		}
//		user.gender = word;
//		word.clear();
//		while (true) {
//			file.get(ch);
//			word += ch;
//			if (ch == ' ') { break; }
//
//		}*/
//		//save_to_map();
//		//data.insert({ user.fname , user });
//	}
//	file.close();
//	//cout << user.email;
//}

//void save_to_map() {
//	::data.insert({ user.fname , user });
//
//}

//void save_to_userfile() {
//
//	fstream file;
//	file.open("users_file.txt", ios::app);
//
//	file << ::data[user.fname].fname;
//	file << ::data[user.fname].lname;
//	file << ::data[user.fname].email;
//	file << ::data[user.fname].gender;
//	file << ::data[user.fname].number;
//	file << ::data[user.fname].password << endl;
//}



int login() {
	int count = 0;
	int nline = 0;
	fstream file;
	file.open("Data.txt", ios::in);
	while (count < 3) {
		char username[100], password[100]=" ";
		char username_password[100];
		char H[23];
		char K[100];
		// as the user can only try 3 times 
		cout << "Enter your username: "; cin >> username;
		#pragma warning(suppress : 4996);
		strcpy(H,username);
		//cout << "Enter your password: "; cin >> password;
		//password[] = pass_input();

		//char* cstr = new char[pass_input().length() + 1];
		string y = pass_input();
		encrypt(y);
#pragma warning(suppress : 4996);
		std::strcpy(password, y.c_str());
		nline = 0;
		while (!file.eof()) {
			//to read the whole data in the filec
			file.getline(username_password, 81, '~');
			++nline;
#pragma warning(suppress : 4996)
			strcat(username, " ");
#pragma warning(suppress : 4996)
			strcat(username, password);
#pragma warning(suppress : 4996)

			if ( check(username, username_password) )  {
				cout << "\nsuccessful login, welcome: " << H << endl;
				file >> H;
				cout << "your email is : " << H << endl;
				return nline;
				count = 500;
				break;
			}
			else {
#pragma warning(suppress : 4996);
				strcpy(username,H);
				//file.ignore();
				file.getline(K, 100, '\n');
				//char username_password[23];

				//cout << " Falied login. Try again\n";
			}
		}
		file.seekg(0, ios::beg);
		count++;
		if (count ==500) { break; }
		else if (count == 3) {
			cout << "\n" << "you spend your 3 trials....you are denied to access system...!" << "\n";
			return 0;
		}
		else {
			cout << "\n" << "Failed login ,Try again..." << "\n";
		}
	}
	// file.close();
}

int check(char arr1[], char arr2[]) {

	int a1 = strlen(arr1);
	int a2 = strlen(arr2);
	if (a1!= a2) {
		return 0;

	}
	else {
		for (int i = 0; i < a1; i++) {
			if (arr1[i] != arr2[i]) {
				return 0;
			}


		}


		return 1;
	}



}



void Register() {
		while (true)
		{
			personal_info_input();
			f_inst();
			pass1 = pass_input();
			while (true) {
				int a = f8(pass1);
				if (a == 1) {
					cout << "password is little than 8 char" << endl;
					pass1 = pass_input();

				}
				else if (a == 2) {
					cout << "password is not include upper or lower case" << endl;
					pass1 = pass_input();

				}
				else if (a == 3) {
					cout << "password is not include number" << endl;
					pass1 = pass_input();
				}
				else if (a == 4) {
					cout << "include 3 sequntial numbers or letter 'abc' or '123'  " << endl;
					pass1 = pass_input();
				}
				else if (a == 5) {
					cout << " not include sympol" << endl;
					pass1 = pass_input();
				}
				else {
					break;
				}
			}
			f_again();

			pass2 = pass_input();
			while (true) {
				int a = f_compare(pass1, pass2);
				if (a != 0) {
					break;

				}
				else {
					cout << "password not matching the first ...!";
					pass2 = pass_input();
				}


			}

			user.password =  pass1;
			encrypt(user.password);
			//data.insert({ user.fname , user });
			//save_to_userfile();
			fstream file;
			file.open("Data.txt", ios::app);

			file << user.fname << " ";
			file << user.password << "~";
			file << user.email << " ";
			file << user.gender << " ";
			file << user.number << " ";
			file << user.lname << " " << endl;
			file.close();
			cout << " => enter 1 to register new consumer or any key to exit: ";
			string x;
			cin >> x;
			if (x != "1") {
				break;
			}

		}
		//save_to_map();
		// data.insert({ user.fname , user });

		//load_files_to_system();








		cout << endl << "you registered successfully.. and added to user data base system in california \n  our company (moaaz & fathi ) corporation" << endl;


	}



void encrypt(string& password)
{
	int i;
	i = 0;
	while (password[i] != '\0') // to makesure it isnot a nul character(character with ACIII value=0)
	{ //to makesureit is an alphabet in lower or upper case not a number or mathmatical oppreation
		if (!((password[i] >= 0 && password[i] < 65) || (password[i] > 90 && password[i] < 97) || (password[i] > 122 && password[i] <= 127)))
		{
			// if character is in upper case (minus its ACIII value from 90+60 to get the reversed character )
			if (password[i] >= 'A' && password[i] <= 'Z')
				password[i] = ("%c", 'Z' + 'A' - password[i]); //using %c to display the character itself (if using ASCII)
			 // if character is in lower case (minus its ACIII value from 61+122 to get the reversed character)
			if (password[i] >= 'a' && password[i] <= 'z')// if lower

				password[i] = ("%c", 'z' + 'a' - password[i]);
		}
		// IF IT IS A numer in hexa or decimal or oppreation or sign  
		if (((password[i] >= 0 && password[i] < 65) || (password[i] > 90 && password[i] < 97) || (password[i] > 122 && password[i] <= 127)))
		{
			password[i] = ("%c", password[i]);   // print it without any change  
		}

		i++;
	}
	//printf("\n");
}
