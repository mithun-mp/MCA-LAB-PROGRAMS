#check the number of greater element in the right side of the list element using funtion
def readlist():
  n=int(input("enter the elements\n"))
  l1=[]
  for e in range(n):
    l1.append(int(input()))
  greater(l1)
def greater(l1):
  l2=[]
  for i in range(len(l1)):
    counts=0
    for ele in range(i+1,len(l1)):
      if l1[i]<l1[ele]:
        counts=counts+1
    l2.append(counts)
  print(l1," \n")
  print(l2)
readlist()