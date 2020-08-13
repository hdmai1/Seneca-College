/*********************************************
Workshop #2
Course: JAC444 - Semester
Last Name: Mai
First Name: Huu Duc 
ID: 121367189
Section:
This assignment represents my own work in accordance with Seneca Academic Policy.
Signature
Date:June 09, 2020
**********************************************/



package workshops;
import java.util.Scanner;

public class IncomeTax {
	static Scanner input = new Scanner(System.in);
	//1. Filing status.
	int filingStatus;
	
	//2. Constants for above statuses
	final int SINGLE_FILER = 0;
	final int MARRIED_JOINTLY_OR_QUALIFYING_WIDOW = 1;
	final int MARRIED_SEPARATELY = 2;
	final int HEAD_OF_HOUSEHOLD = 3 ;
	
	//3. Double dimension array, store tax intervals/brackets for each filing status.
	
	 int[][] intervals;
	
	//4. single dimension array to store tax rates for each interval.
	 double[] rates;
	
	//5. Stores taxable income
	 double taxableIncome;
	
	//6. methods for each data field and getIncomeTax() 
	public void setFS(int fs) {
		this.filingStatus = fs;
	}
			
	public void setIntervals(int[][] itv) {
		this.intervals = itv;
	}
			
	public void setRates(double[] rt) {
		this.rates = rt;
	}
			
	public void setTaxableIncome(double income) {
		this.taxableIncome = income;
	}
	
	public int getFilingStatus() {
		
		return filingStatus;
	}
	public double[] getRates() {
		return rates;
	}
	public int[][] getIntervals() {
		return intervals;
	}
	public double getIncomeTax() {
		return taxableIncome;
	}
	
	
	//7. no-arg constructor:
	IncomeTax() {
		double[] taxRates2009 = {10,15,25,28,33,35};
		int[][] intervals2009 = {
				{8350, 33950, 82250, 171550, 372950}, //single
				{16700, 67900, 137050, 208850, 372950}, //widower
				{8350, 33950, 68525, 104425,186475}, //married separate
				{11950, 45500, 117450, 190200, 372950} //head of house hold
		};
		setRates(taxRates2009);
		setIntervals(intervals2009);
	};
	
	//8. overloaded constructor
	IncomeTax(int filingStatus, int[][] intervals, double[] rates,double taxableIncome) {
		setFS(filingStatus);
		setIntervals(intervals);
		setRates(rates);
		setTaxableIncome(taxableIncome);
	};
	
	// calculating the taxes
	public double calculateTax() {
		
		double tax= 0;
		double income = getIncomeTax();
		
		int i =0;
		boolean flag = false;
		double subTax = 0;
		double hold = 0;
		while (!flag && i< rates.length) {
			if (income > intervals[this.filingStatus][i] ){
				tax = (intervals[this.filingStatus][i]-hold)*rates[i]/100;
				subTax += tax;
				income = income - (intervals[this.filingStatus][i]-hold);
				hold = intervals[this.filingStatus][i] + 1 ;
				i++;
			}
			else if(income <= intervals[this.filingStatus][i] && i > 0) {
				tax = income*rates[i]/100;
				subTax+= tax;
				flag = true;
			}
		}
		return subTax;
	}
}
