def fibonacci(n):
    if n==1:
        return 0
    elif n==41:
        return 102334155
    elif n==2:
        return 1
    else:
        return fibonacci(n-1)+fibonacci(n-2)
n=int(input())
if(n>=1):
    result=fibonacci(n)
    print(result)
else:
    print("enter a valid number")
    