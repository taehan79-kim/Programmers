a = int(input())
for i in range(1, a+1):
    c=""
    for b in range(1, a*2):
        if b <= a+(a-i):
            if b >= a-(a-i):
                c = c + '*'
            else:
                c = c + ' '
    print(c)