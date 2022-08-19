#!/usr/bin/python

class Solution:
	''' 
		Given two integers dividend and divisor, divide two integers without using multiplication, division, and mod operator.
		The integer division should truncate toward zero, which means losing its fractional part. 
		For example, 8.345 would be truncated to 8, and -2.7335 would be truncated to -2.
		Return the quotient after dividing dividend by divisor.
	'''
	def divide(self, dividend: int, divisor: int) -> int:
		
		quotient = 0
		temp_divisor = 0
		sign = 1
		both_positive = divisor > 0 and dividend > 0
		both_negative = divisor < 0 and dividend < 0	

		if abs(divisor) > abs(dividend):
			return 0;

		if (both_positive or both_negative) != True:
			both_negative = True
			sign = -1

		while abs(temp_divisor) < abs(dividend):

			if both_positive:
				temp_divisor += divisor
	
			if both_negative:
				temp_divisor -= divisor

			quotient += 1

		return (quotient - 1) *sign

s = Solution()

# Test 1:

dividend1 = 10;
divisor1 = 3;

quotient1 = s.divide(dividend1, divisor1)

print('Test 1 quotient: ' + str(quotient1))

# Test 2:

dividend2 = 7;
divisor2 = -3;

quotient2 = s.divide(dividend2, divisor2)

print('Test 2 quotient: ' + str(quotient2))
