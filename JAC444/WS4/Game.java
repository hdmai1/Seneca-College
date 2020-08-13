/**********************************************
Workshop 4
Course: JAC444 - Semester
Last Name: MAI
First Name:HUU DUC 
ID: 121367189
Section:
This assignment represents my own work in accordance with Seneca Academic Policy.
Signature
Date: June 23, 2020
**********************************************/
import java.util.Scanner;

public class Game {
	static Scanner input = new Scanner(System.in);
	public static void main(String[] args) throws Exception {
		boolean flag = false;
		while (!flag) {
			System.out.println("------------------------------------");
			System.out.println("Option 1: Play Hangman Game");
			System.out.println("Option 2: Count occurences in file");
			System.out.println("Option 3: Exit");
			System.out.print("Enter option: ");
			int opt = input.nextInt();
			if (opt == 1) {
				Hangman.Initialize();
			} else if (opt == 2) {
				FindWords.Initialize();
			} else if (opt == 3) {
				System.exit(0);
			} else
				System.out.println("Wrong input");
		}
	}
}
