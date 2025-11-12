import re
def check_phone_number(phone_numb):
    pattern = r'^[9]{1}[0-9]{9}$'
    if re.match(pattern, phone_numb):
        return True
    else:
        return False
phone_numb = input("Enter a phone number: ")
if check_phone_number(phone_numb):
    print("Valid")
else:
    print("Invalid ")
