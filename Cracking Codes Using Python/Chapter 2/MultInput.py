#Program To Take Multiple Input

No1 = eval(input("Enter The First Number  = "))
No2 = eval(input("Enter The Second Number = "))
No3 = eval(input("Enter The Third Number  = "))

Average = (No1 + No2 + No3)/3

print("\nAverage = ", Average)


'''
Output - 


student@ubuntu:~/sebcrc2/ch2$ python3 MultInput.py
Enter The First Number  = 10  
Enter The Second Number = 11 
Enter The Third Number  = 12

Average =  11.0

student@ubuntu:~/sebcrc2/ch2$ python3 MultInput.py
Enter The First Number  = 10 11 12
Traceback (most recent call last):
  File "MultInput.py", line 3, in <module>
    No1 = eval(input("Enter The First Number  = "))
  File "<string>", line 1
    10 11 12
        ^
SyntaxError: invalid syntax

'''
