
public class Scanner extends Machine {
	
	//No-arg constructor
	Scanner()
	{
		price = 80;
		weight = 10;
		name = "Scanner";
		description = "This is a Scanner";	
	}
	
	//Constructor with arguments
	Scanner (double price1, double weight1, String descrip, String name1)
	{
		price = price1;
		if (price1 < 60 || price1 > 300)
		{
			this.price = 80;
		}
		weight = weight1;
		if (weight1 < 2 || weight1 > 25)
		{
			this.weight = 10;
		}
		description = descrip;
		name = name1;
	}
	
	//Set price method
	public void setPrice(double price1)
	{
		this.price = price1;
		if (price1 < 60 || price1 > 300)
		{
			this.price = 80;
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
		if (weight1 < 2 || weight1 > 25)
		{
			this.weight = 10;
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
