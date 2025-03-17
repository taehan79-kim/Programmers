def solution(diffs, times, limit):
    answer = 1
    
    st = 1
    end = max(diffs)
    
    max_level = 1
    
    while st < end:
        sum = 0
        mid = (st + end)//2
        for i in range(len(diffs)): # 푼 경우
            if diffs[i] <= mid:
                sum += times[i]
            else: # 못푼 경우
                sum += (diffs[i] - mid)*(times[i] + times[i-1])
                sum += times[i]
        if sum == limit:
            return mid
        elif sum < limit:
            end = mid
            max_level = mid
        else:
            st = mid + 1
    answer = max_level
    return st