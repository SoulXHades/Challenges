# Write two functions maxInList(aList) and minInList(aList) that return 
# the maximum and minimum value in a list of integers, aList, respectively. 
# You  have  to  implement  the  two  functions  by  using  recursion. 
# Notice that max() and min() functions for lists are not allowed.

import os
import random


def maxInList(aList):
	#Left final data in list means the max value
	if len(aList) == 1:
		return aList[0]

	else:
		#Python's ternary condition operator
		aList.pop(1) if (aList[0] > aList[1]) else aList.pop(0)

		return maxInList(aList)


def minInList(aList):
	#Left final data in list means the max value
	if len(aList) == 1:
		return aList[0]

	else:
		#Python's ternary condition operator
		aList.pop(1) if (aList[0] < aList[1]) else aList.pop(0)
		
		return minInList(aList)

def userInput():
	try:
		aList = [ int(i) for i in input("Input a list of numbers with spacing: ").split()]
	except ValueError:
		print("[Error]\tPlease input numbers and a spacing only")
		return False
	
	return aList


while 1:
	aList = userInput()

	#Loop again if user input number numbers
	if type(aList) == bool:
		continue

	#Create a new list since list is stored a address like pointers pop in one function affect the whole list
	aList_min = aList[:]

	#Get the Max and Min of the list
	maxNum = maxInList(aList)
	minNum = minInList(aList_min)
	print("Max value: {} \nMin value: {}".format(maxNum, minNum))

	break
