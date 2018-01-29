import sys

try:
	patternWidth = int(input("input pattern width: "))
except ValueError:
	print("Please input integers only.")
	exit()

for count in range(1, (patternWidth*2)):
	starsPrint = count

	if starsPrint > patternWidth:
		starsPrint = (patternWidth*2) - count

	for num in range(starsPrint):
		print("*", end="")

	print()