def gcd(a,b):
    while b > 0:
        a,b = b, a % b
    return a

def lcm(a,b):
    ans = a*b
    return ans

A,B = map(int, input().split())
print(gcd(A,B))
print(lcm(A,B)//gcd(A,B))