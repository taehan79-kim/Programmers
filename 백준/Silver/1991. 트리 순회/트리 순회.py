from collections import deque
q = deque()
N = int(input())
lc = [0 for i in range(N+1)]
rc = [0 for i in range(N+1)]
parent = [[] for i in range(N+1)]
pre_str = []
in_str = []
post_str = []
for i in range(N):
    c, l, r = input().split()
    c, l, r = ord(c)-64, ord(l)-64, ord(r)-64
    if l != -18:
        lc[c] = l
        parent[l].append(c)
    if r != -18:
        rc[c] = r
        parent[r].append(c)

def preorder(cur):
    pre_str.append(chr(cur+64))
    if lc[cur] != 0:
        preorder(lc[cur])
    if rc[cur] != 0:
        preorder(rc[cur])
def inorder(cur):
    if lc[cur] != 0:
        inorder(lc[cur])
    in_str.append(chr(cur+64))
    if rc[cur] != 0:
        inorder(rc[cur])
def postorder(cur):
    if lc[cur] != 0:
        postorder(lc[cur])
    if rc[cur] != 0:
        postorder(rc[cur])
    post_str.append(chr(cur+64))
preorder(1)
inorder(1)
postorder(1)

print("".join(pre_str))
print("".join(in_str))
print("".join(post_str))