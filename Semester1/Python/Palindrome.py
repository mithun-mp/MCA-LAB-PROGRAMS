# check whether a string is palindrome or not
string=input("enter a string ")
string=string.lower()
if string==string[::-1]:
    print(string,"is a palindrome")
else:
    print(string,"is not a palindrome")


