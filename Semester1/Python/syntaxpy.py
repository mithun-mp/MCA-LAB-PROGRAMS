import re
def check_syntax(code):
  terms=code.strip()
  keyword=r'^(if|for|def|while)\b'
  colon=r':$'
  syntax=re.search(keyword,terms)
  if syntax:
    if not terms.endswith(':'):
      return f"Syntax error at {len(terms)}th position err1"
  else:
    if re.search(colon,terms):
      return f"Syntax error at {len(terms)}th position err4"
  return "Syntax verified successfully!"
print("Python Syntax Validator (Type EXIT/exit to stop)\n")
while(True):
  user_input=input("Enter python code : ")
  if user_input.lower()=="exit":
    break
  else:
      print(check_syntax(user_input))
