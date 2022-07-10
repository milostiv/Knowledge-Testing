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
		
		# if list is empty print []	
		if current == None:
			print('[]', end = ' ')
	
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

def mergeKLists(lists):

	sol = Solution()
	temp = Solution()
	list_size = len(lists)
	
	# check if list is empty
	if list_size == 0:	
		return sol
	# check if all the rows in the list are empty
	else: 						
		all_rows_empty = True
		for row in lists:
			if len(row) != 0:
				all_rows_empty = False
		
		if all_rows_empty:
			return sol
		
	sol.append_nodes_from_list(lists[0])

	if list_size > 1:
		for i in range(1, list_size):
			temp.append_nodes_from_list(lists[i])
			sol.head = mergeTwoLists(sol.head, temp.head)
			temp.head = None

	return sol
		
sol = Solution()

# Test 1

element_lists1 = [[1, 4, 5],[1, 3, 4],[2, 6]]

sol = mergeKLists(element_lists1)
print('Test 1:')
sol.print_linked_list()
sol.head = None

# Test 2

element_lists2 = []

sol = mergeKLists(element_lists2)
print('Test 2:')
sol.print_linked_list()
sol.head = None

# Test 3

element_lists3 = [[]]

sol = mergeKLists(element_lists3)
print('Test 3:')
sol.print_linked_list()
sol.head = None
