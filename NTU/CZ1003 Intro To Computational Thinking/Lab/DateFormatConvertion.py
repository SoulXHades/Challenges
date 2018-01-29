import sys
import datetime

while 1:
	dateInput = input("Input date in dd/mm/yyyy format:")

	dateInput = dateInput.split('/')

	if (len(dateInput) != 3) or (len(dateInput[0]) != 2) or (len(dateInput[1]) != 2) or (len(dateInput[2]) != 4):
		print("Please input in dd/mm/yyyy only")
		continue

	print("{} {}, {}".format(dateInput[0], datetime.datetime.strptime(dateInput[1], "%m").strftime("%B")[:3], dateInput[2]))
	break

	#print(datetime.datetime.strptime(dateInput, "%d/%m/%Y").strftime("%d %B, %Y"))