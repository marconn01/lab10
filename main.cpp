#include<iostream>
using namespace std;

int* array;
int sizeofarr = 0;
int initcap = 2;

void printele()
{
	if (sizeofarr == 0) {
		cout << "NO ELEMENTS SIR";
	}
	else {
		for (int i =0;i < sizeofarr; i++)
		{
			cout << array[i] << ", ";
		}
	}
	cout << endl;
}

void exparray()
{
	initcap *= 2;
	int* newarray = new int[initcap];
	for (int i = 0; i < sizeofarr; i++)
	{
		newarray[i] = array[i];
	}
	delete[] array;
	array = newarray;
}


void addele(int num)
{
	if (sizeofarr = initcap)
	{
		exparray();
		cout << "ARRAY EXPANDED";
	}
	array[sizeofarr] = num;
	sizeofarr++;
}

void killdil(int num)
{
	int index = -5;
	for (int i = 0; i < sizeofarr; i++)
	{
		if (array[i]==num)
		{
			index = i;
			break;
		}
	}
	if (index == -5) {
		cout << "ITS NOT" << endl;
		return;
	}
	for(int i = index; i < sizeofarr - 1; i++)
	{
		array[i] = array[i + 1];
	}
	sizeofarr--;

	if (sizeofarr <= initcap / 2) {
		initcap /= 2;
		int* newArray = new int[initcap];
		for (int i = 0; i < sizeofarr; i++) {
			newArray[i] = array[i];
		}
		delete[] array;
		array = newArray;
		cout << "Array Bye" << endl;
	}

}
void sizepls() {
	cout << "S: " << initcap << ", E: " << sizeofarr << endl;
}



int main()
{
	array = new int[initcap];
	char choice;
	int num;

	do {
		cout << "Menu" << endl;
		cout << "(p): Print elements" << endl;
		cout << "(a): Add element" << endl;
		cout << "(d): Delete element" << endl;
		cout << "(r): Return size" << endl;
		cout << "(e): Exit" << endl;

		cin >> choice;

		switch (choice)
		{
		case 'p':
			cout << "Elements: ";
			printele();
			break;
		case 'a':
			cout << "Enter New one pls: " << endl;
			cin >> num;
			addele(num);
			break;
		case 'd':
			cout << "Enter Number to eliminate " << endl;
			cin >> num;
			killdil(num);
			break;
		case 's':
			cout << "S = ";
			sizepls();
			break;
		case 'e':
			cout << "Exiting Program: " << endl;
			break;

		default:
			cout << "Enter valid" << endl;
			break;
		}
	} while (choice != 'e');


	delete[] array;
}
	