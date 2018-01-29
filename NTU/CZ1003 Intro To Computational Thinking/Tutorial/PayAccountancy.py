def BasicPayRating(NumOfWorkHrs):
	return NumOfWorkHrs*10

def OTPayRating(NumOfOTWorkHrs):
	return NumOfOTWorkHrs*15

def FirstTax(TaxToPay_First):
	return TaxToPay_First*0.1
	
def SecondTax(TaxToPay_Second):
	return TaxToPay_Second*0.2
	
def FinalTax(TaxToPay_Final):
	return TaxToPay_Final*0.3

try:
	NumOfWorkHrs = int(input("Input number of working hours: "))
	
	#Check user's input or else will show negative pays.
	if(NumOfWorkHrs < 0):
		print("Number of working hours must not be less than 0.")
		exit()
	
	if(NumOfWorkHrs < 160):
		GrossPay = BasicPayRating(NumOfWorkHrs)
	else:
		GrossPay = BasicPayRating(160) + OTPayRating(NumOfWorkHrs-160)
	
	if(GrossPay <= 1000):
		TotalTax = FirstTax(GrossPay)
	elif(GrossPay <= 1500):
		TotalTax = FirstTax(1000) + SecondTax(GrossPay-1000)
	else:
		TotalTax = FirstTax(1000) + SecondTax(500) + FinalTax(GrossPay-1500)

	
	print("Your gross pay is $%.2f" % GrossPay)
	print("Your total tax is $%.2f" % TotalTax)
	print("Your net pay is $%.2f" % (GrossPay-TotalTax))
except ValueError:
	print("Please input numbers only.")