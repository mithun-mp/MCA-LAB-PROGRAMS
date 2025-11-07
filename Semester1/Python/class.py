class Complex: 
def __init__(self, a, b): 
self.a = a 
self.b = b 
def __add__(self, N2): 
N3 Complex (0, 0) 
= 
N3.a = self.a + N2.a 
N3.b = self.b + N2.b 
return N3 
def __mul__(self, N2): 
= 
N3 Complex (0, 0) 
N3.a = self.a * N2.a self.b N2.b 
- 
N3.b = self.a * N2.b + self.b * N2.a 
return N3 
def __str__(self): 
return f"{self.a} + {self.b}i" 
a = int(input()) 
b 
= 
int (input()) 
|| 
c = int(input()) 
d 
= 
int (input()) 
= 
c1 Complex (a, b) 
c2 = Complex (c, d) 
c3 = c1 + c2 
c4 = c1 * c2 
print (c1) 
print (c2) 
print(c3) 
print (c4) 
