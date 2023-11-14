x= []
for i in range(5):
    x.append(int(input()))
x.sort()
print(int(sum(x)/5))
print(x[round(len(x)/2)])