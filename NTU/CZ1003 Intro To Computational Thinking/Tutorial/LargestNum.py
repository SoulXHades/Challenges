import sys

def GetLargestNum(ListOfInt, LargestNum, LenOfList):
	for i in range (1, LenOfList):
		if(LargestNum < ListOfInt[i]):
			LargestNum = ListOfInt[i]
	return LargestNum

ListOfInt = [4, 8, -3, 50]

LenOfList = len(ListOfInt)

if(LenOfList == 0):
	exit()
elif(LenOfList == 1):
	LargestNum = ListOfInt[0]
else:
	LargestNum = ListOfInt[0]
	LargestNum = GetLargestNum(ListOfInt, LargestNum, LenOfList)

print(LargestNum)
