def solution(s):
    nums = []
    for i in s.split(" "):
        if i == "Z":
            del(nums[len(nums)-1])
        else:
            nums.append(int(i))
        
    print(nums)
    answer = sum(nums)
    return answer