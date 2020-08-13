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
public class BasePlusCommissionEmployee extends CommissionEmployee {
	private double baseSalary; 

	public void setBS(double newSalary) {
		if (newSalary >= 0.0)
			baseSalary=newSalary;
		else
			throw new ArithmeticException("New base salary must be greater than 0.0" );
	} 
	
	public double getBS() {
		return baseSalary;
	} 
	
	@Override
	public double getPaymentAmount() {
		return getBS()+ super.getPaymentAmount();
	} 
	
	public BasePlusCommissionEmployee(String first, String last, String ssn, double sales, double rate, double salary) {
		super(first, last, ssn, sales, rate);
		setBS(salary); 
	} 
	@Override
	public String toString() {
		return String.format("%s %s; %s: $%,.2f", "Base Salaried", super.toString(), "Base Salary", getBS());
	} 
}
