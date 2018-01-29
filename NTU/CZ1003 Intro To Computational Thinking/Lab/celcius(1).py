# Temperature conversion
import string

fahrenheit = input("Enter temperature in fahrenheit: ")
try: 
    fahrenheit_float=float(fahrenheit)
except ValueError:
    print("Please enter a valid fahrenheit value!")
else:
    celcius = (fahrenheit_float - 32) * 5.0/9.0
    print(celcius)
