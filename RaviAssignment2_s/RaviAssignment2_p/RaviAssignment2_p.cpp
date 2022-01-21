
#include <iostream> 
#include <fstream>
using namespace std;

struct nodetype
{
	int coeff, exp;
	nodetype* next;
};

class eq
{
	nodetype* begin, * last;
	int length;

public:
	eq();

	void insertitem(nodetype temp);

	void printlist();
};

eq::eq()
{
	length = 0;
	begin = NULL;
	last = NULL;
}

void eq::insertitem(nodetype temp)
{
	nodetype* t, *t2, *t3;
	t = new nodetype;
	t->coeff = temp.coeff;
	t->exp = temp.exp;
	cout << t->coeff << endl;
	cout << t->exp << endl;
	
	if (begin == NULL) {
		last = t;
		last->next = NULL;
		t->next = begin;
		begin = t;
		cout << "...what?" << endl;
		return;
	}
	if (begin->exp < t->exp)
	{
		t->next = begin;
		begin = t;
		cout << " yeah?" << endl;

		
		//return;
	} else if (last->exp > t->exp)
	{
		last->next = t;
		last = t;
		last->next = NULL;
		cout << " yeah" << endl;
	}
	else {
		t2 = begin; 
		t3 = begin->next;
		cout << "...what" << endl;
		
		while (!((t2->exp > t->exp) && (t3->exp < t->exp))) {
			t2 = t2->next;
			t3 = t3->next;

		}
		t2->next = t;
		t->next = t3;

	}



}



void eq::printlist()
{
	ofstream fout;
	fout.open("OutputFile.txt");
	nodetype* t; 
	t = new nodetype; 
	t = begin;

		fout << t->coeff << "X^" << t->exp;
		t = t->next;

	while (t != NULL)
	{
		fout << "+" << t->coeff<< "X^" << t->exp;
		t= t->next;
	}
	fout.close();
}

/* Driver code*/
int main()
{
	eq ob1;
	ifstream fin;
	ofstream fout;
	fin.open("Equations.txt");
	fout.open("OutputFile.txt");
	nodetype carrier;
	
	int item1, item2;

	
	


	for (int i = 0; i < 6; i++) {

		do {
			fin >> item1 >> item2;
			carrier.coeff = item1;
			carrier.exp = item2;

			ob1.insertitem(carrier);
			
		} while ((item1 != -100) && (item2 != -100));
			
			
		if (item1 == -100) {
			item1 = 0;
			ob1.printlist();
		}
		if (item2 == -100) {
			item2 = 0;
			carrier.coeff = item1;
			carrier.exp = item2;
			ob1.insertitem(carrier);
			ob1.printlist();
		}
		fout << "i did it " << endl;

	}




	fin.close();
	fout.close();
	return 0;
}


// This code is contributed by rathbhupendra 
