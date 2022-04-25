#!/usr/bin/python3

# Definition for singly-linked list.
class ListNode:
	def __init__(self, val=0, next=None):
		self.val = val
		self.next = next

class Solution:	
	'''
	You are given the heads of two sorted linked lists list1 and list2.

	Merge the two lists in a one sorted list. The list should be made by splicing together the nodes of the first two lists.

	Return the head of the merged linked list.
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
				
list1 = Solution()
list2 = Solution()

# Test 1

print('Test 1:')
print()

element_list1 = [1, 2, 4]
element_list2 = [1, 3, 4]

list1.append_nodes_from_list(element_list1)
list2.append_nodes_from_list(element_list2)

print('Linked list 1:', end = ' ')
list1.print_linked_list()
print('Linked list 2:', end = ' ')
list2.print_linked_list()

sol = Solution()
sol.head = mergeTwoLists(list1.head, list2.head)

print('Merged list:', end = ' ')
sol.print_linked_list()
