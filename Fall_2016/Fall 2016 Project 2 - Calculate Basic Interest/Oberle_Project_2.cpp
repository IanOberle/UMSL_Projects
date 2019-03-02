/*Created by Ian Oberle
Project Name: Oberle Project 2
Date Started: 9/12/16
Date Finished: 9/15/16
Date Submitted: 9/15/16
Date Due: 9/23/16*/
// Calculate price of stocks, commission, and total purchase
#include <iostream>
using namespace std;

int main()
{
	//Stating variables
	int shares = 750, price = 35, transaction = (shares * price);
	float commission = (transaction * .02);
	
	//Displaying variable outputs
	cout << "The total amount paid for stock alone is " << transaction << " dollars." << endl;
	cout << "The amount of commission is only " << commission << " dollars." << endl;
	cout << "The total amont paid is " << commission + transaction << " dollars." << endl;
	system("pause");
	return 0;
}
