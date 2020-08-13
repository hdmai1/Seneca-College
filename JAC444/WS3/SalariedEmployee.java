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
public class SalariedEmployee extends Employee {
	private double weeklySalary;
	
	public void setWS(double newSalary) {
		if (newSalary >= 0.0)
			weeklySalary = newSalary;
		else
			throw new ArithmeticException("Weekly salary must be greater than 0.0");
	} 
	public double getWS() {
		return weeklySalary;
	} 

	@Override
	public double getPaymentAmount() {
		return getWS();
	}

	
	public SalariedEmployee(String first, String last, String ssn,double salary) {
		super(first, last, ssn);
		setWS(salary);
	}
	
	@Override
	public String toString() {
		return String.format("Salaried Employee: %s\n%s: $%,.2f", super.toString(), "Weekly", getWS());
	} 
}