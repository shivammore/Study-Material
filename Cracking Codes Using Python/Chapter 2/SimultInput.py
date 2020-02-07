#Program To Take Multiple Input

No1, No2, No3 = eval(input("Enter Three Numbers  = "))

Average = (No1 + No2 + No3)/3

print("\nAverage = ", Average)


'''
Output - 

student@ubuntu:~/sebcrc2/ch2$ python3 SimultInput.py
Enter Three Numbers  = 10 11 12
Traceback (most recent call last):
  File "SimultInput.py", line 3, in <module>
    No1, No2, No3 = eval(input("Enter Three Numbers  = "))
  File "<string>", line 1
    10 11 12
        ^
SyntaxError: invalid syntax
student@ubuntu:~/sebcrc2/ch2$ python3 SimultInput.py
Enter Three Numbers  = 10, 11, 12

Average =  11.0


'''
