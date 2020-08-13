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
public class Invoice implements Payable {
	private String part; 
	private String description;
	private int count;
	private double price;
	
	public Invoice(String newPart, String newDes, int newCnt, 
			double newPrice) {
		part = newPart;
		description = newDes;
		setQuantity(newCnt); 
		setPrice(newPrice);
	}
	

	public void setPart(String newPart) {
		part = newPart;
	}
	public void setDes(String newDes) {
		description = newDes; 
	} 
	public void setQuantity(int newCnt) {
		if ( newCnt >= 0 )
			count = newCnt;
		else
			throw new ArithmeticException("Quantity must be greater than 0");
	} 
	public void setPrice(double newPrice) {
		if ( newPrice >= 0.0 )
			price = newPrice;
		else
			throw new ArithmeticException("Price per item must be greater than 0");
	} 
	

	public String getPart() {
		return part;
	}
	public String getDes() {
		return description;
	}
	public int getQuantity() {
		return count;
	} 
	public double getPrice() {
		return price;
	} 


	@Override
	public double getPaymentAmount() {
		return getQuantity() * getPrice(); 
	}

	@Override
	public String toString() {
		return String.format("%s: \n%s: %s (%s) \n%s: %d \n%s: $%,.2f", "invoice", "part number", getPart(), getDes(), "count", getQuantity(), "price per item", getPrice());
	}
} 
