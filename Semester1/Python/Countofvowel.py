# count the number of alphabets in a string
ch=(input("enter a character : "))
vowels=["a","e","i","o","u"]
count=0
for j in ch:
  for i in vowels:
    if j.lower()==i:
        count=count+1
        break
print("there are ",count," number of vowels in given string")