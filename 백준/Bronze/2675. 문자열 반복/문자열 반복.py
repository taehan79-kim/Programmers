T = int(input())
for i in range(T):
    r, S = input().split(" ")
    r = int(r)
    qr = ""
    for k in S:
        for j in range(r):
            qr += k
    print(qr)