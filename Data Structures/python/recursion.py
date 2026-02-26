def factorial(n):
	if n == 0:
		return 1
	return n * factorial(n - 1)
print(factorial(10))

def fibonacci(n):
	if n <= 1:
		return 1
	return fibonacci(n - 1) + fibonacci(n - 2)
print(fibonacci(5))
#%timeit fib(6)

def fib(n,a = 0 , b = 1):
	if n == 0:
		return a
	return fib(n - 1, b, a + b)

print(fib(10))

def sum_list_recursive(l):
	if len(l) == 0: return 0
	return l[0] + sum_list_recursive(l[1:])

l = [1,2,3,4,5]
print(sum_list_recursive(l))
