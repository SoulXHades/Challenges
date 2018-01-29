#Write a program, in the fewest number of lines possible, 
#which creates a list of all the square numbers: x^2 (where 1<=x<=100) that are divisible by 3.

import sys

divisibleby3List = []

for i in range(1, 101):
	if (i**2) % 3 == 0:
		divisibleby3List.append(i**2)

print(divisibleby3List)