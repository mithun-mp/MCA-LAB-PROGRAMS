import re
def check_string(string):
    pattern = r'^a.*a$'
    if re.match(pattern, string.lower()):
        return True
    else:
        return False
n=int(input("enter the limit"))
string=[]
for i in range(n):
  string.append(input())
for i in string:
  if check_string(i):
    print(i)


