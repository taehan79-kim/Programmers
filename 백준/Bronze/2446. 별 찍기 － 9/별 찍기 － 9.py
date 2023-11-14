a = int(input())
for i in range(1, a*2):
    c=""
    if i > a:
        for b in range(1, a * 2):
            if b <= a + (i-a):
                if b >= a - (i-a):
                    c = c + '*'
                else:
                    c = c + ' '
        print(c)
    else:
        for b in range(1, a*2):
            if b <= a+(a-(i)):
                if b >= a-(a-(i)):
                    c = c + '*'
                else:
                    c = c + ' '
        print(c)