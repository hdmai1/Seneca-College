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
public class CommissionEmployee extends Employee {
	private double grossSales; 
	private double commissionRate;
	
	public void setRate(double rate) {
		if (rate > 0.0 && rate < 1.0)
			commissionRate = rate;
		else
			throw new ArithmeticException("Rates must be between 0.0 and 1.0" );
	} 
	public void setGS(double sales) {
		if (sales >= 0.0)
			grossSales = sales;
		else
			throw new ArithmeticException("Gross sales must be greater than 0.0" );
	} 
 
	
	public double getRate() {
		return commissionRate;
	} 
	public double getGS() {
		return grossSales;
	} 

	public CommissionEmployee(String fName, String lName, String ssn, double sales, double rate) {
			super(fName, lName, ssn);
			setGS(sales);
			setRate(rate);
	} 
		
	@Override
	public double getPaymentAmount() {
		return getRate() * getGS();
	} 
	
	@Override
	public String toString() {
		return String.format("%s: %s\n%s: $%,.2f; %s: %.2f", "Commission Employee", super.toString(), "Gross", getGS(), "Commission Rate", getRate());
	} 
} 
