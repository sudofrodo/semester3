
# Classes and Objects

class Point:
	def __init__(self,x = 0 , y = 0):
		self.x = x
		self.y = y

	def __str__(self):
		return "[" + str(self.x) + "," + str(self.y) + "]"


	def temp():
		pass

p1 = Point()
print("p1x = " , p1.x)

p2 = Point(2,4)
print("p2y = " , p2.y)

print(p2)

# Aggregation

class Shape:
	def __init__(self,points):
		self.points = points

	def __str__(self):
		ret = ""
		for i in self.points:
			ret += str(i) + " - "

		return ret

p1 = Point(5,5)
p2 = Point(10,5)
p3 = Point(5,10)
p = [p1,p2,p3]

sh = Shape(p)
print(sh)

# we can add methods to the class even after it has been defined

def draw(self):
	print("Drawing")
Shape.draw = draw

sh.draw()

# Inheritance

class Triangle(Shape):
	pass

	def get_area(self):
		vertices = self.points
		n = len(vertices)
		a = 0.0
		for i in range(n):
			j = (i + 1) % n
			a += abs(vertices[i].x * vertices[j].y - vertices[j].x * vertices[i].y)
		return a / 2.0

t = Triangle(p)
t.draw()
print("Triangle Area: " , t.get_area())

# Accessing Parent Methods

class Rectangle:

	def __init__(self,length, width):
		self.length = length
		self.width = width

	def get_area(self):
		return self.width * self.length

	def __str__(self):
		return "Length : "  + str(self.length) + " Width : " + str(self.width)

rect = Rectangle(4,6)
print(rect)

class Square(Rectangle):

	def __init__(self,length):
		super().__init__(length,length)

	def __str__(self):
		return "Square : " + super().__str__()

	#there are no access modifiers in python but by convention the functions you want
	#to be treated as private , you start there name with underscore _foo

	def _test():
		return True

sq = Square(4)
print("Square Area : " , sq.get_area())
print(sq)
