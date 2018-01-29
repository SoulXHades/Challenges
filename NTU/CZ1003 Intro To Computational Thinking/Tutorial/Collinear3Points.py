x = []
y = []
gradients = []

try:
	NumberOfInputs = int(input("Input number of coordinates: "))
except ValueError:
	print("Please input a number only.")
	NumberOfInputs = int(input("Input number of coordinates: "))

for i in range(NumberOfInputs):
	try:
		x.append(float(input("Input x coordinates: ")))
	except ValueError:
		print("Please input a number only.")
		x.append(float(input("Input x coordinates: ")))
	try:
		y.append(float(input("Input y coordinates: ")))
	except ValueError:
		print("Please input a number only.")
		y.append(float(input("Input y coordinates: ")))

gradients.append((y[1]-y[0])/(x[1]-x[0]))
gradients.append((y[2]-y[0])/(x[2]-x[0]))
print(abs(gradients[1]-gradients[0]) < (1e-7))
	
