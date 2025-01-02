while True:
    num = input()
    if int(num) == 0:
        break
    flag = True
    for i in range(int(len(num)/2)):
        if num[i] != num[len(num)-1 -i]:
            flag = False
            break
    
    if flag:
        print("yes")
    else:
        print("no")