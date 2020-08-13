
/**********************************************
Workshop #6
Course: JAC444
Last Name: Mai
First Name: Huu Duc 
ID: 121367189
Section:
This assignment represents my own work in accordance with Seneca Academic Policy.
Signature
Date:July 16, 2020
**********************************************/
import java.util.Scanner;

public class testClass {
	static Scanner input =  new Scanner(System.in);
	public static final ArrayProcessor getMax = array -> {
		double max = array[0];
		for (int i =0 ; i < array.length; i++)
			if (max < array[i])
				max = array[i];
		return max;
	};
	
	public static final ArrayProcessor getMin = array -> {
		double min = array[0];
		for (int i=0 ; i<array.length;i++)
			if (min >array[i])
				min =array[i];
		return min;
	};
	
	public static final ArrayProcessor getSum = array -> {
		double sum = 0;
		for (int i=0;i<array.length;i++)
			sum += array[i];
		return sum;
	};
	
	public static final ArrayProcessor getAvg = array ->{
		return getSum.apply(array)/array.length;
	};
	
	public static ArrayProcessor counter (double value) {
		return array -> {
			int counter = 0;
			for (int i =0 ;i <array.length ;i++)
				if (value == array[i])
					counter++;
			return counter;
		};
	}
	public static double[] initialize() {
		System.out.print("input number of elements of new array: ");
		int NoOfElements = input.nextInt();
		double[] array = new double[NoOfElements];
		for (int i =0 ; i< array.length; i++) {
			System.out.print("Input array[" + i + "]: ");
			array[i] = input.nextDouble();
		}
		System.out.println("-----------------------------------------------");
		System.out.println("This is the array: ");
		for (double i : array)
			System.out.print(i + " ");
		System.out.println();
		System.out.println("-----------------------------------------------");
		return array;
	}
	public static void main(String[] args) {
		// TODO Auto-generated method stub
			double[] arr1 = initialize();
			System.out.println("Sum of array: " + getSum.apply(arr1));
			System.out.println("Max value of array: "+getMax.apply(arr1));
			System.out.println("Min value of array: " +getMin.apply(arr1));
			System.out.println("Average of array: "+getAvg.apply(arr1));
			System.out.println("-----------------------------------------------");
			System.out.println("Choose 1 value of the array to find the occurences: ");
			double choice  = input.nextDouble();
			System.out.println(choice +" appears " + counter(choice).apply(arr1) + " time(s) in the array\nProgram is exiting...");
			input.close();
			System.exit(0);
	}

}
