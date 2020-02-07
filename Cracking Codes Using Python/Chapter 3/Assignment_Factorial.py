NUM = eval(input("Enter A Number :"))
FACT = 1

print("Factorial Of",NUM," = ")
for i in range(1,NUM+1):
	FACT*=i

print(FACT)

#Output:
'''
student@IOEM1LAB:~/ab$ python3 Assignment_Factorial.py
Enter A Number :5
Factorial Of 5  = 
120
'''
