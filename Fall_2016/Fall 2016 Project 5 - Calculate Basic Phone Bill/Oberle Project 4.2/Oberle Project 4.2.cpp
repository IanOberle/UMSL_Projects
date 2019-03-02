/*Created by: Ian Oberle
Started on: 10/15/16
Finished on: 10/15/16
Submitted on: 10/15/16
Due on: 10/21/16
Project Name: Oberle Project 4.2*/
//Program uses switch to allow user to choose service package

#include <iostream>
using namespace std;

int main()
{
	//Stating Variables
	char choice;
	double price, charge, extraMiuntesCharge;
	int extraMinutes;
	bool check_choice = false;

	//Asking user to select service package (Input)
	cout << "Choose a service package (A, B, or C)\n(Input is case sensitive)\n";
	cin >> choice;
	if (choice == 'A' || choice == 'B' || choice == 'C')
		check_choice = true;
	while (check_choice == false)
	{
		cout << "You have entered an invalid option.\nValid options are"
			"A, B, or C.\n";
		cout << "You would like to cancel enter 0\n\n";
		cin >> choice;
		if (choice == 'A' || choice == 'B' || choice == 'C')
			check_choice = true;
		//Compensates for offset from conversion from ASCII value to int
		if ((int)choice - 48 == 0)
			exit(0);
	}

	//Setting Conditional Prices
	switch (choice)
	{
		case 'A': price = 39.99;
				  extraMiuntesCharge = .45;
				  break;
		case 'B': price = 59.99;
				  extraMiuntesCharge = .40;
				  break;
		case 'C': price = 69.99;
				  break;
	}

	//Selecting Service Package
	switch (choice)
	{
		case 'A': cout << "\nFor $" << price 
			<< " per month 450 minutes are provided."
				  "\nAdditional minutes are $" 
			<< extraMiuntesCharge << " per minute.\n\n";
				  break;
		case 'B': cout << "\nFor $" << price 
			<< " per month 900 minutes are provided."
				  "\nAdditional minutes are $" 
			<< extraMiuntesCharge << " per minute.\n\n";
				  break;
		case 'C': cout << "\nFor $" << price 
			<< " per month unlimited minutes are provided.\n\n";
	}

	//Asking User for number of extra minutes used/Calculates monthly bill
	switch (choice)
	{
	 	case 'A': cout << "How many extra minutes did you use?\n";
				  cin >> extraMinutes;
				  charge = price + (extraMinutes * extraMiuntesCharge);
				  break;
		case 'B': cout << "How many extra minutes did you use?\n";
			      cin >> extraMinutes;
				  charge = price + (extraMinutes * extraMiuntesCharge);
				  break;
	}
	
	//Displaying users monthly bill
	switch (choice)
	{
		case 'A': cout << "\nYour monthly bill is $" << charge << ".\n\n";
				  break;
		case 'B': cout << "\nYour monthly bill is $" << charge << ".\n\n";
				  break;
		case 'C': cout << "\nYour monthly bill is $" << price << ".\n\n";
				  break;
	}

	system("pause");
	return 0;
}