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
import java.util.Random;
public class Craps {
	public static void Game() {
		System.out.println("------------------------------------");
		Random rd = new Random();
		int dice1, dice2;

		dice1 = rd.nextInt(6)+1;
		
		dice2 = rd.nextInt(6)+1;


		int sum = dice1 + dice2;

		System.out.println("You rolled " + dice1 + " + " + dice2 + " = " + sum);
		
		if (sum == 2 || sum == 3||sum==12) {
			System.out.println("Craps, better luck next time.");
		}
		else if (sum == 7 || sum == 11) {
			System.out.println("Naturals, you won the game !!! ");
		}
		else {
			System.out.println("Point is established, set to "+ sum);
			
			boolean flag = true;
			while (flag == true) {
				dice1 = rd.nextInt(6)+1;
				dice2 = rd.nextInt(6)+1;
				int newSum = dice1+dice2;
				
				System.out.println("You rolled " + dice1 + " + " + dice2 + " = " + newSum);
				
				if (newSum == 7) {
					System.out.println("Craps, better luck next time.");
					flag = false;
				}
				else if (newSum == sum) {
					System.out.println("Congratulations, you won the game !!! ");
					flag = false;
				}
			}
		}
		
		
		System.out.println("---------------Ending Task 2---------------------");
	}
}
