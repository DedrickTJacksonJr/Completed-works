
// encrypts file name by using ROT13
#include <iostream>
#include<fstream>
#include<string>
using namespace std;

void WriteTranslatedChar(ofstream&, char);
char ROT13( char &x ){
	
	if (x == ' ') {
		return x;
	}
	else if (x >= 'n') {
		 x = x - 13;
		//cout << "n domain :" << y << endl;
		return x;
	}
	else if (x >= 'a') {
		 x = x + 13;
		//cout << "a domain :" << z << endl;
		return x;
	}
	else if (x >= 'N') {
		 x = x - 13;
		//cout << "N domain :" << a << endl;
		return x;
	}
	else {
		 x = x + 13;
		//cout << "A domain :" << b << endl;
		return x;
	}
}

int main()
{
	ofstream fout;
	fout.open("output.rot13");
	string Filename;
	cout << "Enter the name of the file you want encrypted" << endl;
	cout << "Please include the whole file type as well as the name" << endl;
	getline(cin, Filename);
	
	ifstream fin;
	fin.open( Filename.c_str());

	if (!fin) {
		cout << "file could not be found" << endl;
		return 1;
	}

	char position;
	while (!fin.eof()) {
		fin >> position;
	if (fin.eof())
		break;
		
		
		
		ROT13(position);
		cout << position;
		WriteTranslatedChar(fout,position);
	}
	
/*
	//code I used for ROT13

	char changerplus = 'a';
	 changerplus = changerplus + 13;
	 cout << changerplus;



	 for (char i = 65; i <= 125; i++) {
		 cout << i;
	 }*/
	fin.close();
	fout.close();
	return 0;
}
void WriteTranslatedChar(ofstream& fout,  char y)
{
	
	fout << y;
	return;
}


