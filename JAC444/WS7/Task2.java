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

import java.util.HashMap;
import java.util.Map;
import java.util.Scanner;

public class Task2 {
	static Scanner input = new Scanner(System.in);
	public static void start() {
		boolean flag = false;
		Map<String, String> col = new HashMap<>();
		for (int i =0 ;i <25;i++) {
			System.out.print("Input country name: ");
			String country = input.next();
			
			System.out.print("Input capital: ");
			String capital = input.next();
			
			col.put(country, capital);
			System.out.println("Successfully added (" + (i+1) +"/25): " +country + "-" + capital);
			System.out.println();
		}
		
		System.out.println("Here is the list of countries in the map:");
		for (String country: col.keySet()) {
			System.out.print(country + " ");
		}
		while (!flag ) {
			System.out.println("---------------------------");
			System.out.print("Enter the country name: ");
			String country = input.next();
			
			for (String ct: col.keySet()) {
				if (country.equals(ct)) {
					System.out.println("The capital of " + country + " is " + col.get(country));
					flag = true;
					break;
				}
			}
			if (!flag) 
				System.out.println("We don't have " +country + " in our map, please try another country!");
		}
	}
}
