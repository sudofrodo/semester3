class Stack:
	def __init__(self):
		self.l = []

	def push(self,val):
		self.l.append(val)

	def pop(self):
		return self.l.pop()

	def peek(self):
		return self.l[-1]

	def __str__(self):
		return self.l.__str__()
s = Stack()
s.push(1)
s.push(2)
s.push(3)

print(s)
print(s.pop())
print(s.peek())
print(s.pop())

