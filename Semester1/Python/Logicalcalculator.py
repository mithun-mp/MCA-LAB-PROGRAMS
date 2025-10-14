#DAY-2
# program to do logical operation using bool input
while True:
  print("----Logical Operation----")
  print("1.AND\n2.OR\n3.NOT\n4.XOR\n5.EXIT")
  ch=int(input("enter your choice"))

  if ch==1:
    num1=bool(input("enter first number"))
    num2=bool(input("enter second number"))
    print("the result is",num1 and num2)
  elif ch==2:
    num1=bool(input("enter first number"))
    num2=bool(input("enter second number"))
    print("the result is",num1 or num2)
  elif ch==3:
    num=bool(input("enter the number"))
    print( not num)
  elif ch==4:
    num1=bool(input("enter first number"))
    num2=bool(input("enter second number"))
    print("the result is",num1 ^ num2)
  elif ch==5:
    break
  else:
    print("invalid choice")