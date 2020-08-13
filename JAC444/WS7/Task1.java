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

import java.io.File;
import java.io.FileNotFoundException;
import java.util.ArrayList;
import java.util.Collections;
import java.util.List;
import java.util.Scanner;
public class Task1 {
	static Scanner input = new Scanner(System.in);
	public static void start() {
		System.out.println("----------Part 1----------");
		System.out.print("Enter a file name for baby name ranking: ");
		String fname = input.next();
		File file = new File(fname);
		
		
		List<String> boys = new ArrayList<String>();
		List<String> girls = new ArrayList<String>();
		
		try {
			Scanner file1 = new Scanner(file);
			while (file1.hasNext()) {
				file1.next();
				boys.add(file1.next());
				file1.next();
				girls.add(file1.next());
				file1.next();
			}
			file1.close();
		} catch (FileNotFoundException ex) {System.out.println(ex);};
		
		List<String> mutual = new ArrayList<String>(boys);
		mutual.retainAll(girls);
		System.out.println(mutual.size() + " names used for both genders");
		System.out.print("They are: ");
		for (String name: mutual) {
			System.out.print(name + " ");
		}
		System.out.println();
		
		System.out.println("----------Part 2----------");
		
		sortNremove(boys, "Boys");
		sortNremove(girls, "Girls");
		
	}
	
	public static void sortNremove(List<String> list, String str) {
		System.out.println(str + " Original (" + list.size() + " elements): ");
		for (String name: list) {
			System.out.print(name + " ");
		}
		System.out.println();
		System.out.println();
		
		List<String> sortedNremoved = removeDuplicates(list);
		Collections.sort(sortedNremoved);
		System.out.println(str + " Sorted and Removed Duplicates (" + sortedNremoved.size() + " elements): ");
		for (String name: sortedNremoved) 
			System.out.print(name + " ");
		System.out.println();
		System.out.println();
	}
	
	public static <T> List<T> removeDuplicates(List<T> list) { 
        List<T> newList = new ArrayList<T>(); 
        int count = 0;
        for (T rec : list) {
            if (!newList.contains(rec)) { 
                newList.add(rec);
            } 
            else 
            	count++;
        } 
        if (count == 0)
        	System.out.println("There is no duplicated record");
        else 
        	System.out.println("Successfully removed " + count + " duplicate(s) ");
        return newList; 
    } 
}
