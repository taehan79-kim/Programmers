def twoMove(a,b):
    k = [1,2,3]
    k.remove(a)
    k.remove(b)
    c=k[0]
    
    _answer = [[a,c],[a,b],[c,b]]
    return _answer

def threeMove(a,b):
    k = [1,2,3]
    k.remove(a)
    k.remove(b)
    c=k[0]
    answer = []
    
    answer+=twoMove(a,c)
    answer+=[[a,b]]
    answer+=twoMove(c,b)
    return answer

def sumMove(a,b,p, answer):
    k = [1,2,3]
    k.remove(a)
    k.remove(b)
    c=k[0]
    _answer=[]
    # print(answer)
    
    if p <= 2:
        answer+=twoMove(a,b)
        return [0]
    else:
        p-=1
        _answer+=sumMove(a,c,p, answer)
        answer+=[[a,b]]
        _answer+=sumMove(c,b,p, answer)
        return _answer
    
    
def sumM(i):
    if i<0:
        
        return 
    i-=1
    print(i)
    sumM(i)
    return  

def solution(n):
    answer = []
    top = [[],[],[]]
    sumMove(1,3,n, answer)
    # print(answer)
    
    # for i in range(n):
        
    # print(threeMove(1,3))
    return answer