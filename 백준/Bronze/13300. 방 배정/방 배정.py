import math
N, F = map(int, input().split())
sex = []
grade = []
sum1 = 0
sum2 = 0
sum3 = 0
sum4 = 0
sum5 = 0
sum6 = 0
for i in range(N):
    x, y = map(int, input().split())
    sex.append(x)
    grade.append(y)
for i in range(N):
        if sex[i] == 1:
            if grade[i] == 1:
               sum1 = sum1 +1
            elif grade[i] == 2:
                sum2 = sum2 + 1
            elif grade[i] ==3:
                sum3 = sum3 + 1
            elif grade[i] == 4:
                sum4 = sum4 + 1
            elif grade[i] == 5:
                sum5 = sum5 + 1
            elif grade[i] == 6:
                sum6 = sum6 + 1
roomsum = math.ceil(sum1/F) + math.ceil(sum2/F) + math.ceil(sum3/F) + math.ceil(sum4/F) + math.ceil(sum5/F) + math.ceil(sum6/F)
sum1 = 0
sum2 = 0
sum3 = 0
sum4 = 0
sum5 = 0
sum6 = 0
for i in range(N):
        if sex[i] == 0:
            if grade[i] == 1:
               sum1 = sum1 +1
            elif grade[i] == 2:
                sum2 = sum2 + 1
            elif grade[i] ==3:
                sum3 = sum3 + 1
            elif grade[i] == 4:
                sum4 = sum4 + 1
            elif grade[i] == 5:
                sum5 = sum5 + 1
            elif grade[i] == 6:
                sum6 = sum6 + 1
roomsum = roomsum + math.ceil(sum1/F) + math.ceil(sum2/F) + math.ceil(sum3/F) + math.ceil(sum4/F) + math.ceil(sum5/F) + math.ceil(sum6/F)
print(roomsum)