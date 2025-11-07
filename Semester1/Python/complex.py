import math

# Base class
class Shape:
    def __init__(self, fillColor):
        self.fillcolor = fillColor

# Circle class
class Circle(Shape):
    def __init__(self, rad, fillColor):
        super().__init__(fillColor)
        self.rad = rad

    def area(self):
        return math.pi * self.rad ** 2

    def __lt__(self, other):
        return self.area() < other.area()

# Rectangle class
class Rectangle(Shape):
    def __init__(self, l, b, fillColor):
        super().__init__(fillColor)
        self.l = l
        self.b = b

    def area(self):
        return self.l * self.b

# Main program
if __name__ == '__main__':
    # Input for Circle 1
    rad1 = float(input("Enter radius of Circle 1: "))
    fillColor1 = input("Enter fill color of Circle 1: ")
    c1 = Circle(rad1, fillColor1)

    # Input for Rectangle
    length = float(input("Enter length of the Rectangle: "))
    breadth = float(input("Enter breadth of the Rectangle: "))
    fillColorRect = input("Enter fill color of the Rectangle: ")
    rect = Rectangle(length, breadth, fillColorRect)

    # Input for Circle 2
    rad2 = float(input("Enter radius of Circle 2: "))
    fillColor2 = input("Enter fill color of Circle 2: ")
    c2 = Circle(rad2, fillColor2)

    # Calculate and print areas
    print("\nArea of Circle 1:", c1.area())
    print("Area of Rectangle:", rect.area())
    print("Area of Circle 2:", c2.area())

    # Compare areas of Circle 1 and Circle 2
    print("Circle 1 has a smaller area than Circle 2:", c1 < c2)
