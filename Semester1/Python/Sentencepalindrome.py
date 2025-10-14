# check a sentence is paliandrome or not
string=input("enter a sentence")
string=string.lower()
string=string.replace(" ","")
if string==string[::-1]:
    print(string,"is a paliandrome")
else:
    print(string,"is not a paliandrome")