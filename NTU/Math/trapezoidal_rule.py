def fx(xi):
    return xi / (1 + xi*xi)

def getDiff_x(a, b, n):
	return (b - a) / n;

print("Trapezoidal rule")
	
a = int(input("Input a = "))
b = int(input("Input b = "))
n = int(input("Input n = "))

while n <= 50:
    count = n
    x_diff = getDiff_x(a, b, n)
    
    xi_left = a;
    xi_right = b;
    total = 0;

    while count != 0:
        total += fx(xi_left) + fx(xi_right)

        xi_left += x_diff;
        xi_right -= x_diff;

        count -= 1;


    print("n", n, "=", total*0.5*x_diff)

    n += 5
