#!/usr/bin/python3

class Solution:

	def myPow(self, x: float, n: int):
	
		negativePow = False
		
		if n < 0:
			negativePow = True
			n *= -1

		if n == 0:
			return 1
		elif n % 2 == 0:
			temp = self.myPow(x, int(n/2)) * self.myPow(x, int(n/2))
		else:
			temp = x * self.myPow(x, int(n/2)) * self.myPow(x, int(n/2))

		if negativePow:
			temp = 1 / temp
		
		return temp
	
sol = Solution()

# Test 1 

x = 2.0
n = 10

print("Test 1: " + str(sol.myPow(x, n)))

# Test 2

x = 2.1
n = 3

print("Test 2: " + str(sol.myPow(x, n)))

# Test 3

x = 2.0
n = -2

print("Test 3: " + str(sol.myPow(x, n)))
