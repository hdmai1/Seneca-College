/**********************************************
Workshop #7
Course: JAC444
Last Name: Mai
First Name: Huu Duc 
ID: 121367189
Section:
This assignment represents my own work in accordance with Seneca Academic Policy.
Signature
Date:July 22, 2020
**********************************************/
package ws7;

import java.util.Scanner;

public class testClass {
	
	static Scanner input = new Scanner(System.in);
	
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		int i  = 0 ; 
		while (i==0) {
			System.out.print("-----------Workshop 7-----------");
			System.out.println();
			System.out.println("1. Task 1");
			System.out.println("2. Task 2");
			System.out.println("3. Exit the program");
			System.out.print("Choose an option: ");
			try {
				int opt = input.nextInt();
				if (opt == 1) 
					Task1.start();
				else if (opt == 2) 
					Task2.start();
				else if (opt == 3) {
					System.out.println("Goodbye!");
					System.exit(0);
				}
				else 
					System.out.println("Wrong choice, only 1-2-3 are accepted.");
			} catch (Exception e) {
				// TODO Auto-generated catch block
				e.printStackTrace();
			}
		}
	}

}
