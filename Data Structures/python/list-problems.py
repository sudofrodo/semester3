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

	def get_last(self):
		last = self.head
		while last.next is not None: #loop till the node whose next is null is found.
			last = last.next
		return last

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

def get_max(list):
	max = 0
	temp = list.head
	while temp is not None:
		if temp.val > max:
			max = temp.val
		temp = temp.next
	return max


print(get_max(l))

def get_min(list):
	min = float('inf')
	temp = list.head
	while temp is not None:
		if temp.val < min:
			min = temp.val
		temp = temp.next
	return min

print(get_min(l))

def remove_min(list):
	min = get_min(list)
	list.remove(min)

remove_min(l)
print(l)

def find_three_max(list):
	h1=h2=h3 = 0
	for val in list:
		if val > h1:
			h3 = h2
			h2 = h1
			h1 = val
		elif val > h2:
			h3 = h2
			h2 = val
		elif val > h3:
			h3 = val
	return (h1,h2,h3)

def reverse_list(list):
	if list.head is None: return
	if list.head.next is None: return

	new_head = list.get_last()
	processing = new_head

	for i in range(list.size() - 1):
		temp = list.head
		while temp.next != processing:
			temp = temp.next
		processing.next = temp
		processing = temp
	list.head.next = None
	list.head = new_head

def get_counts(self):
	from collections import Counter
	cnt = Counter()
	temp = self.head
	while temp is not None:
		cnt[temp.val] += 1
		temp = temp.next
	return cnt.most_common()

def append_list(l1,l2):
	if l1.head is None:
		l1.head = l2.head
	last = l1.get_last()
	last.next = l2.head
	return l1

from math import sqrt
def some_op(list,fn):
	temp = list.head
	while temp is not None:
		print(fn(temp.val))
		temp = temp.next


l2 = [1,2,3,4,5,6,7,10,8]
print(find_three_max(l2))

reverse_list(l)
print(l)

l.push(15)
print(get_counts(l)[0])

l3 = LinkedList()
l3.push(19)
l3.push(23)
l3.push(29) 

print(append_list(l,l3))

some_op(l,sqrt)
