import sys

while 1:
	try:
		print("please input birthday of 1st person")
		year_1 = int(input("year:	"))
		month_1 = int(input("month:	"))
		day_1 = int(input("day:	"))

	except ValueError:
		print("Please input numbers only")
		continue

	break

while 1:
	try:
		print("please input birthday of 2nd person")
		year_2 = int(input("year:	"))
		month_2 = int(input("month:	"))
		day_2 = int(input("day:	"))

	except ValueError:
		print("Please input numbers only")
		continue

	break


if year_1 < year_2:
	print("person 1 is older")

elif year_1 > year_2:
	print("person 2 is older")

else:
	if month_1 < month_2:
		print("person 1 is older")

	elif month_1 > month_2:
		print("person 2 is older")

	else:
		if day_1 < day_2:
			print("person 1 is older")

		elif day_1 > day_2:
			print("person 2 is older")

		else:
			print("they have the same birthday")

