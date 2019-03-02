/*
 * Created by: Ian Oberle
 * Completed on: 12/10/2017
 * Submitted on: 12/10/2017
 * Class: CS 2261
 * Project 6
 */

public class Oberle_CS2261_Project6 
{
	public static void main(String[] args) 
	{		
		//Initializing both binary images and "look" function calls
		int [][]image1 = 
			{
				 {0,1,0,0,0,0,0,0}
				,{0,1,0,0,0,1,0,0}
				,{0,1,1,1,0,0,1,0}
				,{0,0,0,1,1,0,0,1}
				,{0,0,0,0,1,0,0,1}
				,{0,0,0,0,0,1,0,0}
				,{0,0,0,0,0,0,1,0}
			};
		System.out.println("Image 1");
		look(image1);
		
		int [][]image2 = 
			{
				 {0,0,0,0,0,0,0,0}
				,{0,1,1,1,1,0,1,0}
				,{0,0,0,0,1,0,1,0}
				,{0,0,1,1,1,0,1,0}
				,{0,0,1,0,0,0,1,0}
				,{0,0,1,0,0,0,1,0}
				,{0,0,0,0,0,0,1,1}
				,{0,0,0,0,0,0,0,0}
			};
		System.out.println("Image 2");
		look(image2);
		
	}
		
	//look function, searches through the 2-D binary array for the first occurrence of "1".
	//When "1" is found the function will search for the end of the binary trail.
	//When the end of the trail is found the function continues searching from the first "1"
	// to see if there are any other instances of "1"s.
	//When a "1" is found it is changed to "0"
	public static void look (int [][] image)
	{
		int x = 0, y = 0;
		
		//For-loops to look through the entire 2-D array
		for(int i = 0; i < 7; i++)
		{
			for(int j = 0; j < 8;j++)
			{
				x = i;
				y = j;
				
				//Search for "1"s till the end of the trail/path is found
				while(image[x][y] == 1)
				{
					int count = 0;
						
						//All 8 directional possibilities
						if((x+1) != 7 && image[x+1][y] == 1)
						{
							System.out.print("6 ");
							image[x][y] = 0;
							x++;
							count++;
							
						}
						
						else if ((x-1) != -1 && image[x-1][y] == 1)
						{
							System.out.print("2 ");
							image[x][y] = 0;
							x--;
							count++;
						}
			
						else if ((y-1) != -1 && image[x][y-1] == 1)
						{
							System.out.print("4 ");
							image[x][y] = 0;
							y--;
							count++;
						}
					
						else if ((y+1) != 8 && image[x][y+1] == 1)
						{
							System.out.print("0 ");
							image[x][y] = 0;
							y++;
							count++;					
						}
					
						else if (((x-1) != -1 && (y+1) != 8) && image[x-1][y+1] == 1)
						{
							System.out.print("1 ");
							image[x][y] = 0;
							y++;
							x--;
							count++;
						}
						
						else if (((x+1) != 7 && (y+1) != 8) && image[x+1][y+1] == 1)
						{
							System.out.print("7 ");
							image[x][y] = 0;
							y++;
							x++;
							count++;
						}
						
						else if (((x-1) != -1 && (y-1) != -1) && image[x-1][y-1] == 1)
						{
							System.out.print("3 ");
							image[x][y] = 0;
							y--;
							x--;
							count++;
						}
						
						else if (((x+1) != 7 && (y-1) != -1) && image[x+1][y-1] == 1)
						{
							System.out.print("5 ");
							image[x][y] = 0;
							y--;
							x++;
							count++;
						}
						
						//Tells user if end of binary trail has been found
						if (count == 0)
						{
							image[x][y] = 0;
							System.out.println("Count if statement\n");
						}
				}
			}
		}
	}
}
