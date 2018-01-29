import sys

NameOfPerson = input("Input your name (e.g John White Litte):")

SplitedName = NameOfPerson.split(" ")

for length in range(len(SplitedName)):
	print("{}. ".format(SplitedName[length][0]), end="")

print()