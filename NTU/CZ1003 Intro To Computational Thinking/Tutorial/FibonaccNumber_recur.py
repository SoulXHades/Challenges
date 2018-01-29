# Write a function fib(n) which uses recursion to generate the nth Fibonacci number,
# Fn = Fn-1 + Fn-2 where F1 = 1 and F2 = 1. 
# Assume input n is nonnegative.

import sys

def fib(n):
	#When nth term is 1 or 2
	if n == 1 or n == 2:
		return 1
	else:
		return fib(n-1) + fib(n-2)


def userInput():
	try:
		print("This Fibonacci has no 0th term.")
		n = int(input("Input the nth Fibonacci (-1 to exit): "))
	except ValueError:
		print("Input numbers only!")

		return False

	return n

while 1:
	n = userInput()

	#Checks
	if type(n) == bool:
		continue
	elif n == 0 or n < -1:
		print("Please input value more than zero.")
	elif n == -1:
		break

	print(fib(n))