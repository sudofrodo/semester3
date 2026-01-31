
#variable
x = 5

#function
def function(x):
	print("The value of x is : " , x)

def value(y):
	return(y + 2)

def abs(z):
	if z > 0 or z == 0:
	    return z
	else:
	    return -z 

#function call
function(4)

#for loop
for i in range(10):
	print(i)

#while loop
j = 10
while (j > 0):
	j = j - 1
	print(j)

#list
l = ["ali", "karim" , "haris"]
for s in l:
	print(s)
print(l)

#dictionary
d = {1 : "one",
     2 : "two",
    }

print(d[1])
print(d.items())

for k,v in d.items():
	print(k,v)

#tuple (immutable)
tuple(d.items())

#casting
list(d.keys())

#zipping
a = [1,2,3,4,5]
b = [6,7,8,9,10]

merged = list(zip(a,b))
print(merged)



















































