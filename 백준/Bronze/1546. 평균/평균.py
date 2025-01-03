N = int(input())
num = list(map(int, input().split()))
num.sort(reverse=True)
result = [x / num[0] * 100 for x in num]
avr = sum(result)/len(result)
print(avr)