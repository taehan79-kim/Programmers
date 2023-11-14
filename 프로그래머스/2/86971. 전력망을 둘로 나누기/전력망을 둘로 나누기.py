import operator
import copy
def solution(n, wires):
    div=100
    tempdiv = 0
    buf = []
    cbuf = []
    timbuf = []
    k = 0
    ## data 정리
    nspace = {}
    espace = {}
    bspace = {}
    for i in range(1, n+1):
        nspace[i] = 0
        espace[i] = []
    
    for i in wires:
        for idx, a in enumerate(i):
            nspace[a] += 1
            espace[a].append(i[1-idx]) 
    bspace = copy.deepcopy(espace) 
    for i in wires:
        a = i[0]
        b = i[1]
        cbuf = [1]
        timbuf = [1000]
        idx = 0
        cnt=0
        bspace[a].remove(b)
        buf = copy.deepcopy(bspace[a]) 
        
        cbuf.append(a)
        timbuf.append(1000)
        # print("cbuf",cbuf)
        c = a
        # print("a",a,"b",b,"bspace[a]",bspace[a], "buf" , buf, "len buf", len(buf))
        while k < len(buf):
                # print ("cbuf pop" , c)
            # print(c,"와 ",buf[k], "서로 삭제", "cbuf",cbuf,"timbuf",timbuf )
            if buf[k] in bspace[c]:
                bspace[c].remove(buf[k])
            if c in bspace[buf[k]]:
                bspace[buf[k]].remove(c)
                
            # print(buf[k],"의 테이블 ",bspace[buf[k]],"== []이면 끝, 아니면 버퍼에 추가")
            # print(bspace)
            if bspace[buf[k]] != []:
                for kk in range(len(bspace[buf[k]])):
                    buf.insert(k+1+kk,bspace[buf[k]][kk])
                # timbuf[-1] = timbuf[-1] - 1
                if timbuf[-1] < 0:
                    cbuf.pop()
                    c = cbuf[-1]
                    timbuf.pop()
                    timbuf[-1] = timbuf[-1] -1
                cbuf.append(buf[k])
                # print("cbuf append", cbuf)
                c = buf[k]
                timbuf.append(len(bspace[buf[k]]))
                # print("buf", buf)
            # print(k, len(buf))
            timbuf[-1] = timbuf[-1] - 1
            while timbuf[-1] < 0:
                cbuf.pop()
                c = cbuf[-1]
                timbuf.pop()
                timbuf[-1] = timbuf[-1] -1
            k = k + 1
        k = 0
        
            
        cnt = len(buf)
        divb = abs(len(wires)-1-cnt)
        
        # print(divb)
        buf = []
        
        
        if div > abs(divb-cnt):
            div = abs(divb-cnt)
        # print("cnt: ", cnt, "divb: " ,divb, "div: " ,abs(divb-cnt))
        
        
        bspace = copy.deepcopy(espace) 
        
    # print(espace) 
    # print(nspace)
    answer = div
    return answer