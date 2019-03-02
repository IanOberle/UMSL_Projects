/*Created by: Ian Oberle
Created on: 10/23/16
Finished on: 10/23/16
Submitted on: 10/23/16
Due on: 10/28/16*/
//This program calculates the values of a country club membership
#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
	//Stating variable and initializing
	double membership = 2500, membershipIncrease = .04;
	int count;

	//Creating loop to show value of membership for next 6 years
	for (count = 1; count <= 6; count++)
	{
		membership += (membership * membershipIncrease);
		cout << "The membership for year " << count 
			 << " of membership increase is $" << fixed 
			 << showpoint << setprecision(2) << membership << endl;
	}
	system("pause");
	return 0;
}
