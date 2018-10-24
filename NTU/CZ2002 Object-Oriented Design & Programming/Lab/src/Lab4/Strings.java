package Lab4;

import java.util.Scanner;

public class Strings {

	public static void main(String[] args) {
		Comparable[] stringList;
		int size;
		Scanner scan = new Scanner(System.in);
		System.out.print ("\nHow many strings do you want to sort? ");
		size = scan.nextInt();
		stringList = new Comparable[size];
		System.out.println ("\nEnter the strings...");
		for (int i = 0; i < size; i++)
			stringList[i] = scan.next();
			//String is a concrete class of Comparable so can upcast to it which String already override compareTo() in Comparable Interface
			//Sorting.selectionSort(stringList);
			Sorting.insertionSort(stringList);
			System.out.println ("\nYour strings in sorted order...");
		for (int i = 0; i < size; i++)
			System.out.print(stringList[i] + " ");
		System.out.println ();

	}

}
