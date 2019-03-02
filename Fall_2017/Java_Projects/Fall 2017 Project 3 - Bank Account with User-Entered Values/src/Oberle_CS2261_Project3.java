/*
 * Created By: Ian Oberle
 * Class: CS 2261
 * Completed on: 10/9/17
 * Submitted on: 10/10/17
 */


//Imports for Scanner, Date, and Date formatting
import java.util.Scanner;
import java.util.Date;
import java.text.*;

public class Oberle_CS2261_Project3 
{
	public static void main(String[] args)
	{	
		//Initializing Scanner and account option
		Scanner input = new Scanner (System.in);
		int choice = -1;
		
		//Displaying account options for user
		System.out.println("1.Make Default Account\n2.Make Personalized Acount");			
		System.out.print("Please enter option number: ");
		choice = input.nextInt();
		System.out.print("\n");
		
		//Initializing account based on user input
		if (choice == 1)
		{
			System.out.println ("Default Account has been created.\n*ID, balance, and interest rates are set to zero.\n");
			Account ac1 = new Account();
			menu_options(ac1);
		}
		else if (choice == 2)
		{
			int id;
			double balance, annualInterestRate; 
			
			System.out.println ("Custom Account has been created.\n");
			System.out.print("Please enter new ID number: ");
			id = input.nextInt();
			System.out.print("Please enter your starting balance: $");
			balance = input.nextDouble();
			System.out.print("*Do not include any special symbols, only numbers and a decimal (if necessary)\n"
					+ "Please enter the annual interest rate: ");
			annualInterestRate = input.nextDouble();
			Account ac1 = new Account(id,balance,annualInterestRate);
			System.out.println("");
			menu_options(ac1);
		}	
		//Creates default account if invalid input was entered
		else
		{
			System.out.println ("Default Account has been created.\n*ID, balance, and interest rates are set to zero.\n");
			Account ac1 = new Account();
			menu_options(ac1);
		}
	}
	
//Method creates a menu to allow user to pick what to do with their created account
public static void menu_options (Account ac1)
	{
		Scanner input = new Scanner (System.in);
		int menu = 1, choice1 = -1;
		while (menu > 0)
		{	
			//Menu display
			System.out.println("1.Enter Account ID\n2.Enter Starting Balance of Account"
			+ "\n3.Enter Annual Interest Rate\n4.View Account ID\n5.View Balance\n6.View Annual Interest Rate"
			+ "\n7.View Monthly Interest Rate\n8.View Monthly Interest\n9.View Creation Date of Account\n"
			+ "10.Add to balance\n11.Withdraw from Balance\n12.Exit\n\n");
			
			System.out.print("Please enter option number: ");
			choice1 = input.nextInt();
			
			//Checks for valid input
			while (choice1 <= 0 || choice1 > 12)
			{
				System.out.print("Please re-enter your choice: ");
				choice1 = input.nextInt();
			}

			if (choice1 == 1)
			{
				ac1.setID();
			}
			else if (choice1 == 2)
			{
				ac1.setBalance();
			}
			else if (choice1 == 3)
			{
				ac1.setAnnualInterestRate();
			}
			else if (choice1 == 4)
			{
				ac1.getID();
			}
			else if (choice1 == 5)
			{
				ac1.getBalance();
			}
			else if (choice1 == 6)
			{
				ac1.getAnnualInterestRate();
			}
			else if (choice1 == 7)
			{
				ac1.getMonthlyInterestRate();
			}
			else if (choice1 == 8)
			{
				ac1.getMonthlyInterest();
			}
			else if (choice1 == 9)
			{
				ac1.getDate();
			}
			else if (choice1 == 10)
			{
				ac1.deposit();
			}
			else if (choice1 == 11)
			{
				ac1.withdraw();
			}
			else if (choice1 == 12)
			{
				menu = -1;
				System.out.print("Program Terminated");
			}
		}
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
	Account(int id1, double balance1, double annualInterestRate1)
	{
		id = id1;
		balance = balance1;
		annualInterestRate = annualInterestRate1;
		dateCreated = new Date();
	}
	
	//Sets ID value
	public void setID()
	{
		System.out.print("Please enter new ID number: ");
		this.id =input.nextInt();
		while (this.id < 0)
		{
			System.out.print("\nThe ID that was entered is invalid.\nPlease re-enter new ID number: ");
			this.id =input.nextInt();
		}
		System.out.print("\n");
	}
	
	//Displays ID value
	public void getID()
	{
		System.out.println("\nYour account ID is " + this.id + "\n");
	}

	//Display Date and Time that account is created
	public void getDate()
	{
		
		SimpleDateFormat df = new SimpleDateFormat ("E MM/dd/yyyy 'at' hh:mm:ss a zzz");	
		System.out.println("\nYour account was created on " + df.format(this.dateCreated) + "\n");
	}	
	
	//Adds a "deposit" value to the users account
	public void deposit()
	{
		double deposit;
		System.out.print("Please enter your deposit to balance: $");
		deposit = input.nextDouble();
		while (deposit < 0)
		{
			System.out.print("\nThe deposit that was entered is invalid.\nPlease re-enter deposit value: $");
			deposit =input.nextDouble();
		}
		this.balance += deposit;
		System.out.printf("\nYour new account balance is $ %.2f\n", this.balance);
	}
	
	//Sets the starting balance of your account
	public void setBalance()
		{
			if (this.balance > 0)
				System.out.println("A starting balance has already been created for this account.\n");
			else
			{
			System.out.print("Please enter the starting balance for your account: $");
			this.balance = input.nextDouble();
			System.out.printf("\nYour new account balance is $ %.2f\n", this.balance);
			}
		}
	
	//Displays the current balance of a users account
	public void getBalance()
	{
		System.out.printf("\nYour account balance is $ %.2f\n", this.balance);
	}
	
	//Set the annual interest rate
	public void setAnnualInterestRate()
	{
		System.out.print("\n*Do not include any special symbols, only numbers and a decimal (if necessary)\n"
				+ "Please enter the annual interest rate: ");
		this.annualInterestRate = input.nextDouble();
		while (this.annualInterestRate < 0)
		{
			System.out.print("\nThe annual interest rate that was entered is invalid.\nPlease re-enter the interest rate: ");
			this.annualInterestRate =input.nextDouble();
		}
		System.out.print("\n");
	}
	
	//Displays the annual interest rate
	public void getAnnualInterestRate()
	{
		System.out.println("\nThe annual interest rate for your account is " + this.annualInterestRate + "%\n");
	}
	
	//Displays the monthly interest rate
	
	public void getMonthlyInterestRate()
	{
		double monthlyInterestRate = (this.annualInterestRate / 12);
		System.out.print("\nYour monthly interest rate is " + monthlyInterestRate + "%\n\n");
	}
	
	//Displays the monthly interest
	public void getMonthlyInterest()
	{
		double monthlyInterest = (this.balance * (this.annualInterestRate / 1200));
		System.out.printf("\nYour monthly interest is $ %.2f\n\n", monthlyInterest );
	}
	
	//Asks the user how much they would like to withdraw from their account
	public void withdraw()
	{
		System.out.print("\nHow much you like to withdraw from your account? $");
		double withdraw = input.nextDouble();
		while (withdraw < 0)
		{
			System.out.print("\nThe withdraw value that was entered is invalid.\nPlease re-enter withdraw value: $");
			withdraw =input.nextDouble();
		}
		this.balance -= withdraw;
		System.out.printf("Your new account balance is $ %.2f\n", this.balance);
	}
}
