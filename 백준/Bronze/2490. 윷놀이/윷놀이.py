x = [list(map(int, input().split()))for _ in range(3)]
for i  in range(3):
    a, b, c, d = map(int, x[i])
    cnt = a + b + c + d
    if cnt == 0:
        print("D")
    elif cnt == 1:
        print("C")
    elif cnt == 2:
        print("B")
    elif cnt == 3:
        print("A")
    elif cnt == 4:
        print("E")