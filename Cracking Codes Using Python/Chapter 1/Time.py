#Program To finding Hour, Minutes And Second From Total Input Seconds


Total_Seconds = 10056
SS = Total_Seconds%60
MM = (Total_Seconds//60)%60
HH = (Total_Seconds//60)//60

print("HH:MM:SS - ",HH,":",MM,":",SS)

