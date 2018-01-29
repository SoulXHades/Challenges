#Given  two  lists  of  grades  (list  of  integers)  from  two  classes,  write  a 
#program  that  will  check  which  class  has 
#the  highest  average  score  and 
#the highest maximum score.

import sys

list1 = [30, 50, 12, 90, 80, 78]
list2 = [50, 11, 45, 79, 90, 00]

list1AVG = 0
list2AVG = 0

list1Max = 0
list2Max = 0

for element in list1:
	list1AVG += element

	if element > list1Max:
		list1Max = element

list1AVG /= len(list1)

for element in list2:
	list2AVG += element

	if element > list2Max:
		list2Max = element

list2AVG /= len(list2)

if list1AVG > list2AVG:
	print("list1 has a higher average of %.1f" % list1AVG)
elif list1AVG < list2AVG:
	print("list2 has a higher average of %.1f" % list2AVG)
else:
	print("Both have the same average of %.1f" % list1AVG)

if list1Max > list2Max:
	print("list1 has a higher maximum score of", list1Max)
elif list1Max < list2Max:
	print("list2 has a higher maximum score of", list2Max)
else:
	print("Both have a maximum score of", list1Max)
