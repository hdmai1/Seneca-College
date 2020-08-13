/**********************************************
Workshop 1
Course:JAC444 - Semester 4
Last Name: Mai
First Name: Huu Duc (Tom)
ID: 121367189
Section:NAA
This assignment represents my own work in accordance with Seneca Academic Policy.
Signature
Date:June 1st
**********************************************/
import java.util.Scanner;
public class ws1_tester {

	static Scanner input = new Scanner(System.in);
	
	public static void task1_tester() {
		System.out.println("------------------------------------");
		System.out.print("Enter the number of rows: ");
		int r = input.nextInt();
		System.out.print("Enter the number of columns: ");
		int c = input.nextInt();

		double [][] arr = new double[r][c];
		
		System.out.println("Enter the array:");
		for (int i = 0; i < r; i++) {
			for (int j = 0; j < c; j++) {
				arr[i][j] = input.nextDouble();
			}
		}
		
		maxLocation obj = maxLocation.getMax(arr);
	
		System.out.println("------------------------------------");
		System.out.println("Largest element in array: " + obj.maxVal);
		System.out.println("Row: "+ obj.row + " Column: " + obj.column);
		System.out.println("---------------Ending Task 1---------------------");
	}
	
	public static void task2_tester() {
		System.out.print("Press Enter key to start rolling dices: ");
		
		//I borrowed this block of code from Stackoverflow
		try {
            System.in.read();
        } catch(Exception e)
        {}
		//


		Craps.Game();
	}
	
	public static void main(String[] args) {
		boolean flag = true;
		while(flag == true) {
			System.out.println("Which task do you want to test?\n1: Task 1\n2: Task 2\n3: Exit" );
			int choice = input.nextInt();
			if (choice == 1) 
				task1_tester();
			else if (choice == 2) 
				task2_tester();
			else if (choice == 3) {
				flag = false;
				System.out.println("Program is terminating...");
			}
			else 
				System.out.println("Wrong Choice, only 1 - 2 - 3 are valid");
		}
	}
}
