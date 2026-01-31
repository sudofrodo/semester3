class Node:
	def __init__(self,val):
		self.val = val
		self.prev = None
		self.next = None

class Doubly:
	def __init__(self):
		self.head = None
	def __str__(self):
		#hex(id(None))
		ret_str = "[ "
		temp = self.head
		while temp is not None:
			ret_str += str(temp.val) + ', '
			temp = temp.next
		ret_str = ret_str.rstrip(', ')
		ret_str += ']'
		return ret_str

	def push(self,val):
		new_node = Node(val)
		if self.head is None:
			self.head = new_node
			return
		last = self.head
		while last.next is not None:
			last = last.next
		last.next = new_node
		new_node.prev = last

	def insert(self,index,val):
		new_node = Node(val)
		if self.head is not None:
			if index == 0:
				new_node.next = self.head
				self.head.prev = new_node
				self.head = new_node
				return

			temp = self.head
			counter = 0
			while temp is not None and counter < index:
				prev = temp
				temp = temp.next
				counter += 1

			prev.next = new_node
			new_node.prev = prev
			if temp is None:
				return
			new_node.next = temp
			temp.prev = new_node

		else:
			self.head = new_node

	def remove(self,val):
		temp = self.head
		if temp is None:
			raise Exception("Empty List")
		if temp.val == val:
			self.head = temp.next
			if self.head is not None:
				self.head.prev = None
			return
		while temp is not None:
			if temp.val == val:
				break
			prev = temp
			temp = temp.next
		if temp is None:
			return
		prev.next = temp.next
		if temp.next is not None:
			temp.next.prev = prev

d = Doubly()
d.push(1)
d.push(3)
d.push(4)

print(d)

d.insert(0,12)
d.insert(1,13)
d.insert(3,20)
d.insert(5,15)
d.insert(100,55)
print(d)


d2 = Doubly()
d2.insert(500,100)
d2.insert(0,10)
print(d2)

d.remove(12)
d.remove(500)
d.remove(3)
print(d)



	#	if index == 0:
	#		new_node.next = self.head
	#		if self.head is not None:
	#			self.head.prev = new_node
	#		self.head = new_node
	#		return
