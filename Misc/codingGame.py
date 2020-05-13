import sys
import math

def tp(r,pre,suf,x):
    if len(pre)==x:
        r+=[pre]
    elif len(suf)+len(pre)<x:
        return
    else:
        for i in range(len(suf)):
            v=[]
            v+=suf
            tp(r,pre+suf[i],v[i+1:],x)


s = input()
k = int(input())
r=[]
tp(r,"",list(s),k)

print(*sorted(list(set(r))),sep='\n')