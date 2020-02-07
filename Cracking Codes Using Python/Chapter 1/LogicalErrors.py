#Program To Achieve Logical Error

F =35
print("Farenhiet To Celcius Conversion")
print("35 F =", 5/9*F-32,"C")	#Logical Error Will Occur Here

print("Farenhiet To Celcius Conversion")
print("35 F =", 5/9*(F-32),"C")

'''
Output - 

student@ubuntu:~/ABpython$ python3 LogicalErrors.py
Farenhiet To Celcius Conversion
35F = -12.555555555555554 C

Farenhiet To Celcius Conversion
35 F = 1.6666666666666667 C


'''
