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
import java.util.ArrayList;
import java.io.File;
import java.util.Scanner;
import java.io.FileNotFoundException;

public class FindWords {
	static Scanner input = new Scanner(System.in);

	public static void Initialize() throws FileNotFoundException {
		
		System.out.print("Enter the file name: ");
		
		File newFile = new File(input.next());
		if (!newFile.exists()) {
			System.out.println("No file detected");
		}
		
		ArrayList<String> library = new ArrayList<String>();
		Scanner input2 = new Scanner(newFile);
		while (input2.hasNext()) {
			String str = input2.nextLine();
			library.add(str);
		}
		input2.close();

		ArrayList<Character> Upper = new ArrayList<Character>();
		ArrayList<Character> Lower = new ArrayList<Character>();
		System.out.println("---------------------------");
		for (String str : library) {
			char words[] = str.toCharArray();
			for (char ch : words) {
				if (Character.isUpperCase(ch)) {
					Upper.add(ch);
				} else if (Character.isLowerCase(ch)) {
					Lower.add(ch);
				}
			}
		}

		FindOcc(Upper);
		FindOcc(Lower);
	}

	public static void FindOcc(ArrayList<Character> arr) {
		int count[] = new int[arr.size()];
		for (int i = 0; i < arr.size(); i++){
			count[arr.get(i)]++;
		}
		char ch[] = new char[arr.size()];

		for (int i = 0; i < arr.size(); i++) {
			ch[i] = arr.get(i);
			int found = 0;
			for (int j = 0; j <= i; j++) {
				if (arr.get(i) == ch[j])
				found++;
			}
			if (found == 1)
				System.out.println("Number of " + arr.get(i) + "'s: " + count[arr.get(i)]);
		}
		System.out.println("---------------------------");

	}
}