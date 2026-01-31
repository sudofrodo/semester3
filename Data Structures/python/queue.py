class Queue:
	def __init__(self):
		self.size = 5
		self.q = list(range(self.size))
		self.i = 0 #insertion index
		self.o = 0 #out index

		self.is_empty = True
		self.is_full = False

	def _inc(self,val):
		if val + 1 == self.size:
			return 0
		else:
			return val + 1

	def enqueue(self,val):
		if self.is_full:
			raise IndexError("Queue full. Cannot enqueue")
		self.q[self.i] = val
		self.i = self._inc(self.i);
		if self.i == self.o:
			self.is_full = True
		self.is_empty = False

	def dequeue(self):
		if self.is_empty:
			raise IndexError("Queue empty. Cannot dequeue")
		ret = self.q[self.o]
		self.o = self._inc(self.o)
		if self.o == self.i:
			self.is_empty = True
		self.is_full = False
		return ret

	def __str__(self):
		return str(self.q) + ", in: " + str(self.i) + ", out: " + str(self.o)

q = Queue()
q.enqueue(10)
q.enqueue(12)
q.enqueue(14)
q.enqueue(16)
q.enqueue(18)
#q.enqueue(20)
print(q)

print(q.dequeue())
print(q.dequeue())
print(q.dequeue())
print(q.dequeue())
print(q.dequeue())
print(q)
