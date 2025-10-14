#DAY-2
#check the count of each elements in the list
n=int(input("enter the elements"))
l1=[]
for e in range(n):
  l1.append(int(input()))
for e in range(len(l1)):
  if l1[e] not in l1[:e]:
    counts=l1.count(l1[e])
    print(l1[e],":",counts)

