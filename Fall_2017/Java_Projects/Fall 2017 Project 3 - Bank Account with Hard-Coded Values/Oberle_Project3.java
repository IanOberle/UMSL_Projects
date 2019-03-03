/*
 * Created By: Ian Oberle
 * Class: CS 2261
 * Completed on: 10/9/17
 * Submitted on: 10/12/17
 */

//Imports for Scanner, Date, and Date formatting
import java.util.Scanner;
import java.util.Date;
import java.text.*;


public class Oberle_CS2261_Project3_1 {

	public static void main(String[] args)
	{	
		//Creates a new account
		Account ac1 = new Account(1122,20000.00);
		
		//Sets annual interest rate
		ac1.setAnnualInterestRate(4.5);
		
		//Withdraws and deposits money into the account
		ac1.withdraw(2500.00);
		ac1.deposit(3000.00);
		
		//Displays and formats output for balance, monthly interest, and date created
		System.out.printf ("Balance is $%.2f\n", ac1.getBalance());
		System.out.printf ("Monthly interest is $%.2f\n",ac1.getMonthlyInterest());
		
		SimpleDateFormat df = new SimpleDateFormat ("E,MMM,MM/dd/yyyy 'at' hh:mm:ss a zzz");	
		System.out.println ("This account was created on " + df.format(ac1.getDate()));
		
}
}
	
	//class that contains data members and member methods for a users account
	class Account
	{
		//Private data members
		private int id;
		private double balance, annualInterestRate;
		private Date dateCreated;
		
		Scanner input = new Scanner (System.in);
		
		//Default Constructor
		Account()
		{
			id = 0;
			balance = 0;
			annualInterestRate = 0;
			dateCreated = new Date();
		}

		//Constructor with arguments
		Account(int id1, double balance1)
		{
			id = id1;
			balance = balance1;
			annualInterestRate = 0;
			dateCreated = new Date();
		}
		
		//Sets ID value
		public void setID(int id1)
		{
			this.id = id1;	
		}
		
		//Displays ID value
		public int getID()
		{
			return this.id;
		}

		//Display Date and Time that account is created
		public Date getDate()
		{
			return dateCreated;
		}	
		
		//Adds a "deposit" value to the users account
		public double deposit(double deposit1)
		{			
			this.balance += deposit1;
			return this.balance;
		}
		
		//Sets the starting balance of your account
		public void setBalance(double balance1)
		{
			this.balance = balance1;
		}
		
		//Displays the current balance of a users account
		public double getBalance()
		{
			return this.balance;
		}
		
		//Set the annual interest rate
		public void setAnnualInterestRate(double annualInterestRate1)
		{
			this.annualInterestRate = annualInterestRate1;
		}
		
		//Displays the annual interest rate
		public double getAnnualInterestRate()
		{
			return this.annualInterestRate;
		}
		
		//Displays the monthly interest rate
		
		public double getMonthlyInterestRate()
		{
			double monthlyInterestRate = (this.annualInterestRate / 12);
			return monthlyInterestRate;
		}
		
		//Displays the monthly interest
		public double getMonthlyInterest()
		{
			double monthlyInterest = (this.balance * (this.annualInterestRate / 1200));
			return monthlyInterest;
		}
		
		//Asks the user how much they would like to withdraw from their account
		public double withdraw(double withdraw1)
		{
			this.balance -= withdraw1;
			return this.balance;
		}
	}
