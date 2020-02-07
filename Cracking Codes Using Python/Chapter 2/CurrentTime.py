#Program to access system time and convert to GMT and IST

import time


currentTime = time.time()

totalSec 	= int(currentTime)
currentSec	= totalSec% 60

totalMin	= totalSec//60
currentMin	= totalMin% 60

totalHr		= totalMin//60
currentHr	= totalHr % 24


print("\tCurrent Time : ",currentHr,":",currentMin,":",currentSec,"GMT")
print("\tCurrent Time : ",currentHr+5,":",currentMin+30,":",currentSec,"IST")


'''
Output - 
student@ubuntu:~/sebcrc2/ch2$ python3 CurrentTime.py
	Current Time :  5 : 38 : 49 GMT
	Current Time :  10 : 68 : 49 IST
student@ubuntu:~/sebcrc2/ch2$ python3 CurrentTime.py
	Current Time :  5 : 38 : 50 GMT
	Current Time :  10 : 68 : 50 IST
student@ubuntu:~/sebcrc2/ch2$ python3 CurrentTime.py
	Current Time :  5 : 38 : 51 GMT
	Current Time :  10 : 68 : 51 IST
student@ubuntu:~/sebcrc2/ch2$ python3 CurrentTime.py
	Current Time :  5 : 38 : 51 GMT
	Current Time :  10 : 68 : 51 IST
student@ubuntu:~/sebcrc2/ch2$ python3 CurrentTime.py
	Current Time :  5 : 38 : 51 GMT
	Current Time :  10 : 68 : 51 IST
student@ubuntu:~/sebcrc2/ch2$ python3 CurrentTime.py
	Current Time :  5 : 38 : 52 GMT
	Current Time :  10 : 68 : 52 IST
student@ubuntu:~/sebcrc2/ch2$ python3 CurrentTime.py
	Current Time :  5 : 38 : 53 GMT
	Current Time :  10 : 68 : 53 IST

student@ubuntu:~/sebcrc2/ch2$ python2 CurrentTime.py
('\tCurrent Time : ', 5, ':', 39, ':', 9, 'GMT')
('\tCurrent Time : ', 10, ':', 69, ':', 9, 'IST')
student@ubuntu:~/sebcrc2/ch2$ python2 CurrentTime.py
('\tCurrent Time : ', 5, ':', 39, ':', 11, 'GMT')
('\tCurrent Time : ', 10, ':', 69, ':', 11, 'IST')
student@ubuntu:~/sebcrc2/ch2$ python2 CurrentTime.py
('\tCurrent Time : ', 5, ':', 39, ':', 12, 'GMT')
('\tCurrent Time : ', 10, ':', 69, ':', 12, 'IST')
student@ubuntu:~/sebcrc2/ch2$ python2 CurrentTime.py
('\tCurrent Time : ', 5, ':', 39, ':', 13, 'GMT')
('\tCurrent Time : ', 10, ':', 69, ':', 13, 'IST')
student@ubuntu:~/sebcrc2/ch2$ python2 CurrentTime.py
('\tCurrent Time : ', 5, ':', 39, ':', 14, 'GMT')
('\tCurrent Time : ', 10, ':', 69, ':', 14, 'IST')
student@ubuntu:~/sebcrc2/ch2$ python2 CurrentTime.py
('\tCurrent Time : ', 5, ':', 39, ':', 14, 'GMT')
('\tCurrent Time : ', 10, ':', 69, ':', 14, 'IST')
student@ubuntu:~/sebcrc2/ch2$ python2 CurrentTime.py
('\tCurrent Time : ', 5, ':', 39, ':', 14, 'GMT')
('\tCurrent Time : ', 10, ':', 69, ':', 14, 'IST')
student@ubuntu:~/sebcrc2/ch2$ python2 CurrentTime.py
('\tCurrent Time : ', 5, ':', 39, ':', 16, 'GMT')
('\tCurrent Time : ', 10, ':', 69, ':', 16, 'IST')

'''
