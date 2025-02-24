import sys
import copy
input=sys.stdin.readline

n = int(input())
d = set()
for i in range(n):
    st = list(map(str,input().split()))
    if len(st) > 1:
        func, param = st[0], st[1]
    else:
        func = st[0]
    if func == "add":
        d.add(int(param))
    elif func == "remove" and int(param) in d:
        d.remove(int(param))
    elif func == "check":
        if int(param) in d:
            print(1)
        else:
            print(0)
    elif func == "toggle":
        if int(param) in d:
            d.remove(int(param))
        else:
            d.add(int(param))
    elif func == "all":
        d = set([i for i in range(1,21)])
    elif func == "empty":
        d = set()