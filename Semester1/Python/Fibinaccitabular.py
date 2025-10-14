def fib_t(n):
    if n==1:
        return 0
    elif n==2:
        return 1
    fib = [0]*(n+1)
    fib[1]=0
    fib[2]=1
    for i in range(3, n+1):
        fib[i]=fib[i-1]+fib[i-2]
    return fib[n]
n=int(input())
if n>=1:
    print(fib_t(n))
else:
    print("enter valid number")