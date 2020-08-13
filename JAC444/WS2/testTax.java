/**********************************************
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

import java.util.*;
import java.util.Scanner;

public class testTax {
	static Scanner input = new Scanner(System.in);

	public static void main(String[] args) {
		boolean flag = false;

		while(!flag) {
			try {
				System.out.println("--------------------------------------------");
				System.out.println("Choice 1: Calculate Taxes");
				System.out.println("Choice 2: Print Taxes for 2001 & 2009");
				System.out.println("Choice 3: Exit the program");
				System.out.print("Enter your choice: ");
				int choice = input.nextInt();
				if (choice == 1) {
					Choice1();
				} else if (choice == 2) {
					Choice2();
				} else if (choice == 3) {
					flag = true;
					System.out.println("Program is terminating...");
				} else
					System.out.println("Wrong Choice, only 1 - 2 - 3 are valid");
			} catch (InputMismatchException ex) {
				System.out.println("Try again. (Incorrect input: an integer is required)");
				System.out.println("--------------------------------------------");
			}
		} 
	}

	public static void Choice1() {
		System.out.println("--------------------------------------------");
		System.out.println("Filing Statuses: ");
		System.out.println("0-Single Filer");
		System.out.println("1-Married jointly or Qualifying Widow(er)");
		System.out.println("2-Married Separately");
		System.out.println("3-Head of House Hold");
		boolean flag = false;
		int FS = 0;
		double[] taxRates2009 = { 10, 15, 25, 28, 33, 35 };
		int[][] intervals2009 = { { 8350, 33950, 82250, 171550, 372950 }, // single
				{ 16700, 67900, 137050, 208850, 372950 }, // widower
				{ 8350, 33950, 68525, 104425, 186475 }, // married separate
				{ 11950, 45500, 117450, 190200, 372950 } // head of house hold
		};
		while (!flag) {
			try {
				System.out.print("Enter your filing status: ");
				FS = input.nextInt();
				if (FS == 0 || FS == 1 || FS == 2 || FS == 3)
					flag = true;
				else
					System.out.println("You have entered an incorrect value, Please try again");
			} catch (InputMismatchException ex) {
				System.out.println("Try again. (Incorrect input: an integer is required)");
			}
			input.nextLine();
		}

		try {
			System.out.print("Enter the Taxable Income: $");
			double income = input.nextDouble();
			IncomeTax icTax = new IncomeTax(FS, intervals2009, taxRates2009, income);
			System.out.print("Tax is: $" + icTax.calculateTax());
			System.out.println();
		} catch (InputMismatchException ex) {
			System.out.println("Try again. (Incorrect input: a double is required)");
			System.out.println("Redirecting to menu...");
		}
		input.nextLine();
	}

	public static void Choice2() {
		IncomeTax tax2001 = new IncomeTax();
		double[] taxRates2001 = { 15, 27.5, 30.5, 35.5, 39.1 };
		tax2001.setRates(taxRates2001);
		int[][] intervals2001 = {
				// single
				{ 27050, 65550, 136750, 297350 },
				// widow
				{ 45200, 109250, 166500, 297350 },
				// Separately
				{ 22600, 54625, 83250, 148675 },
				// household
				{ 36250, 93650, 151650, 297350 } };
		tax2001.setIntervals(intervals2001);

		// tax2009
		boolean flag = false;
		double Start = 0, End = 0;
		IncomeTax tax2009 = new IncomeTax();
		while (!flag) {
			try {
				System.out.print("Enter the amount From: $");
				Start = input.nextDouble();
				System.out.print("Enter the amount To: $");
				End = input.nextDouble();
				flag = true;
			} catch (InputMismatchException ex) {
				System.out.println("Try again. (Incorrect input: a double is required)");
			}
			input.nextLine();
		}
		
		System.out.println("2001 tax tables for taxable income from " + Start + " to " + End);
		System.out.println("------------------------------------------------------------------");

		printTax(tax2001, Start, End);
		System.out.println();
		System.out.println();

		System.out.println("2009 tax tables for taxable income from " + Start + " to " + End);
		System.out.println("------------------------------------------------------------------");
		printTax(tax2009, Start, End);
	}

	public static void printTax(IncomeTax tax, double from, double to) {
		System.out.println("Income\t\t" + "Single\t\t" + "Married Joint\t" + "Married\t\t" + "Head of");
		System.out.println("      \t\t" + "      \t\t" + "or Widow(er)\t" + "Separated\t" + "a House");
		for (double i = from; i <= to; i += 1000) {
			System.out.println();

			tax.setTaxableIncome(i);
			System.out.print(tax.getIncomeTax());

			tax.setFS(tax.SINGLE_FILER);
			System.out.print("\t\t" + tax.calculateTax() + "\t\t");

			tax.setFS(tax.MARRIED_JOINTLY_OR_QUALIFYING_WIDOW);
			System.out.print(tax.calculateTax() + "\t\t");

			tax.setFS(tax.MARRIED_SEPARATELY);
			System.out.print(tax.calculateTax() + "\t\t");

			tax.setFS(tax.HEAD_OF_HOUSEHOLD);
			System.out.print(tax.calculateTax());
		}
		System.out.println();
	}

}
