#!/usr/bin/python3

# Definition for singly-linked list.
class ListNode:
	def __init__(self, val=0, next=None):
		self.val = val
		self.next = next	

class LinkedList:
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

class Solution:
	'''
	Given the head of a linked list, remove the nth node from the end of the list and return its head.
	'''
	def removeNthFromEnd(self, head: ListNode, n: int) -> ListNode:
		pass

# Test 1

element_list1 = [1, 2, 3, 4, 5]
element_list_size = len(element_list1)

list1 = LinkedList()
list1.insert_node_from_list(element_list1)

list1.print_LinkedList()
