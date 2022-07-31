#!/usr/bin/python3

# Definition for singly-linked list.
class ListNode:
	def __init__(self, val=0, next=None):
		self.val = val
		self.next = next

class Solution:
	'''
		Given a linked list, swap every two adjacent nodes and return its head. 
		You must solve the problem without modifying the values in the list's nodes 
		(i.e., only nodes themselves may be changed.)
	'''
	def __init__(self):
		self.head = None

	def append_node(self, val):
		new_node = ListNode(val)
		# check if head already exists
		if self.head:
			current = self.head
			# go to the end of linked list
			while current.next:
				current = current.next
			current.next = new_node
		else:
			self.head = new_node

	def append_nodes_from_list(self, val_list: list):
		for i in range(len(val_list)):
			self.append_node(val_list[i])

	def print_linked_list(self):
		current = self.head
		
		# if list is empty print []	
		if current == None:
			print('[]', end = ' ')
	
		while current:
			print(current.val, end = ' ')
			current = current.next
		print()

def swapPairs(head: ListNode):
	
	dummy_node = ListNode()
	current = ListNode()
	temp_first = ListNode()
	temp_second = ListNode()

	dummy_node.next = head
	current = dummy_node

	while current.next and current.next.next:
		
		temp_first = current.next
		temp_second = current.next.next

		temp_first.next = temp_second.next

		current.next = temp_second
		temp_second.next = temp_first

		current = current.next.next

	return dummy_node.next
	
# Test 1:

print('Test 1: ')

list1 = Solution()
list1_array = [1, 2, 3, 4]

list1.append_nodes_from_list(list1_array)

print('Starting list 1: ')
list1.print_linked_list()

list1.head = swapPairs(list1.head)

print('Swapped list 1: ')
list1.print_linked_list()

# Test 2:

print('\nTest 2: ')

list2 = Solution()
list2_array = []

list2.append_nodes_from_list(list2_array)

print('Starting list 2: ')
list2.print_linked_list()

list2.head = swapPairs(list2.head)

print('Swapped list 2: ')
list2.print_linked_list()

# Test 3:

print('\nTest 3: ')

list3 = Solution()
list3_array = [1]

list3.append_nodes_from_list(list3_array)

print('Starting list 3: ')
list3.print_linked_list()

list3.head = swapPairs(list3.head)

print('Swapped list 3: ')
list3.print_linked_list()
