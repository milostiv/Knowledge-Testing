import time

# Definition of a singly-linked list.
class ListNode:
    def __init__(self, val = 0, next = None):
        self.val = val
        self.next = next

# Linked List class with a single head node.
class LinkedList:
    def __init__(self):
        self.head = None

    def insert_node(self, val):
        new_node = ListNode(val)
        # check if head already exists
        if(self.head):
            current = self.head 
            # go to the end of linked list
            while(current.next):
                current = current.next
            current.next = new_node
        else:
            self.head = new_node

    def insert_node_from_list(self, val: list):
        for i in range(len(val)):
            self.insert_node(val[i]) 

    def printLinkedList(self):
        current = self.head
        while(current):
            print(current.val, end = ' ')
            current = current.next
        print()

class Solution:
    """ 
    You are given two non-empty linked lists representing two non-negative integers. The digits are stored in reverse order, 
    and each of their nodes contains a single digit. Add the two numbers and return the sum as a linked list.
    You may assume the two numbers do not contain any leading zero, except the number 0 itself.
    """
    def __init__(self, l1: LinkedList, l2: LinkedList):
        self.l1 = l1
        self.l2 = l2
        self.sol = LinkedList()
        self.sol_num = 0
    
    def form_number_from_list(self, listIndex: int):
        if(listIndex == 2):
            current = self.l2.head
        else:
            current = self.l1.head
        mul = 1
        tmp = 0 
        while(current):
            tmp += current.val * mul
            mul *= 10
            current = current.next 
        return tmp
         
    def add_two_numbers(self): # changed from leetCode version 
        tmp = self.form_number_from_list(1) + self.form_number_from_list(2)
        self.sol_num = tmp
        while(tmp != 0):
            self.sol.insert_node(tmp % 10)
            tmp //= 10
        self.sol 

    def test_function(self, sol_num: int, test_num: int):
        start_time = time.time()
        self.add_two_numbers()                
        end_time = time.time()
        if(self.sol_num == sol_num):
            print('\nTEST' + str(test_num) + ': PASSED IN ' + '{:.2f}us'.format((end_time - start_time) * 1000000))
        else:
            print('\nTEST FAILED')
 
# Test 1

l1 = LinkedList()
tmp_list = [2, 4, 3]
l1.insert_node_from_list(tmp_list)

l2 = LinkedList()
tmp_list = [5, 6, 4] 
l2.insert_node_from_list(tmp_list)

s = Solution(l1, l2)
s.test_function(807, 1)

# Test 2

l1 = LinkedList()
l1.insert_node(0)

l2 = LinkedList()
l2.insert_node(0)

s = Solution(l1, l2)
s.test_function(0, 2)

# Test 3
l1 = LinkedList()
tmp_list = [9, 9, 9, 9, 9, 9, 9]
l1.insert_node_from_list(tmp_list)

l2 = LinkedList()
tmp_list = [9, 9, 9, 9]
l2.insert_node_from_list(tmp_list)

s = Solution(l1, l2)
s.test_function(10009998, 3)
