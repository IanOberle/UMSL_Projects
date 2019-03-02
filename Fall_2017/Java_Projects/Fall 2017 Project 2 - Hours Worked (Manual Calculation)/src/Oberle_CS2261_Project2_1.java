/*
 * Created by: Ian Oberle
 * Started on: 9/22/17; 9:28 AM
 * Completed on: 9/23/17
 * Submitted on: 9/27/17
 */
public class Oberle_CS2261_Project2_1 {
	public static void main(String[] args) {
		
		//Initializing Hours Array
		int [][]employeeHours = {
					{4,2,5,3,4,5,8,}
					,{1,7,8,4,3,3,4,}
					,{2,3,3,4,3,3,2,}
					,{3,3,3,7,3,4,1,}
					,{1,3,2,4,3,6,3,}
					,{5,3,4,4,6,3,4,}
					,{8,3,7,4,8,3,8,}
					,{2,6,3,5,9,2,7,}};
		
		//Creating Sort Array
		int [][] sortArr = new int [8][2];
		int value = 0;
		for(int i = 0; i < 8; i++)
		{
			for (int j = 1; j == 1; j++)
			{
				sortArr[i][j] = value;
				value++;
			}
			for (int j = 0; j == 0; j++)
			{
				for (int k = 0; k < 7; k++)
				{
					sortArr[i][j] += employeeHours[i][k]; 
				}
			}
		}
				
		//Making display of unsorted array before sort
		//Calling display method
		System.out.println ("Array before sort");
		displayHours (employeeHours, sortArr);
		
		//Calling sort method
		sortHours (employeeHours, sortArr);
		
		//Tells user that the program is complete
		System.out.println("Done");
	}
	
	//Sort Method
	public static void sortHours (int [][] employeeHours, int [][] sortArr) 
	{
		//Creating a temporary array for swapping 
		int [] temp1 = new int [7];
		int [][] temp2 = new int [8][2];
		
		//Sorting employeeHours array and Sort Array
			for (int i = 0; i < 7;i++) //Sets target index
			{
				for (int k = (i + 1); k < 8; k++) //Sets searching index
				if (sortArr[k][0] > sortArr[i][0]) 
				{
					for (int j = 0; j < 2; j++)	//Swap for Sort Array  
					{
						temp2[i][j] = sortArr[i][j];
						sortArr[i][j] = sortArr[k][j];
						sortArr[k][j] = temp2[i][j];
					}
					for (int j = 0; j < 7;j++) //Swap for employeeHours Array
					{
						temp1[j] = employeeHours[i][j];
						employeeHours[i][j] = employeeHours[k][j];
						employeeHours[k][j] = temp1[j];
					}
				}
			}

			
		//Creating display for sorted array
		System.out.println ("\nSort Completed. "
				+ "(Employees are sorted from greatest hours worked"
				+ " to least hours worked.)");
		displayHours (employeeHours, sortArr);
	}
	
	//Method to display array
	public static void displayHours (int [][] employeeHours, int [][] sortArr)
	{
		//Sets up days of the week and total hours columns
		System.out.println ("\t\tSu  M   T   W   H   F   Sa  "
				+ "Total Hours\n\t\t"
				+ "---------------------------------------"); 
		for (int i = 0; i < 8;i++)
		{
			//Displays employee number
			System.out.print ("Employee_" + sortArr[i][1] + "|\t");
			for (int j = 0; j < 7;j++)
			{
				//Displays number of hours worked per day
				System.out.print (employeeHours[i][j] + "   ");
			}
			//Displays total number of hours worked per week
			System.out.print(sortArr[i][0]);
			
			System.out.println("\n");
		}
	}
}
