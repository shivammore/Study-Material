SCORE = eval(input("Enter The Score : "))
if SCORE>75:
	print("Distinction")
elif SCORE>60:
	print("First Class")
elif SCORE>50:
	print("Second Class")
elif SCORE>40:
	print("Pass")
else:
	print("Fail")


#Output:
'''
student@IOEM1LAB:~/ab$ python3 Assignment_Score.py
Enter The Score : 86
Distinction
student@IOEM1LAB:~/ab$ python3 Assignment_Score.py
Enter The Score : 67
First Class
student@IOEM1LAB:~/ab$ python3 Assignment_Score.py
Enter The Score : 55
Second Class
student@IOEM1LAB:~/ab$ python3 Assignment_Score.py
Enter The Score : 45
Pass
student@IOEM1LAB:~/ab$ python3 Assignment_Score.py
Enter The Score : 35
Fail
'''

