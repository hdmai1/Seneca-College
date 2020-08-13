/**********************************************
Workshop #10
Course: JAC444 - Summer 2020
Last Name: Mai
First Name: Huu Duc
ID: 121367189
Section: NAA
This assignment represents my own work in accordance with Seneca Academic Policy.
Signature
Date: 10/08/2020
**********************************************/
import java.util.Scanner;

public class T2_bank {
	public static void main(String[] args) {
		
		
		Scanner input = new Scanner(System.in);
		System.out.print("Enter number of banks: ");
		int n = input.nextInt();
		
		double[] bal = new double[n];
		double[][] borrowers = new double[n][n];
		
		int temp;
		double temp1;
		boolean flag = false;
		
		
		System.out.print("Enter the limit: ");
		int limit = input.nextInt();
		
		
		for (int i = 0; i < n; i++) {
			System.out.println("For Bank #" + i + " :");
			System.out.print("\tBalance: ");
			bal[i] = input.nextDouble();
			
			System.out.print("\tNumber of banks Loaned: ");
			int m = input.nextInt();
			
			for (int j = 0; j < m; j++) {
				System.out.print("\t\tBank ID who gets the loan: ");
				temp = input.nextInt();
				System.out.print("\t\tLoaned Amount: ");
				temp1 = input.nextDouble();
				borrowers[i][temp] = temp1;
			}
			
		}
		boolean[] check = new boolean[n];
		do {
			flag = false;
			for (int i = 0; i < n; i++) {
				double asset = bal[i];
				for (int j = 0; j < borrowers[i].length; j++) 
					asset += borrowers[i][j];
		
				if (asset < limit) {
					check[i] = true;
					
					for (int j = 0; j < borrowers.length; j++) {
						if (borrowers[j][i] != 0) {
							borrowers[j][i] = 0;
							flag = true;
						}
					}
				}
			}
		} while (flag);
		System.out.println("-----------------------------------");
		System.out.print("Unsafe banks are:");
		for (int i = 0; i < check.length; i++) {
			if (check[i]) 
				  System.out.print("Bank " + i + " ");
		  }
		 
	}
}
