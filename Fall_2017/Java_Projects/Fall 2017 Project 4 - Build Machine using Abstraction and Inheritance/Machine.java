public abstract class Machine {
 	
	//Variables that will be inherited by sub-classes
	protected double price, weight;
	protected String description, name;
	static int count;
	
	//Abstract set price method
	public abstract void setPrice(double price1);
	
	//Abstract set weight method
	public abstract void setWeight(double weight1);
	
	//Keeps track of how many machines are created
	public int getCount()
	{
		return count;
	}
}
