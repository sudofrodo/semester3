import time
import matplotlib
matplotlib.use('TkAgg')
import matplotlib.pyplot as plt

def fib1(n):
	if  n <= 1:
	    return 1
	else:
	    return fib1(n-2) + fib1(n-1)

def fib2(n):
	a = 1
	b = 1
	for i in range(n):
	    a, b = b, a + b

	return a

def compute_times(fn, limit):
	l = []
	for i in range(limit):
	    start_time = int(round(time.time() * 1000))
	    fn(i)
	    end_time = int(round(time.time() * 1000))
	    time_taken = end_time - start_time
	    l.append(time_taken)

	return l

limit = 35
fib1_times = compute_times(fib1,limit)
fib2_times = compute_times(fib2,limit)

print("Fib1 times")
print(fib1_times)
print("Fib2 times")
print(fib2_times)

plt.figure()
plt.xlabel('fib(n)')
plt.ylabel('time (ms)')
plt.plot(fib1_times)
plt.plot(fib2_times)
#plt.show()
plt.savefig('limit35.png')
