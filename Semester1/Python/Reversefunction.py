# reverse list of n elements(using reverse function)
n=int(input("enter the limit"))
print("enter ",n,"elements")
L1=[]
i=0
for i in range(n):
    L1.append(int(input()))
print("the list is",L1)
print("after reversing")
L1.reverse()
print(L1)