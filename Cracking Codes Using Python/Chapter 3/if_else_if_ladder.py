#Condition Checking - Else If Ladder

a,b,c = eval(input("Enter 3 Numbers : "))

if a>b:
	if a>c:
		print("Largest Number = ",a)
elif b>c:
	print("Largest Number = ",b)
else:
	print("Largest Number = ",c)

#Output
'''
student@IOEM1LAB:~/ab$ python3 if_else_if_ladder.py
Enter 3 Numbers : 9,8,7
Largest Number =  9
student@IOEM1LAB:~/ab$ python3 if_else_if_ladder.py
Enter 3 Numbers : 8,9,7
Largest Number =  9
student@IOEM1LAB:~/ab$ python3 if_else_if_ladder.py
Enter 3 Numbers : 8,7,9
Largest Number =  9
'''
