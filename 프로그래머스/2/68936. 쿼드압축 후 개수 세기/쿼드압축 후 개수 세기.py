def slicing(arr):
    # print("---------함수 시작-------")
    zeroCnt = 0
    oneCnt = 0
    sumArr = 0
    appArr = []
    if len(arr) == 2:
        for _ in arr:
            zeroCnt += _.count(0)
            oneCnt += _.count(1)
        # print(zeroCnt,oneCnt)
        return zeroCnt, oneCnt
    m = int(len(arr)/2)
    n = int(len(arr))
    for i in range(0, n, m): # x축 2번 반절
        for j in range(0, n, m): # y축 2번 반절
            # print("---")
            for row in arr[i:i+m]: # 행 반절
                sumArr += sum(row[j:j+m]) # 열 반절
                appArr.append(row[j:j+m])
                
            # print(appArr)
            # print("합산 : " + str(sumArr/m**2))
            if sumArr/m**2 == 0:
                zeroCnt += 1
            elif sumArr/m**2 == 1:
                oneCnt +=1
            else:
                zeroCntT, oneCntT = slicing(appArr)
                zeroCnt += zeroCntT
                oneCnt += oneCntT
            appArr = []
            sumArr = 0
    return zeroCnt, oneCnt
    
def solution(arr): 
    answer = []
    zeroCnt = 0
    oneCnt = 0
    zeroCnt, oneCnt = slicing(arr)
        
    # print(zeroCnt)
    # print(oneCnt)
    answer = [zeroCnt, oneCnt]
    if sum(answer) ==4:
        if zeroCnt == 4:
            answer = [1,0]
        elif oneCnt == 4:
            answer = [0,1]
    return answer