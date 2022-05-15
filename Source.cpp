#include <iostream>
#include <fstream>
#include <string>
int menu();
void add_text();
void Display_file();
void Empty_file();
void Encrypt_file();
void Decrypt_file();
void Merge();
void num_word();
void num_char();
void num_line();
void search_word();
void search();
void upper();
void lower();
void first();
void save();
using namespace std;

int main()
{
	while (true)
	{
		switch (menu())
		{
		case 1:add_text();
			break;
		case 2:Display_file();
			break;
		case 3:Empty_file();
			break;
		case 4:Encrypt_file();
			break;
		case 5:Decrypt_file();
			break;
		case 6:Merge();
			break;
		case 7:num_word();
			break;
		case 8:num_char();
			break;
		case 9:num_line();
			break;
		case 10:search_word();
			break;
		case 11:search();
			break;
		case 12:upper();
			break;
		case 13:lower();
			break;
		case 14:first();
			break;
		case 15:save();
			break;
		default:cout << "plz enter correct number";
			break;
		}
		if (menu() == 16)
		{
			break;
		}
	}
}
int menu()
{
	int num;
	cout <<
		"1.Add new text to the end of the file \n"
		"2.Display the content of the file \n"
		"3.Empty the file \n"
		"4.Encrypt the file content \n"
		"5.Decrypt the file content \n"
		"6.Merge another file \n"
		"7.Count the number of words in the file. \n"
		"8.Count the number of characters in the file \n"
		"9.Count the number of lines in the file \n"
		"10.Search for a word in the file \n"
		"11.Count the number of times a word exists in the file \n"
		"12.Turn the file content to upper case. \n"
		"13.Turn the file content to lower case. \n"
		"14.Turn file content to 1st caps(1st char of each word is capital) \n"
		"15.Save \n"
		"16.Exit \n"
		"Enter the option u want do in ur file: ";
		cin >> num;
		return num;
}
void add_text()
{
	string words;
	char filename[100];
	cout << "plz enter your file name with .txt : ";
	cin >> filename;
	fstream file;
	file.open(filename, ios::app);
	if(file)
	{
		cout << "enter text u want add: ";
		std::cin >> std::ws;
		getline(file,words);
		file << words;
	}
	file.close();
}
void Display_file()
{
	fstream file;
	char filename[100];
	cout << "plz enter your file name with .txt : ";
	cin >> filename;
	file.open(filename, ios::in);
	if (file)
	{
		string line;
		while(getline(file, line))
		{
			cout << line << endl;
		}
	}
	file.close();
}
void Empty_file()
{
	fstream file;
	char filename[100];
	cout << "plz enter your file name with .txt : ";
	cin >> filename;
	file.open(filename, ios::out);
	file.close();
}
void Encrypt_file()
{
	string encryption_text, filename;
	cout << "plz enter your file name with .txt : ";
	cin >> filename;
	fstream file;
	file.open(filename.c_str());
	while (getline(file, encryption_text, '\0'))
	{
		for (int i = 0; i < encryption_text.length(); i++)
		{
			if (encryption_text[i] == 10)
			{
				continue;
			}
			encryption_text[i] = encryption_text[i] + 1;

		}
		file >> encryption_text;


	}
	cout << endl;
	file.close();

	file.open(filename, ios::out);
	file << encryption_text;
	file.close();

}
void Decrypt_file()
{
	string Decrypt_text, filename;
	cout << " Enter The Name of File with .txt : ";
	cin >> filename;
	fstream file;
	file.open(filename.c_str());
	while (getline(file, Decrypt_text, '\0'))
	{
		for (int i = 0; i < Decrypt_text.length(); i++)
		{
			if (Decrypt_text[i] == 10)
			{
				continue;
			}
			Decrypt_text[i] = Decrypt_text[i] - 1;

		}
		file >> Decrypt_text;


	}
	cout << endl;
	file.close();

	file.open(filename, ios::out);
	file << Decrypt_text;
	file.close();
}
void Merge()
{	fstream f1;
	fstream f2;
	char car[100];
	string filename, Merge_file;
	cout << " Enter The Name of File with .txt : ";
	cin >> filename;
	cout << " Enter The Name of File u want merge with .txt : ";
	cin >> Merge_file;
	f1.open(filename, ios::in);
	f2.open(Merge_file, ios::app);
	while (!f1.eof()) 
	{
		f1.getline(car, 99, '\n');
		f2 << car << endl;
	}
}
void num_word()
{
	fstream f1;
	string car,filename;
	long long counter = 0;
	cout << " Enter The Name of File with .txt : ";
	cin >> filename;
	f1.open(filename, ios::in);
	while (!f1.eof()) {
		f1 >> car;
		counter++;
	}
	cout << "number of words is: " << counter << endl;
}
void num_char()
{
	fstream f1;
	string filename;
	char ch;
	long long counter = 0;
	cout << " Enter The Name of File with .txt : ";
	cin >> filename;
	f1.open(filename, ios::in);
	while (!f1.eof()) {
		f1.get(ch);
		if (ch == ' ') {
			continue;
		}
		else if (ch == '\n') {
			continue;
		}
		else {
			++counter;
		}
	}
	cout << "number of letters is: " << counter - 1 << endl;
}
void num_line() 
{
	fstream f1;
	string filename;
	char car[100];
	long long counter = 0;
	cout << " Enter The Name of File with .txt : ";
	cin >> filename;
	f1.open(filename, ios::in);
	while (!f1.eof()) {
		f1.getline(car, 99, '\n');
		++counter;
	}
	cout << "number of lines is: " << counter << endl;
}
void search_word()
{
	fstream f1;
	string word, car, filename;
	long long counter = 0;
	bool found = false;
	cout << " Enter The Name of File with .txt : ";
	cin >> filename;
	cout << "enter the word you want to check: ";
	cin >> word;
	f1.open(filename, ios::in);
	while (!f1.eof()) {
		f1 >> car;
		for (size_t i = 0; i < car.length() - 1; i++)
		{
			car[i] = toupper(car[i]);

		}


		for (size_t i = 0; i < word.length() - 1; i++)
		{
			word[i] = toupper(word[i]);

		}

		if (car == word) {
			found = true;
			break;
		}
		else {
			continue;
		}

	}
	if (found == true) {
		cout << "its there.. you are right (+_+)\n";

	}
	else
	{
		cout << "its not here try another one..!";
	}
}
void search() {
	string word,filename;
	string x;
	int count;
	count = 0;
	cout << " Enter The Name of File with .txt : ";
	cin >> filename;
	cout << "Enter the word you want to search about";
	cin >> word;
	ifstream file;
	file.open(filename);
	while (!file.eof()) {
		file >> x;
		if (x == word) {
			count++;
		}
	}
	cout << "the number of existence in the file is "
		<< count;

}
void upper() {
	string upper_text,filename;
	fstream file;
	cout << " Enter The Name of File with .txt : ";
	cin >> filename;
	file.open(filename.c_str());
	while (getline(file,upper_text , '\0'))
	{
		for (int i = 0; i < upper_text.length(); i++)
		{
			
			upper_text[i] = toupper(upper_text[i]);

		}
		file >> upper_text;
	}
	file.close();
	file.open(filename, ios::out);
	file << upper_text;
	file.close();
}
void lower() {
	string lower_text,filename;
	fstream file;
	cout << " Enter The Name of File with .txt : ";
	cin >> filename;
	file.open(filename.c_str());
	while (getline(file, lower_text, '\0'))
	{
		for (int i = 0; i < lower_text.length(); i++)
		{

			lower_text[i] = tolower(lower_text[i]);

		}
		file >> lower_text;
	}
	file.close();
	file.open(filename, ios::out);
	file << lower_text;
	file.close();
}
void first() {
	string first_text,filename;
	fstream file;
	cout << "Enter The Name of File with .txt : ";
	cin >> filename;
	file.open(filename.c_str());
	while (getline(file, first_text, '\0'))
	{
		for (int i = 0; i < first_text.length(); i++)
		{
			first_text[0] = toupper(first_text[0]);
			if (first_text[i] == ' ')
			{
				first_text[i+1] = toupper(first_text[i+1]);

			}
		}
		file >> first_text;
	}
	file.close();
	file.open(filename, ios::out);
	file << first_text;
	file.close();
}
void save() {
	char input[100];
	string filename;
	ifstream file;
	cout << " Enter The Name of File with .txt : ";
	cin >> filename;
	file.open(filename);
	fstream datafile; char fileName[81];
	cout << "Enter the name of a file: ";
	cin.getline(fileName, 81);
	datafile.open(fileName, ios::out);
	cout << "File " << fileName << " saved the data.\n";
	while (!file.eof()) {
		file.getline(input, 100);
		datafile << input << endl;
	}
	file.close();
	datafile.close();
}
