import sys
import heapq
sys.setrecursionlimit(10**6)

def parent(ParentIdx, nodeIdx):
    if nodexy[nodeIdx][0] < nodexy[ParentIdx][0]:
        if nodeL[ParentIdx] == []:
            nodeL[ParentIdx] = nodeIdx
        else:
            parent(nodeL[ParentIdx], nodeIdx)
    elif nodexy[nodeIdx][0] > nodexy[ParentIdx][0]:
        if nodeR[ParentIdx] == []:
            nodeR[ParentIdx] = nodeIdx
        else:
            parent(nodeR[ParentIdx], nodeIdx)

def preorder(): 
    while order:
        nodeIdx = order.pop()
        preorderarr.append(nodeIdx +1)
        if nodeL[nodeIdx] != []:
            if nodeR[nodeIdx] != []:
                order.append(nodeR[nodeIdx])
            order.append( nodeL[nodeIdx])
        elif nodeR[nodeIdx] != []:
            order.append(nodeR[nodeIdx])
    
def postorder():
    while order:
        nodeIdx = order.pop()
        postorderarr.append(nodeIdx +1)
        if nodeR[nodeIdx] != []:
            if nodeL[nodeIdx] != []:
                order.append(nodeL[nodeIdx])
            order.append( nodeR[nodeIdx])
        elif nodeL[nodeIdx] != []:
            order.append(nodeL[nodeIdx])
    
def solution(nodeinfo):
    answer = []
    global nodexy
    global nodeL
    global nodeR
    global order
    global preorderarr
    global postorderarr
    nodexy = nodeinfo.copy()
    nodeR=[[] for i in range(len(nodeinfo))]
    nodeL=[[] for i in range(len(nodeinfo))]
    order=[]
    preorderarr=[]
    postorderarr=[]
    nodeinfo.sort(reverse= True, key=lambda x:x[1])
    TempParent = None
    for node in nodeinfo:
        nodeIdx = nodexy.index(node)
        if TempParent != None:
            parent(TempParent,nodeIdx)
        else:
            TempParent = nodeIdx
    nodeIdx = nodexy.index(nodeinfo[0])
    order.append(nodeIdx)
    preorder()
    order=[]
    #nodeinfo.sort(key=lambda x:x[0])
    order.append(nodeIdx)
    postorder()
    answer.append(preorderarr)
    postorderarr.reverse()
    answer.append(postorderarr)
    return answer