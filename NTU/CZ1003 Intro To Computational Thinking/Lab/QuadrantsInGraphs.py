import sys

while 1:
	try:
		x_axis = float(input("input x: "))

	except ValueError:
		print("Please input numbers only. \nNo spacing as well.")
		continue

	break

while 1:
	try:
		y_axis = float(input("input y: "))

	except ValueError:
		print("Please input numbers only. \nNo spacing as well.")
		continue

	break


if abs(x_axis) < 1e-7 and abs(y_axis) < 1e-7:
	print("at origin")

elif abs(x_axis) > 1e-7 and abs(y_axis) < 1e-7:
	print("on x-axis")

elif abs(x_axis) < 1e-7 and abs(y_axis) > 1e-7:
	print("on y-axis")

elif x_axis > 0:
	if y_axis > 0:
		print("in quadrant 1")

	else:
		print("in quadrant 4")

else:
	if y_axis > 0:
		print("in quadrant 2")
	else:
		print("in quadrant 3")