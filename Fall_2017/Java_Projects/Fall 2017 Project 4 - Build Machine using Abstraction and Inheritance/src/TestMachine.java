/*
 * Created by: Ian Oberle
 * Started on: 10/22/17
 * Finished on: 10/24/17
 * Submitted on: 10/24/17
 */



//TestMachine Class
public class TestMachine  
{

	public static void main(String[] args) 
	{
		
		//Creating array of objects and initializing all member values
	 	Object [] objects = {
	 			new Printer(199, 30, "This is a laser printer",
	 			"Printer A"),
	 			new Printer(40, 1.5, "This is a inkjet printer", 
	 					"Printer B"),
	 			new Printer(70, 6.0, "This is a slow inkjet printer", 
	 					"Printer C"),
	 			new Printer(50, 7.0, "This is a fast inkjet printer", 
	 					"Printer D"),
	 			new Scanner(70, 4.0, "This is a black and white scanner", 
	 					"Scanner A"),
	 			new Scanner(80, 20, "This is a color scanner", "Scanner B"),
	 			new Scanner(250, 20, "This scanner is both color and "
	 					+ "black/white", "Scanner C"),
	 			new Smartphone(230, .4, "This smartphone has Marshmallow"
	 					+ " operating system", "Smartphone A"),
	 			new Smartphone(240, .3, "This smartphone has KitKat operating"
	 					+ " system", "Smartphone B"),
	 			new Smartphone(235, .45, "This smartphone has Jelly Bean"
	 					+ " operting system", "Smartphone C")};
		
	 	//Loop to display all information for each machine
		for (int i = 0; i < 10; i++)
		{
			if (objects[i] instanceof Printer)
			{
				Machine.count++;
				System.out.println("Machine: " + ((Machine) objects[i]).getCount());
				System.out.println("Name: " + ((Printer)objects[i]).getName());
				System.out.println ("Description: " + ((Printer) objects[i]).getDescription());
				System.out.println ("Price: " +((Printer)objects[i]).getPrice());
				System.out.println ("Weight: " + ((Printer)objects[i]).getWeight());
				System.out.println("");
			}
			else if (objects[i] instanceof Scanner)
			{
				Machine.count++;
				System.out.println("Machine: " + ((Machine) objects[i]).getCount());
				System.out.println("Name: " + ((Scanner)objects[i]).getName());
				System.out.println ("Description: " + ((Scanner) objects[i]).getDescription());
				System.out.println ("Price: " +((Scanner)objects[i]).getPrice());
				System.out.println ("Weight: " + ((Scanner)objects[i]).getWeight());
				System.out.println("");
			}
			else if (objects[i] instanceof Smartphone)
			{
				Machine.count++;
				System.out.println("Machine: " + ((Machine) objects[i]).getCount()); 
				System.out.println("Name: " + ((Smartphone)objects[i]).getName());
				System.out.println ("Description: " + ((Smartphone) objects[i]).getDescription());
				System.out.println ("Price: " +((Smartphone)objects[i]).getPrice());
				System.out.println ("Weight: " + ((Smartphone)objects[i]).getWeight());
				System.out.println("");
			}
		}	
	}
}
