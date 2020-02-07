print("For First Point")
x1, y1 = eval(input("Enter X1 and Y1 Co-ordinates : "))

print("For Second Point")
x2, y2 = eval(input("Enter X2 and Y2 Co-ordinates : "))



distance = ((x2-x1)**2 + (y2-y1)**2)**0.5

print("Distance : ", distance)

'''
Output-

student@ubuntu:~/sebcrc2/ch2$ python3 distance.py
For First Point
Enter X1 and Y1 Co-ordinates : 1.5, -3.4
For Second Point
Enter X2 and Y2 Co-ordinates : 4, 5
Distance :  8.764131445842194


'''
