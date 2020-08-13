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
public abstract class Employee implements Payable {
	private String first;
	private String last;
	private String SSN;
	
	public void setFName(String fName) {
		first = fName;
	} 
	public void setLName(String lName) {
		last = lName; 
	} 
	public void setSSN(String ssn) {
		SSN = ssn;
	} 
	

	public String getFName() {
		return first;
	}
	public String getLName() {
		return last;
	} 
	public String getSSN() {
		return SSN;
	} 

	public Employee(String fName, String lName, String ssn) {
		first = fName;
		last = lName;
		SSN = ssn;
	}
	
	@Override
	public String toString() {
		return String.format( "%s %s\nSSN: %s", getFName(), getLName(), getSSN());
	} 
}
