/*Created by: Ian Oberle
Started on: 12/2/16
Finished on:12/7/16
Submitted on:12/8/16
Due on:12/9/16*/
//Program reads grades from a file and puts them into an array.
//Program also calculates averages for each student and test, and finds the highest grade and the number of A's. 
#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;

int main()
{
	//Stating Variables and opening file
	int rows, columns = 0;
	double average, total;
	const int ROW = 5, COLUMN = 3;
	int testGrades[ROW][COLUMN];
	ifstream gradeFile;
	gradeFile.open("p6.dat");
	
	if (!gradeFile)
		cout << "File did not open\n";
	else
		cout << "File opened\n";
	
	//Sends numbers from file to array
	for (rows = 0; rows < ROW; rows++)
	{
		for (columns = 0; columns < COLUMN; columns++)
		{	
			gradeFile >> testGrades[rows][columns];
		}
	}
	gradeFile.close();
		
	
	//Generates and displays student averages
	for (rows = 0; rows < ROW; rows++)
	{
		total = 0;
		for (columns = 0; columns < COLUMN; columns++)
		{
			total += testGrades[rows][columns];
		}
		average = (total / COLUMN);
		cout << "Student " << (rows + 1) << ", test average: " <<
			showpoint << fixed << setprecision(2) << average << ".\n";
	}
	cout << endl;	
	
	//Generates and displays test averages
	for (columns = 0; columns < COLUMN; columns++)
	{
		total = 0;
		for (rows = 0; rows < ROW; rows++)
			total += testGrades[rows][columns];
		average = total / ROW;
		cout << "Test " << (columns + 1) << ", average score: " <<
			showpoint << fixed << setprecision(2) << average << ".\n";
	}
	cout << endl;
	
	//Finds the Highest Score
	int highest = testGrades[0][0];
	for (rows = 0; rows < ROW; rows++)
	{
		for (columns = 0; columns < COLUMN; columns++)
		{
			if (testGrades[rows][columns] > highest)
				highest = testGrades[rows][columns];
		}
	}
	cout << "The highest score is " << highest << ".\n\n";
	
	//Finds the numbers of score that are A's
	int gradeA = 0;
	for (rows = 0; rows < ROW; rows++)
	{
		for (columns = 0; columns < COLUMN; columns++)
			if (testGrades[rows][columns] >= 90)
				gradeA++;
	}
	cout << "There are " << gradeA << " tests that are A's.\n\n";
	system("pause");
	return 0;
}
