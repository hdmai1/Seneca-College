/**********************************************
Workshop 3
Course: JAC444 - Semester
Last Name: MAI
First Name:HUU DUC 
ID: 121367189
Section:
This assignment represents my own work in accordance with Seneca Academic Policy.
Signature
Date: June 16, 2020
**********************************************/
public class HourlyEmployee extends Employee {
	private double wage; 
	private double hours;
	
	public void setWage(double newWage) {
		if (newWage >= 0.0)
			wage = newWage;
		else
			throw new ArithmeticException("Wage must be greater than 0.0" );
	} 
	public void setHours(double hoursWorked){
		if ((hoursWorked >= 0.0) && (hoursWorked <= 168.0))
			hours = hoursWorked;
		else
			throw new ArithmeticException("Hours must between 0.0 and 168.0" );
	} 


	public double getWage() {
		return wage;
	}
	public double getHours() {
		return hours;
	} 
	
	public HourlyEmployee(String fName, String lName, String ssn,double newWage, double hoursWorked) {
		super(fName, lName, ssn);
		setWage(newWage); 
		setHours(hoursWorked); 
	} 

	@Override
	public double getPaymentAmount() {
		if (getHours() <= 40) 
			return getWage() * getHours();
		else
			return (40*getWage()) + (1.5*getWage()*(getHours()-40));
	} 

	@Override
	public String toString(){
		return String.format( "Hourly Employee: %s\n%s: $%,.2f; %s: %,.2f", super.toString(), "Hourly wage", getWage(), "Total Hours", getHours());
	} 
} 
