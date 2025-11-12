import re
def is_valid_pan(pan_number):
    pattern = r'^[A-Z]{5}[0-9]{4}[A-Z]$'
    if re.match(pattern, pan_number):
        return True
    else:
        return False
pan_number = input("Enter a PAN number: ")
if is_valid_pan(pan_number):
    print("Valid")
else:
    print("Invalid")
