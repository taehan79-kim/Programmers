a = int(input())
for i in range(1, a+1):
    c=""
    for b in range(1, a+1):
        if b + i > a:
            c = c + '*'
        else:
            c= c+' '
    print(c)