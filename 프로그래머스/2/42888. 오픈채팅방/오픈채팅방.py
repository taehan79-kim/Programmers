def solution(record):
    status = []
    userid = []
    nickname = []
    DB = dict()
    answer = []
    
    ## DB 정리
    for string in record:
        str_split = string.split(" ")
        status.append(str_split[0])
        userid.append(str_split[1])
        
        if str_split[0] == 'Leave':
            nickname.append("")
        else:
            DB[str_split[1]] = str_split[2]
            nickname.append(str_split[2])
    
    #print(DB)
    ## 닉네임 정리
    Users = list(set(userid))
    #for index, i in enumerate(Users):
    
    ## 채팅 출력
    for index, i in enumerate(status):
        if status[index] != "Change":
            x="들어왔습니다" if status[index]=="Enter" else "나갔습니다"
            answer.append("{}님이 {}.".format(DB[userid[index]], x))
        
    
    #print(answer)
    return answer