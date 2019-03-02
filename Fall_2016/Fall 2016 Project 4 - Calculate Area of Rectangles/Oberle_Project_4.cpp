/*Created By: Ian Oberle
Created on:10/13/16, 
Finished on: 10/13/16 
Submitted on: 10/13/16
Due on: 10/14/16
Project Name: Oberle Project 4-1*/
/*Project asks for dimensions of rectangles and
tells the user which rectangle has the 
greater area*/
#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
	//Declaring Variables 
	double length1, width1, length2, width2, area1, area2; //Use double since length and width can have decimal values

	//Asking user to input variable values
	cout << "What is the length and width of the first rectangle?\n"
		 << "Use numerical values only\n";
	cin >> length1 >> width1;
	cout << "What is the length and width of the second rectangle?\n"
		 << "Use numerical values only\n";
	cin >> length2 >> width2;

	//Stating area formula
	area1 = length1 * width1;
	area2 = length2 * width2;

	//Display area of rectangles (This is not needed for Project. I wanted to add this.)
	cout << "The area of the first rectangel is "<< showpoint << fixed << setprecision(2) << area1 << endl
		 <<" The area of the first rectangle is "<< showpoint << fixed << setprecision(2) << area2 << endl;

	//Establishing Conditional Statements
	if (area1 > area2)
	{
		cout << "The first rectangle has a larger area than the second rectangle.\n";
	}
	else if (area2 > area1)
	{
		cout << "The second rectangle has a larger area than the first rectangle.\n";
	}
	else if (area1 == area2)
	{
		cout << "Both rectangles have the same area.\n";
	}
	
	return 0;
}