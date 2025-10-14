#Day-2
#check key in list exist or not
n=int(input("enter the limit"))
print("enter ",n,"elements")
l1=[]
for i in range(n):
  l1.append(int(input()))
key=int(input("enter the key"))
if key in l1:
  print(key,"is present in the list")
else:
  print(key,"is not present in the list")