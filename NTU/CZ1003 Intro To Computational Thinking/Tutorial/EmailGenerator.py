#No special characters in this program (until implemented)

import random
import os

def checkDots(domain):
	repeatedDot = 0

	for i in range(len(domain)):
			if domain[i] == '.' and repeatedDot == 1:
				print("\nThere must not be continuous '.'")
				repeatedDot = 0
				return True
			elif domain[i] == '.' and repeatedDot == 0:
				repeatedDot = 1

	return False

def getDomain():
	while 1:

		print("This is a email generator.")
		print("Your domain must not contain '@' and more than one continuous '.'")
		domain = input("Please input your domain (-1 to exit, cls to clear screen): ")

		if domain == '-1':
			exit()
		elif domain == 'cls':
			os.system('cls' if os.name == 'nt' else 'clear')
			continue

		if domain.find('@') >= 0:
			print("Your domain must not contain '@'")
			continue

		if checkDots(domain) == True:
			continue


		return domain

def getRandUsername():
	usernameLength = random.randint(1, 11)
	username = ''

	for i in range(usernameLength+1):
		while 1:
			randChar = random.randint(48, 122)

			if randChar >= 58 and randChar <= 65:
				continue
			elif randChar >= 91 and randChar <= 96:
				continue
			else:
				username += chr(randChar)

			break

	return username

domain = getDomain()

username = getRandUsername()

print("{}@{}".format(username, domain))