def factorial(n):
    if n==0:
        print(0)
        print(1)
        return 1
    print(n)
    if n==1:
        print(1)
        return 1
    fact=n*(factorial(n-1))
    print(fact)
    return(fact)
n=int(input())
if 0<=n<=150:
    factorial(n)
else:
    print("enter a valid number")
    