package InsertionSortVSMergeSort;

import java.util.*;

public class temp {

	public static void main(String[] args) {
		int[] theList = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
		int compareCount=0;
		int start = 0, end = 9;
		int mid = (end-start)/2;
		int mainListPos = start;
		int tempList1Pos = 0;
		//split array into half for comparisons
		int[] tempList = new int[mid-start+1];
		int[] tempList1 = new int[end-mid];
		
		//copy 1st half and 2nd half from original list to separate lists
		tempList = Arrays.copyOfRange(theList, start, mid+1);
		tempList1 = Arrays.copyOfRange(theList, mid+1, end+1);
		
		for(int i=0; i<tempList.length; i++)
		{
			System.out.print(tempList[i] + " ");
			System.out.println(tempList1[i]);
		}
		
		
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
		
		for(int i=start; i<=end; i++)
		{
			System.out.print(theList[i]);
		}
		
		System.out.println("\n" + compareCount);

	}

}
