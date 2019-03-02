
public class Printer extends Machine {

	//No-arg constructor
	Printer()
	{
		price = 90;
		weight = 25;
		name = "Printer";
		description = "This is a Printer";
	}
	
	//Constructor with arguments
	Printer (double price1, double weight1, String descrip, String name1)
	{
		price = price1;
		if (price1 < 40 || price1 > 200)
		{
			this.price = 90;
		}
		weight = weight1;
		if (weight1 > 50)
		{
			this.weight = 25;
		}
		description = descrip;
		name = name1;
	}
	
	//Set price method
	public void setPrice(double price1)
	{
		this.price = price1;
		if (price1 < 40 || price1 > 200)
		{
			this.price = 90;
			System.out.print("Default price of " + this.price + " is used.\n");
		}
	}
	
	//Get price method
	public double getPrice()
	{
			return this.price;	
	}
	
	//Set weight method
	public void setWeight(double weight1)

	{
		this.weight = weight1;
		if (weight1 > 50)
		{
			this.weight = 25;
			System.out.print("Default weight of " + this.weight + " is used.\n");

		}
	}
	
	//Get weight method
	public double getWeight()
	{
		return this.weight;
	}
	
	//Set description method
	public void setDescription(String descrip)
	{
		this.description = descrip;
	}
	
	//Get description method
	public String getDescription()
	{
		return this.description;
	}
	
	//Set name method
	public void setName(String name1)
	{
		this.name = name1;
	}
	
	//Get name method
	public String getName()
	{
		return this.name;
	}
}
