import sys

while 1:
	try:
		Nums = int(input("Input numbers to be added without spacing:"))

	except ValueError:
		print("Please input only numbers without spacing.")
		continue

	break

NumToDivide = 10
Total = 0

while 1:
	NumToBeAdded = Nums%NumToDivide
	Total += NumToBeAdded

	Nums = Nums // NumToDivide

	if Nums == 0:
		print("{:10d}".format(Total))
		break