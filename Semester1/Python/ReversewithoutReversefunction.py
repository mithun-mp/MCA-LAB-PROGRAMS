#  reverse list of n elements(without using reverse function)
n=int(input("enter the limit"))
print("enter ",n,"elements")
L1=[]
i=0
for i in range(n):
    L1.append(int(input()))
print("the list is",L1)
print("after reversing")
start=0
end=len(L1)-1
while start<end:
    temp=L1[start]
    L1[start]=L1[end]
    L1[end]=temp
    start=start+1
    end=end-1
print(L1)



