num = eval(input("Enter The Number : "))

isprime = "false"

for i in range(2,10):	
	if num%i==0 and num//i!=1:
		isprime = "false"
		break
	else :
		isprime = "true"

print(isprime)
#Output
'''
student@IOEM1LAB:~/ab$ python3 Assignment_Prime.py
Enter The Number : 2
true
student@IOEM1LAB:~/ab$ python3 Assignment_Prime.py
Enter The Number : 3
true
student@IOEM1LAB:~/ab$ python3 Assignment_Prime.py
Enter The Number : 9
false

'''
