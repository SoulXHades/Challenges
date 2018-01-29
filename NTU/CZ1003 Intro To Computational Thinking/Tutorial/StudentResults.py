import sys

max_score = 0
min_score = 101

print("note: enter -1 to end.")

while 1:

	try:
		grade = int(input("input score: "))

	except ValueError:
		print("Please input numbers only")
		continue

	if grade == -1:
		break
	elif grade < 0:
		print("Please input a score greater or equals to 0.")
		continue
	elif grade > 100:
		print("Please input a score lesser or equals to 100.")
		continue
	elif grade >= 85:
		print("grade: A")
	elif grade >= 65 and grade < 85:
		print("grade: B")
	elif grade >= 45 and grade < 65:
		print("grade: C")
	elif grade < 45:
		print("grade: F")

	if grade > max_score:
		max_score = grade
	if grade < min_score:
		min_score = grade

if min_score == 101:
	min_score = "Not available"

print("max_score =", max_score)
print("min_score =", min_score)