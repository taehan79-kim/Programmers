def solution(wallpaper):
    startpoint = [50,50]
    endpoint= [0,0]
    start = False
    for idxi, i in enumerate(wallpaper):
        for idxj, j in enumerate(i):
            if j == "#":
                if startpoint[0] > idxi:
                    startpoint[0] = idxi
                if startpoint[1] > idxj:
                        startpoint[1] = idxj
                if endpoint[0] < idxi+1:
                    endpoint[0] = idxi+1
                if endpoint[1] < idxj+1:
                    endpoint[1] = idxj+1
    #print(startpoint) 
    #print(endpoint)
    answer = startpoint + endpoint
    return answer