import re
def check_ip(ip):
    octete = r'([0-9]|[1-9][0-9]|1[0-9][0-9]|2[0-4][0-9]|25[0-5])'
    ip_pattern = fr'^{octete}\.{octete}\.{octete}\.{octete}$'
    if re.match(ip_pattern, ip):
        return True
    else:
        return False
ip = input("Enter an IP address: ")
if check_ip(ip):
    print("Valid")
else:
  print("Invalid")
