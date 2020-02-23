def getDiff_x(a, b, n):
	return (b - a) / n;

def fx(xi):
	return xi / (1 + xi*xi)

print("Simpson's rule")

a = int(input("Input a = "))
b = int(input("Input b = "))
n = int(input("Input n = "))

while n <= 50:
	count = n
	diff_x = getDiff_x(a, b, n)
	xi = a
	total = 0
	
	for i in range(0, n+1):
		if i == 0 or i == n:
			total += fx(xi);
		elif i%2 == 0:
			total += (2 * fx(xi));
		else:
			total += (4 * fx(xi));
		
		xi += a + diff_x;
	
	total *= diff_x * (1/3);

	print("n", n, "=", total);
	
	n += 10;