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


public class maxLocation {
	
	double maxVal;
	int row, column;
	
	public static maxLocation getMax(double[][] arr) {
		maxLocation obj = new maxLocation();
		obj.maxVal = arr[0][0];
		for (int i =0 ; i < arr.length; i++) {
			for (int j = 0; j < arr[i].length; j++) {
				if (obj.maxVal < arr[i][j]) {
					obj.maxVal = arr[i][j];
					obj.row = i;
					obj.column = j;
				}
			}
		}
		
		return obj;
	}


} 
