a = int(input())
for i in range(1, a*2):
    c=""
    if i > a:
        for b in range(1, a * 2+1):
            if b < a + (i-a)+1:
                if b > a - (i-a):
                    c = c + ' '
                else:
                    c = c + '*'
            else:
                c = c + '*'
        print(c)
    else:
        for b in range(1, a*2+1):
            if b < a+(a-(i)+1):
                if b > a-(a-(i)):
                    c = c + ' '
                else:
                    c = c + '*'
            else:
                c = c + '*'
        print(c)