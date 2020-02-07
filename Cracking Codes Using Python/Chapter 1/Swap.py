#Program For Swapping Of The Numbers

A = 5
B =10

print("A & B Values Before Swapping = ",A , B)

Temp = A
A = B
B = Temp	#Swapping Algorithm Using Extra Variable

print("A & B Values After Swapping = ",A , B)

A,B = B,A
print("A & B Values After Swapping Again = ",A , B) #Without Extra Variable

'''
Output-
student@ubuntu:~/ABpython$ python3 Swap.py
A & B Values Before Swapping =  5 10
A & B Values After Swapping =  10 5
'''
