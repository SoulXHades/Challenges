package InsertionSortVSMergeSort;

import java.lang.reflect.Array;
import java.util.*;

public class CompareISortvsMSort {

	public static void main(String [] args) {
		CompareISortvsMSort a = new CompareISortvsMSort();
		int n = 100000;
		int start=0;
		long compareCount=0;
		int [] list = new int[n];
		int [] templist1 = new int[n];
		int [] templist2 = new int[n];
		Random rand = new Random();
		
		//(1) Randomly generated datasets of integers in the range [1 ... n].
		System.out.println("");
		System.out.println("Random");
		for(int i=0; i<=n;i+=10000) {
			for(int j=start;j<i;j++) {
				list[j]= rand.nextInt(n) + 1;
			
			}
			//starting index for next loop
			start = i;
			
			//Insertion Sort test
			//clone list
			templist1 = list.clone();
			
			//sort from 0 to the currently inserted length
			System.out.println("InsertionSort n = " + i);
			a.insertionSort(templist1, i);
			
			
			//Merge sort test
			//clone array content
			templist2=list.clone();
			
			//sort from 0 to the currently inserted length
			System.out.println("\nMergeSort n = " + i);
			
			long startTime = System.nanoTime();
			compareCount = a.mergeSort(templist2, 0, i-1);
			
			//merge sort is recursive so need to print here
			long estimatedTime = System.nanoTime() - startTime;
			System.out.println("Time in nanoseconds = " + estimatedTime);
			System.out.println("Comparisons = " + compareCount);
			
			System.out.println("\n------------------------------------\n");
		}
		
		//(2) Integers 1, 2, ..., n sorted in ascending order.
		System.out.println("");
		System.out.println("Ascending");
		for(int i=0; i<=n;i+=10000) {
			for(int j=start;j<i;j++) {
				list[j]= j;
			
			}
			start =i;
			templist1 =list.clone();
			System.out.println("InsertionSort n = " + i);
			a.insertionSort(templist1,i);
			
			//Merge sort test
			//clone array content
			templist2=list.clone();
			
			//sort from 0 to the currently inserted length
			System.out.println("\nMergeSort n = " + i);
			
			long startTime = System.nanoTime();
			compareCount = a.mergeSort(templist2, 0, i-1);
			
			//merge sort is recursive so need to print here
			long estimatedTime = System.nanoTime() - startTime;
			System.out.println("Time in nanoseconds = " + estimatedTime);
			System.out.println("Comparisons = " + compareCount);
			
			System.out.println("\n------------------------------------\n");
		}
		
		//(3) Integers n, n-1, ...,1 sorted in descending order.
		System.out.println("");
		System.out.println("Descending");
		int dec=n-1;
		for(int i=0; i<=n;i+=10000) {
			for(int j=start;j<i;j++) {
				list[j]= dec;
				dec--;
			}
			start =i;
			templist1 =list.clone();
			System.out.println("InsertionSort n = " + i);
			a.insertionSort(templist1,i);
			
			//Merge sort test
			//clone array content
			templist2=list.clone();
			
			//sort from 0 to the currently inserted length
			System.out.println("\nMergeSort n = " + i);
			
			long startTime = System.nanoTime();
			compareCount = a.mergeSort(templist2, 0, i-1);
			
			//merge sort is recursive so need to print here
			long estimatedTime = System.nanoTime() - startTime;
			System.out.println("Time in nanoseconds = " + estimatedTime);
			System.out.println("Comparisons = " + compareCount);
			
			System.out.println("\n------------------------------------\n");
		}
	}
	
	public void insertionSort(int[] thelist,int length) {
		int temp;
		long compareCount=0;
		long startTime = System.nanoTime(); 
		
		for(int i = 1; i<length;i++) {
			for(int j = i; j>0;j--) {
				compareCount++;
				if(thelist[j]<thelist[j-1]) {
					temp = thelist[j];
					thelist[j]=thelist[j-1];
					thelist[j-1]=temp;
				}
				else
					break;
				
			}
		}
		
		long estimatedTime = System.nanoTime() - startTime;
		System.out.println("Time in nanoseconds = " + estimatedTime );
		System.out.println("Comparisons = " + compareCount );
	}
	
	public int mergeSort(int[] theList, int start, int end)
	{
		int mid = (start + end)/2;
		int compareCount=0;
		
		if((end - start) < 1)
			return 0;
		else
		{
			compareCount += mergeSort(theList, start, mid);
			compareCount += mergeSort(theList, mid+1, end);
			
		}
		
		compareCount += merge(theList, start, mid, end);
		
		return compareCount;
	}
	
	public int merge(int[] theList, int start, int mid, int end)
	{
		int compareCount=0;
		//mainListPos is to know where to write to theList
		int mainListPos = start;
		//the starting pointer of 2nd half of the list
		int tempList1Pos = 0;
		//split array into half for comparisons
		int[] tempList = new int[mid-start+1];
		int[] tempList1 = new int[end-mid];
		
		//copy 1st half and 2nd half from original list to separate lists
		tempList = Arrays.copyOfRange(theList, start, mid+1);
		tempList1 = Arrays.copyOfRange(theList, mid+1, end+1);
		
		
		for(int i=0; i<tempList.length; i++)
		{
			for(int j=tempList1Pos; j<tempList1.length; j++)
			{
				++compareCount;
				//comparison between both temporary lists
				if(tempList1[j] < tempList[i])
				{
					//assign to actual list
					theList[mainListPos] = tempList1[j];
					
					//increment the next starting pointer of 2nd half of the list
					//increment the pointer to the original list to write to
					++tempList1Pos;
					++mainListPos;
				}
				else
					break;
			}
			
			//assign to actual list
			theList[mainListPos] = tempList[i];
			//increment the pointer to the original list to write to
			++mainListPos;
		}
		return compareCount;
	}

}
