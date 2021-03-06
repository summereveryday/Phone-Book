// Daily_Summer_Mod6_PhonBook
// Author: Summer Daily
// Last Updated: 10/18/18
// Purpose: Illustrate vectors and classes by creating a phone book.

#include "stdafx.h"
#include <iostream>
#include <string>
#include <vector>
using namespace std;

class PhoneBookEntry
{
public:
	PhoneBookEntry();
	PhoneBookEntry(string, string);
	string getName();
	string getNumber();
	void changeNumber(string);
	void toString();
private:
	string name;
	string number;
};

int main()
{
	vector<PhoneBookEntry> PhoneBook;
	string newName;
	string newNumber;

	bool again = true;
	while (again == true)
	{
		cout << "Enter name or press X to quit: ";
		getline(cin, newName);
		if (newName == "X" || newName == "x")
		{
			again = false;
		}
		else
		{
			cout << "Enter phone number as 123-456-7890: ";
			getline(cin, newNumber);
			int length = newNumber.length();
			while (length < 12)
			{
				cout << "The number you entered did not contain enough characters. Please enter it again: ";
				getline(cin, newNumber);
				length = newNumber.length();
			}
			while (length > 12)
			{
				cout << "The number you entered contained too many characters. Please enter it again: ";
				getline(cin, newNumber);
				length = newNumber.length();
			}
			PhoneBookEntry newEntry = PhoneBookEntry(newName, newNumber);
			PhoneBook.push_back(newEntry);
			int lastEntry = PhoneBook.size();
			cout << endl << "You've entered " << lastEntry << " number(s)." << endl;
			lastEntry -=1;
			cout << "Last Entry:" << endl;
			PhoneBook[lastEntry].toString();
		}
	}

	cout << "You've entered these numbers: " << endl;
	for (int i = 0; i < PhoneBook.size(); i++)
	{
		PhoneBook[i].toString();
	}

	system("pause");
    return 0;
}

PhoneBookEntry::PhoneBookEntry()
{
	name = "Nothing Entered.";
	number = "Nothing Entered.";
}
PhoneBookEntry::PhoneBookEntry(string newName, string newNumber)
{
	name = newName;
	number = newNumber;
}
string PhoneBookEntry::getName()
{
	return name;
}
string PhoneBookEntry::getNumber()
{
	return number;
}
void PhoneBookEntry::changeNumber(string newNumber)
{
	number = newNumber;
}
void PhoneBookEntry::toString()
{
	cout << name << endl;
	cout << number << endl << endl;
}