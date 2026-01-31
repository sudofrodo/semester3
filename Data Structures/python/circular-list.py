class Node:
	def __init__(self,val):
		self.val = val
		self.next = None

class Circly:
	def __init__(self):
		self.head = None

	def __str__(self):
		ret_str = '['
		temp = self.head
		while temp is not None:
			ret_str += str(temp.val) + ', '
			temp = temp.next
			if temp == self.head:
				break
		ret_str = ret_str.rstrip(', ')
		ret_str += ']'
		return ret_str

	def _get_last(self):
		if self.head is None:
			return None
		temp = self.head.next
		while temp.next != self.head:
			temp = temp.next
		return temp

	def insert(self,index,val):
		new_node = Node(val)
		last = self._get_last()
		if self.head is None and index > 0:
			raise IndexError("Empty List")
		if index == 0:
			new_node.next = self.head
			self.head = new_node
			if last is None:
				self.head.next = self.head
			else:
				last.next = new_node
			return
		temp = self.head
		counter = 0
		while temp is not None and counter < index:
			prev = temp
			temp = temp.next
			counter += 1
		prev.next = new_node
		new_node.next = temp

	def remove(self,val):
		if self.head is None:
			return
		temp = self.head
		last = self._get_last()
		if temp.val == val:
			if last == self.head: #if only one node
				self.head = None
			else:
				self.head = temp.next
			return
		prev = temp
		temp = temp.next
		while temp != self.head:
			if temp.val == val:
				break
			prev = temp
			temp = temp.next
		if temp == self.head: #value not found
			return
		prev.next = temp.next

	def push(self,val):
		self.insert(self.len(),val)

	def pop(self):
		val = self._get_last().val
		self.remove(val)
		return val 

	def len(self):
		temp = self.head.next
		counter = 1
		while temp != self.head:
			temp = temp.next
			counter += 1
		return counter

	def get(self,index):
		temp = self.head
		counter = 0
		while counter < index:
			temp = temp.next
			counter += 1
		return temp.val


c = Circly()
c.insert(0,1)
c.insert(0,2)
c.insert(1,5)
c.insert(10,15)
print("====Testing Functions====")
print("Insert")
print(c)

c.push(30)
c.push(50)
print("Push")
print(c)

print("Pop")
print(c.pop())
print(c)

print("Remove")
c.remove(1)
c.remove(50)
c.remove(200)
print(c)

print("Get")
print(c.get(0))
print(c.get(3))
print(c.get(10))

print("len")
print(c)
print(c.len())

print("Get Last")
print(c._get_last().val)

print("Ring test")
print(c._get_last().next == c.head)

