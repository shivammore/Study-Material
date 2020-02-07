#Program To Take Input From User On Console

radius = input("Enter The Radius : ")
print("Area Of Circle With Radius : ",radius," is: ", (radius**2)*3.14);


'''python3
Output-
student@ubuntu:~/sebcrc2/ch2$ python3 InputConsole.py
Enter The Radius : 10
Area Of Circle With Radius :  10  is:  314.0
student@ubuntu:~/sebcrc2/ch2$ python3 InputConsole.py
Enter The Radius : 5
Area Of Circle With Radius :  5  is:  78.5

''''''python2
student@ubuntu:~/sebcrc2/ch2$ python InputConsole.py
Enter The Radius : 5
Traceback (most recent call last):
  File "InputConsole.py", line 3, in <module>
    radius = eval(input("Enter The Radius : "))
TypeError: eval() arg 1 must be a string or code object
student@ubuntu:~/sebcrc2/ch2$ python InputConsole.py
Enter The Radius : 5
('Area Of Circle With Radius : ', 5, ' is: ', 78.5)


'''
