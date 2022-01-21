#include <iostream>
using namespace std;

int Ea(int r0, int r1) {
	int t; 
	if (r0 < r1) {
		 t = r0;
		r0 = r1;
		r0 = t;
	}
	int ri = r0 % r1;
	if (ri != 0) {
		Ea(r1,ri);
	}
	return ri;
}

int main() {

	int r0, r1, i, answer;
	do {
	cout << "enter a number for r0" << endl;
	cin >> r0;

	cout << "enter a number for r1" << endl;
	cin >> r1;
	} while (r0 < r1); 
	i = 1;
	
	answer =Ea(r0, r1);

	cout << " The answer is " << answer << endl;


	return 0; 
}