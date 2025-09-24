# check given alphabet is vowel r not
ch=(input("enter a character\n"))
vowels=["a","e","i","o","u"]
for i in vowels:
    if ch.lower()==i:
        print(ch,"is a vowel")
        break
else:
    print(ch,"is a consonant")
