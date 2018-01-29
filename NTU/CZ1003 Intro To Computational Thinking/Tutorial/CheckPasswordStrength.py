import sys

def CheckPassStr(Password):	#simple and efficient way
	specialChar = 0
	lowerChar = 0
	upperChar = 0
	digits = 0
	x = 0

	for i in range(len(Password)):
		x = ord(Password[i])

		if 33 <= x < 48 and specialChar != 1:
			specialChar = 1
		if 58 <= x < 65 and specialChar != 1:
			specialChar = 1
		if 91 <= x < 97 and specialChar != 1:
			specialChar = 1
		if 123 <= x < 127 and specialChar != 1:
			specialChar = 1
		if 48 <= x < 58 and digits != 1:
			digits = 1
		if 65 <= x < 91 and upperChar != 1:
			upperChar = 1
		if 97 <= x < 123 and lowerChar != 1:
			lowerChar = 1

	return specialChar + lowerChar + upperChar + digits

'''def CheckPassStr(Password):
	strengthLevel = 0

	strengthLevel = CheckPassStr1(Password, 33, 48, strengthLevel)

	if strengthLevel != 1:
		strengthLevel = CheckPassStr1(Password, 58, 65, strengthLevel)

	if strengthLevel != 1:
		strengthLevel = CheckPassStr1(Password, 91, 97, strengthLevel)

	if strengthLevel != 1:
		strengthLevel = CheckPassStr1(Password, 123, 127, strengthLevel)

	strengthLevel = CheckPassStr1(Password, 48, 58, strengthLevel)

	strengthLevel = CheckPassStr1(Password, 65, 91, strengthLevel)

	strengthLevel = CheckPassStr1(Password, 97, 123, strengthLevel)

	return strengthLevel

def CheckPassStr1(Password, startNum, endNum, strengthLevel	):
	for i in range(startNum, endNum	):
		for count in range(len(Password)):
			if Password[count] == chr(i):
				strengthLevel += 1
				return strengthLevel

	return strengthLevel'''

def OutputStrLevel(strengthLevel):
	if strengthLevel <= 1:
		print("Password is too weak!")
	elif strengthLevel == 2:
		print("Password strength is average.")
	elif strengthLevel == 3:
		print("Password strength is good.")
	else:
		print("Password strenth is excellent!")

def UserInput():
	return input("Please enter your password (-1 to exit): ")

while 1:
	Password = UserInput()
	
	if Password == '-1':
		break
	elif Password == '':
		print("Please enter something.")
		continue
	elif len(Password) < 6:
		print("Password must be 6 or more characters.") 
		continue

	strengthLevel = CheckPassStr(Password)

	OutputStrLevel(strengthLevel)