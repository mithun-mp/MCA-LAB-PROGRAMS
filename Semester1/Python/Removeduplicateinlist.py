#DAY-2
#Remove Duplicate elements from list using set
n=int(input("enter the elements"))
l1=[]
for e in range(n):
  l1.append(int(input()))
l2=set(l1)
print(l2)