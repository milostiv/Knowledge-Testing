#!/usr/bin/python3

class ListNode:
	def __init__(self, val=0, next=None):
		self.val = val
		self.next = next

class Solution:
	'''
	You are given an array of k linked-lists lists, each linked-list is sorted in ascending order.

	Merge all the linked-lists into one sorted linked-list and return it.
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
		while current:
			print(current.val, end = ' ')
			current = current.next
		print()

def mergeTwoLists(list1: ListNode, list2: ListNode) -> ListNode:				
	head = temp = ListNode()

	while list1 or list2:	
		# if one of the lists is empty
		if list1 and not list2:
			while list1:
				temp.next = ListNode(list1.val)
				list1 = list1.next	
			break
		if list2 and not list1:	
			while list2:
				temp.next = ListNode(list2.val)
				list2 = list2.next	
			break

		if list1.val <= list2.val:
			temp.next = ListNode(list1.val)
			list1 = list1.next
		else:
			temp.next = ListNode(list2.val)
			list2 = list2.next
	
		# advance the pointer
		temp = temp.next 

	return head.next

def mergeKLists(self, lists):

	pass


