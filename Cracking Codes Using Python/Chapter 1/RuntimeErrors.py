#Program For Achieving Runtime Error

x=11
print("X =",x)
y = x/0

'''
Output-
student@ubuntu:~/ABpython$ python3 RuntimeErrors.py
X = 11
Traceback (most recent call last):
  File "RuntimeErrors.py", line 5, in <module>
    y = x/0
ZeroDivisionError: division by zero

'''
