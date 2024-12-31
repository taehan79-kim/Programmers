while True:
    a, b, c = input().split(" ")
    a = int(a)
    b = int(b)
    c = int(c)
    if a == 0 and b == 0 and c == 0:
        break
    if (pow(a, 2) + pow(b, 2)) == pow(c, 2) or (pow(b, 2) + pow(c, 2)) == pow(a, 2) or (pow(a, 2) + pow(c, 2)) == pow(b, 2):
        print("right")
    else:
        print("wrong")