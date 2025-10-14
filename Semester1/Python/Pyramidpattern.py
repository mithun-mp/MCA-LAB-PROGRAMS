#DAY-2
# program for print pyramid pattern
n=int(input("enter the length of pyramid : "))
width=2*n-1
for i in range(n+1):
  star="*"*(2*i-1)
  print(star.center(width))

