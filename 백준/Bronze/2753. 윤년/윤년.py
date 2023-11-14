x = int(input())
if (int(x%4) == 0 )and (int(x%100) != 0) or (int(x%400) ==0):
    print(1)
else:
    print(0)