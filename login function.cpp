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

