def getDiff_x(a, b, n):
	return (b - a) / n;

def xi_mean(xi, diff_x):
	return xi + xi - diff_x;

print("Midpoint rule")

a = int(input("Input a = "))
b = int(input("Input b = "))
n = int(input("Input n = "))

while n != 55:
    count = n
    diff_x = getDiff_x(a, b, n)
    xi = diff_x;
    total_xi = 0;

    while count != 0:
        total_xi += (xi_mean(xi, diff_x)/2) / (1 + (xi_mean(xi, diff_x)/2)*(xi_mean(xi, diff_x)/2))
        
        xi += diff_x;
        count -= 1;

    area = diff_x * total_xi

    print("n", n, "=", area)

    n += 5;

    
