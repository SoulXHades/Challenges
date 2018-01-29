def GetNumDiff(ListOfNums):
	MinNum = ListOfNums[0]
	MaxNum = ListOfNums[0]
	
	for i in range(1,3):
		if(MinNum > ListOfNums[i]):
			MinNum = ListOfNums[i]
		if(MaxNum < ListOfNums[i]):
			MaxNum = ListOfNums[i]
	
	return abs(MaxNum-MinNum)

ListOfNums = []

try:
	for i in range(1,4):
		print("Input number %d:" % i)
		ListOfNums.append(float(input("")))
except ValueError:
	print("Please input numbers only.")
	exit()

NumRange = GetNumDiff(ListOfNums)

print("The numerical range is", NumRange)