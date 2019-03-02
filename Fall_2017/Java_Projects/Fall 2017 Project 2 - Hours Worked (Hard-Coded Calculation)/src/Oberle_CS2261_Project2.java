/*
 * Created by: Ian Oberle
 * Started on: 9/22/17; 9:28 AM
 * Completed on:
 * Submitted on:
 */
public class Oberle_CS2261_Project2 {
	public static void main(String[] args) {
		
		//Initializing Array
		int [][]employeeHours = {
					{4,2,5,3,4,5,8,31,0}
					,{1,7,8,4,3,3,4,30,1}
					,{2,3,3,4,3,3,2,20,2}
					,{3,3,3,7,3,4,1,24,3}
					,{1,3,2,4,3,6,3,22,4}
					,{5,3,4,4,6,3,4,29,5}
					,{8,3,7,4,8,3,8,41,6}
					,{2,6,3,5,9,2,7,34,7}};
		
		//Making display of unsorted array before sort
		System.out.println ("Array before sort");
		displayHours (employeeHours);
		
		//Calling sort function
		sortHours (employeeHours);
	}
	public static void sortHours (int [][] employeeHours) 
	{
		//Creating a temp array for swapping 
		int [] temp1 = new int [9];
	
			for (int i = 0; i < 7;i++) 
			{
				for (int k = (i + 1); k < 8; k++)
				if (employeeHours[k][7] > employeeHours[i][7]) 
				{
					for (int j = 0; j < 9;j++) 
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
				+ " to least hours worked.)\n");
		displayHours (employeeHours);
		
		//Tells user that the program is complete
		System.out.println("Done");
	}
	public static void displayHours (int [][] employeeHours)
	{
		System.out.println ("\t\tSu  M   T   W   H   F   Sa  "
				+ "TotalHours\n\t\t"
				+ "--------------------------------------");
		for (int i = 0; i < 8;i++)
		{
			System.out.print ("Employee_" + employeeHours[i][8] + "|\t");
			for (int j = 0; j < 8;j++)
			{
				System.out.print (employeeHours[i][j] + "   " );
			}
			System.out.println("\n");
		}
	}
}
