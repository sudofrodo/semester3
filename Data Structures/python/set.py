set_a = {1,2,3,4}
set_b = {4,5,6,7}

#all valid set operations can be performed , e.g union, difference , intersection etc

a = 10
b = 4
constraints = { a > 2, a < 10 , b > 0 , b < 10}
if all(constraints):
	print("All constraints satisfied")
if any(constraints):
	print("Some constraints satisfied")

#quantifiers
print(all([x  % 2 == 0 for x in set_a]))

def is_odd(x):
	return x % 2 != 0

print(any([ is_odd(x) for x in set_b]))
