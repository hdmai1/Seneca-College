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

public class T1 {
	
   public static void main(String args[]) {
	   
       Scanner input = new Scanner(System.in);
       
       System.out.print("Enter time1 (hour minute second): ");
       T1_time Time1 = new T1_time(input.nextInt(), input.nextInt(), input.nextInt());
       System.out.println(Time1);
       System.out.println("Elapsed seconds in time1: " + Time1.getSeconds());
       System.out.println();
       
       System.out.print("Enter time2 (elapsed time in seconds): ");
       long newT = input.nextLong();
       T1_time Time2 = new T1_time(newT);
       System.out.println(Time2);
       System.out.println("Elapsed seconds in time2: " + Time2.getSeconds());

       System.out.println();
       System.out.println("time1.compareTo(time2)? " + Time1.compareTo(Time2));
       
       T1_time Time3 = Time1.clone();
       System.out.println("time3 is created as a clone of time1");
       System.out.println("time1.compareTo(time3)? " + Time1.compareTo(Time3));
   }
   
}