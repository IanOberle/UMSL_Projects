/*Created by: Ian Oberle
Created on 9/30/16
Completed on 9/30/16
Submitted on 10/1/16
Due on 10/7/16*/
//Program calculates the value of a savings account
#include <iostream>
#include <cmath>
#include <iomanip>
#include <string>
using namespace std;

int main()
{
	//Assigning variables
	int compounds;
	double principal, amount, rate, rate1, interest;
	string name;
	
	//Asking user to input values into variables
	cout << "What is your full name?\n";
	getline(cin, name);
	cout << "What is the interest rate? (Ex. 4.25, not .0425)\n";
	cin >> rate1;
	cout << "What is the principal?\n";
	cin >> principal;
	cout << "How many times is interest compounded?\n";
	cin >> compounds;
	cout << endl;

	//Establishing equation for value in savings and value of interest, and converting rate to a decimal
	rate = rate1 / 100;
	amount = principal * (pow((1 + (rate / compounds)), compounds));
	interest = amount - principal;
	

	//Displaying individual input values
	cout << "Principal:         $" << setw(7) << principal << endl;
	cout << "Interest rate: " << setw(12) << rate1 << "%" << endl;
	cout << "Times Compounded: " << setw(9) << compounds << endl;
	cout << "Amount in Savings: $" << setw(6) << amount << endl;
	cout << "Value of Interest: $" << fixed << setprecision(2) << setw(7) << interest << endl << endl;

	//Displaying value of money in Savings
	cout << name << " has a total amount of $" << fixed << setprecision(2) << amount << " in the savings account." << endl
		<< endl;
	system("pause");
	return 0;
}