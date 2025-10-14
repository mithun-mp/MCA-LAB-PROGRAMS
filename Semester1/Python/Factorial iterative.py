def factor(n):
    fact=1
    for i in range(1,n+1):
        if i<101:
            fact=fact*i
            print(fact)
        else:
            break
n=int(input())
if n<0:
    print("enter a positive number")
elif(n==0):
    print(1)
else:
    factor(n)