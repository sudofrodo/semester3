class Node:
	def __init__(self, val=None):
		self.val = val
		self.next = None

class LinkedList:
	def __init__(self):
		self.head = None

	def push(self,val):
		new_node = Node(val)
		if self.head is None:
			self.head = new_node
			return
		last = self.head
		while last.next is not None: #loop till the node whose next is null is found.
			last = last.next
		last.next = new_node

	def pop(self):
		if self.head is None:
			raise Exception("Empty List")
		if self.head.next is None:
			val = self.head.val
			self.head = None
			return val
		last = self.head
		while last.next is not None:
			prev = last
			last = last.next
		val = last.val
		prev.next = None
		return val

	def insert(self,index,val):
		new_node = Node(val)
		if index == 0:
			new_node.next = self.head
			self.head = new_node
			return
		temp = self.head
		counter = 0
		while temp is not None and counter < index: #when we will exit the loop , the temp will be standing on the given index
			prev = temp
			temp = temp.next
			counter += 1
		prev.next = new_node
		new_node.next = temp

	def remove(self,val):
		temp = self.head
		if temp is not None:
			if temp.val == val:
				self.head = temp.next
				return
		while temp is not None: #we see every element including last one
			if temp.val == val:
				break
			prev = temp
			temp = temp.next
		if temp is None: #value not found
			return
		prev.next = temp.next

	def get(self,index):
		if index == 0:
			return self.head.val
		temp = self.head
		counter = 0
		while temp is not None and counter < index:
			temp = temp.next
			counter += 1
		if temp is None:
			raise Exception("Invalid Index")
		return temp.val

	def size(self):
		counter = 0
		temp = self.head
		while temp is not None:
			temp = temp.next
			counter += 1
		return counter

	def __str__(self):
		temp = self.head
		if temp is None:
			return "Empty List"
		ret_str = '['
		while temp is not None:
			ret_str += str(temp.val) + ' ,'
			temp = temp.next
		ret_str = ret_str.rstrip(', ')
		ret_str += ']'
		return ret_str

	
l = LinkedList()
l.push(1)
l.push(2)
l.push(3)

l.insert(0,12)
l.insert(2,15)
l.insert(100,17)
# l.insert(-1,56) index will be less than counter , so condition is false and prev is undefined
print(l)

#l.remove(5)
#l.remove(12)
#l.remove(15)
#print(l)


#print(l.get(0))
#print(l.get(2))
#print(l.get(100))
print(l.size())
