#!/usr/bin/python

# Definition for singly-linked list.
class ListNode:
	def __init__(self, val=0, next=None):
		self.val = val
		self.next = next

class Solution:
	'''
		Given the head of a singly linked list and two integers left and right where left <= right, 
		reverse the nodes of the list from position left to position right, and return the reversed list.
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

	def reverseBetween(self, head: ListNode, left: int, right: int) -> ListNode:
	
		counter = 1
	
		# check if linked list is empty	
		if self.head == None:
			return self.head

		curr = self.head

		# check if linked list has only one element		
		while curr.next != None:
			counter += 1
			curr = curr.next

		if counter == 1:
			return head

		counter = 1
		curr = head

		# go to left element
		while counter < left:
			prev = curr
			curr = curr.next
			counter += 1

		start = prev
		prev = curr
		end = curr
		curr = curr.next
		next = None
	
		while counter < right:
			next = curr.next
			curr.next = prev
			prev = curr
			curr = next
			counter += 1

		if start:
			start.next = prev

		end.next = curr
	
		if start == None:
			return prev
		else:
			return head

# Test 1:

print('Test 1:\n')

list1 = Solution()
list1_array = [1, 2, 3, 4, 5]
left = 2
right = 4

list1.append_nodes_from_list(list1_array)

print('List 1 before reversing: ', end = ' ')
list1.print_linked_list()

list1.reverseBetween(list1.head, left, right)

print('List 1 after reversing: ', end = ' ')
list1.print_linked_list()

print()

# Test 2:

print('Test 2:\n')

list2 = Solution()
list2_array = 5
left = 1
right = 1

list2.append_node(list2_array)

print('List 2 before reversing: ', end = ' ')
list2.print_linked_list()

list2.reverseBetween(list1.head, left, right)

print('List 1 after reversing: ', end = ' ')
list2.print_linked_list()
