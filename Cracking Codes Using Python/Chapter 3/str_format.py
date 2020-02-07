#String And Number Formatting

print("ASCII Value Of a = ", ord('a'))
print("ASCII Value Of A = ", ord('A'))
print("Offset = ",ord('a')-ord('A'))


print("Charecter B = ",chr(ord('A')+1))
offset = ord('a')-ord('A')
print("Charecter b = ",chr(ord('A')+offset+1))
print("Charecter z = ",chr(ord('A')+offset+25))


print(str(3.14))
print(str(1234))


#Output
'''
student@IOEM1LAB:~/ab$ python3 str_format.py
ASCII Value Of a =  97
ASCII Value Of A =  65
Offset =  32
Charecter B =  B
Charecter b =  b
Charecter z =  z
3.14
1234
'''
