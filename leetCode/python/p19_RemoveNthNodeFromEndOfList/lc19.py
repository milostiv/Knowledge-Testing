#!/usr/bin/python3

# Definition for singly-linked list.
class ListNode:
	def __init__(self, val=0, next=None):
		self.val = val
		self.next = next	

class LinkedList:	
	'''
	Given the head of a linked list, remove the nth node from the end of the list and return its head.
	'''
	def __init__(self):
		self.head = None

	def insert_node(self, val):
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

	def insert_node_from_list(self, val_list: list):
		for i in range(len(val_list)):
			self.insert_node(val_list[i])

	def print_LinkedList(self):
		current = self.head
		while current:
			print(current.val, end = ' ')
			current = current.next
		print()

	def removeNthFromEnd(self, head: ListNode, n: int) -> ListNode:
		list_size = 1
		foo = self.head
		bar = self.head
			
		# find the size of linked list
		while foo.next:
			list_size += 1
			foo = foo.next	
			
		if list_size == 1 and n == 1:
			print('Empty list!')		
			return head
		elif list_size == 1 and n > 1:
			print('\'n\' is greater than number of list elements!')
			return head

		foo = self.head

		for i in range(n):
			foo = foo.next

		while foo.next:
			foo = foo.next
			bar = bar.next

		bar.next = (bar.next).next

		return self.head
	
# Test 1
print('Test 1:')

element_list1 = [1, 2, 3, 4, 5]
element_list_size = len(element_list1)

list1 = LinkedList()
list1.insert_node_from_list(element_list1)

list1.print_LinkedList()

list1.removeNthFromEnd(list1, 2)

list1.print_LinkedList()

print()

# Test 2
print('Test 2:')

element_list2 = 1
element_list_size = 1

list2 = LinkedList()
list2.insert_node(element_list2)

list2.print_LinkedList()

list2.removeNthFromEnd(list2, 1)

print()

# Test 3 
print('Test 3:')

element_list3 = [1, 2]
element_list_size = len(element_list3)

list3 = LinkedList()
list3.insert_node_from_list(element_list3)

list3.print_LinkedList()

list3.removeNthFromEnd(list3, 1)

list3.print_LinkedList()	

print()
