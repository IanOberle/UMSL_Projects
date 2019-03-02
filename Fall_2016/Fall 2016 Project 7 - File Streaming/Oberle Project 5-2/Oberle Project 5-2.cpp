/*Created by: Ian Oberle
Created on: Can't Remember
Completed on: 11/1/16
Submitted on: 11/3/16
Due on: 11/4/16*/

/*Program reads input from file and displays number of numbers in file,
even numbers in file, odd numbers in file, sum of numbers in file, and
the average of the numbers in the file*/

#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
using namespace std;

int main()
{
	//Stating Variables
	ifstream Random;
	string filename;
	int number;
	int  odd = 0, even = 0, count = 0, sum = 0;
	float average;
	
	//Asking users to input name of file they wish to open
	cout << "Choose a file to open.\n";
	cin >> filename;
	Random.open(filename);

	//Validation Step (Tells whether or not the user-selected file has opened successfully)
	if (!Random)
		cout << "Your file has not opened.\n";
	if (Random)
		cout << "Your file has successfully opened.\n\n";

	//Finding number of numbers (odd and even), sum, and average of file
	while (Random >> number)
	{
		count++;
		sum += number;
		if (number % 2 == 1)
			odd++;
	}
	Random.close();
	even = count - odd;
	average = static_cast<float>(sum /count);
	
	//Print out all conclusions made
	cout << "There are " << count << " numbers in the " << filename << " file.\n";
	cout << "There are " << odd << " odd numbers and " << even << " even numbers\n";
	cout << "The sum of all the numbers is " << sum << endl;
	cout << "The average of the numbers in " << filename << " is "
		<< showpoint << fixed << setprecision(3) << average << endl << endl;

	system("pause");
	return 0;
}
