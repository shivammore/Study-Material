#To Find EMI And Net Payable Amount  For Loan

MonthlyInt = eval(input("Enter Annual Interest Rate :"))/1200

Yrs = eval(input("Enter Total Years = "))
LoanAmount = eval(input("Enter Total Loan Amount"));

EMI = (LoanAmount * MonthlyInt) / (1 - 1 / (1+MonthlyInt)**(Yrs *12))

NetPay = EMI *Yrs *12

print("EMI : ", int(EMI*100)/100)
print("Net Payable Amount : ", int(NetPay*100)/100)


'''
Output

student@ubuntu:~/sebcrc2/ch2$ python3 ComputeLoan.py
Enter Annual Interest Rate :2  
Enter Total Years = 2
Enter Total Loan Amount10000
EMI :  425.4
Net Payable Amount :  10209.66


'''
