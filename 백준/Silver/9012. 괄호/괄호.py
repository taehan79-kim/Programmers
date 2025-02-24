t = int(input())

for _ in range(t):
    s = input()
    q = []
    idx = 0
    isVps = True

    for i in s:
        if i == "(":
            q.append(1)
            idx += 1
        elif i == ")":
            if idx-1 < 0 or q[idx-1] != 1:
                isVps = False
                break
            q.pop(idx-1)
            idx -= 1
    if isVps:
        if idx != 0:
            print("NO")
        else:
            print("YES")
    else:
        print("NO")