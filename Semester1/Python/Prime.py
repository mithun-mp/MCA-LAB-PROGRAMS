# check whether a number is prime or not
num=int(input("enter a number"))
prime=0
i=2
for i in range(2,num):
  if num%i==0:
    prime=prime+1
if prime>0:
  print(num,"is not a prime number")
else:
  print(num,"is a prime number")

