#!/usr/bin/python3

# Definition for singly-linked list.
class ListNode:
	def __init__(self, val=0, next=None):
		self.val = val
		self.next = next

class Solution:
	'''
	Given the head of a singly linked list, reverse the list, and return the reversed list.
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

	def reverseList(self) -> ListNode:
	
		# check if linked list is empty	
		if self.head == None:
			return self.head

		curr = self.head
		prev = None		
	
		while curr is not None:
			next = curr.next
			curr.next = prev
			prev = curr
			curr = next

		self.head = prev
	
		return self.head

# Test 1:

print('Test 1:')

list1 = Solution()
list1_array = [1, 2, 3, 4, 5]

list1.append_nodes_from_list(list1_array)

print('List 1 before reversing: ', end = ' ')
list1.print_linked_list()

list1.reverseList()

print('List 1 after reversing: ', end = ' ')
list1.print_linked_list()

# Test 2:

print('Test 2:')

list2 = Solution()
list2_array = [1, 2]

list2.append_nodes_from_list(list2_array)

print('List 2 before reversing: ', end = ' ')
list2.print_linked_list()

list2.reverseList()

print('List 2 after reversing: ', end = ' ')
list2.print_linked_list()

# Test 2:

print('Test 2:')

list3 = Solution()

print('List 3 before reversing: ', end = ' ')
list3.print_linked_list()

list3.reverseList()

print('List 3 after reversing: ', end = ' ')
list3.print_linked_list()
