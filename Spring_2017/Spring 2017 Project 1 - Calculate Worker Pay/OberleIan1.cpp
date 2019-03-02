/*Created by: Oberle, Ian, 001
Started on: 1/23/2017
Finished on:1/25/2017
Submitted on:1/25/2017*/

//Program takes input for users name, base pay, and hours worked, and outputs their total pay
//Program also generates error messages at the end if pay and/or hours worked inputs are invalid

#include <iostream>
#include <string>

using namespace std;

int main()
{
	//Stating Variables
	string name;
	int count = 1;
	double overtimeHours, payrate, hours, salary; 
	
	//Loop for inputing employee's name, payrate, and hours worked
	//Calculates employee's weekly pay
	do
	{
		cout << "Please enter employee's name.\n";
		cin.ignore();
		getline(cin, name); 
		cout << "Enter the employees base pay.\n";
		cin >> payrate;
		cout << "Enter the hours that the employee worked this week.\n";
		cin >> hours;
		cout << endl;
		
		// Calculates overtimes hours and pay, if employee is eligible
		if (hours > 40) 
		{
			overtimeHours = hours - 40;
			hours = 40;
			salary = payrate * (hours + (overtimeHours * 1.5));
		}
		else // Calculates weekly pay without overtime
			salary = payrate * hours;
			
		// Both inputs for hours and pay are valid	
		if (hours <= 60 && payrate >= 7.65)
			cout << name << "'s total pay this week is $" << salary << endl; 
		
		// Both inputs for hours and pay are invalid
		else if (payrate < 7.65 && hours > 60)
			cout << "!!!Error!!!\n" << name <<
			"'s payrate and hours worked are both invalid quantities.\n"; 
		
		// Input for hours is invalid
		else if (hours > 60)
			cout << "!!!Error!!!\n" << name <<
			" cannot work more than sixty hours per week.\n"; 
		
		// Input for pay is invalid
		else if (payrate < 7.65)
			cout << "!!!Error!!!\n" << name <<
			"'s payrate must be greater than $7.65.\n"; 
		
		// Asks users if they want to input information for another employee	
		cout << "Would you like to calculate the total pay for another employee?\n"
			"If so, press 1\nIf not, press 0\n"; 
		cin >> count;
		system("CLS");
	} while (count == 1);
	cout << "Thank you and have a good day.\n";
	system("pause");
	return 0;
}