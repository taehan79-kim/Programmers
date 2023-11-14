def solution(X, Y):
    nums = [0,0,0,0,0,0,0,0,0,0]
    x_count = [X.count(str(i)) for i in range(10) ]
    y_count = [Y.count(str(i)) for i in range(10) ]
    for i in range(10):
        if (x_count[i] != 0) & (y_count[i]!=0):
            if x_count[i]>=y_count[i]:
                nums[i] = y_count[i]
            else:
                nums[i]=x_count[i]
    result = ""
    for i in range(10):
        result = result + str(i) * nums[i]
    result = result[::-1]
    
    if result =="":
        result ="-1"
    else:
        result = result.lstrip("0")
        if result =="":
            result = "0"
    return result