input()
a=list(map(int,input().split()))
b=sorted((i,-a[j],-j)for j in range(len(a))for i in range(j)if a[i]>a[j])
print(len(b))
for i,j,k in b:print(i+1,-k+1)