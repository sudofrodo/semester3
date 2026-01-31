def is_matched(string):
	opening = '({['
	closing = ')}]'
	mapping = dict(zip(opening,closing))
	stack = []
	for c in string:
		if c not in mapping.values() and c not in mapping.keys():
			continue
		if c in mapping:
			stack.append(mapping[c])
		elif len(stack) == 0 or c != stack.pop():
			return False
	return len(stack) == 0


string = "][]]]]p]"
print(is_matched(string))

s2 =' {[[]]{()}}'
print(is_matched(s2))
