x = [int(input()) for _ in range(9)]
for i in range(9):
    if x[i] == max(x):
        print(x[i])
        print(i+1)