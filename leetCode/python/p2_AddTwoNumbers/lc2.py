import time

# Definition of a singly-linked list.
class ListNode:
    def __init__(self, val = 0, next = None):
        self.val = val
        self.next = next

# A Linked List class with a single head node.
class LinkedList:
    def __init__(self):
        self.head = None

    def insertLL(self, val):
        newNode = ListNode(val)
        # Check if head already exists
        if(self.head):
            current = self.head 
            # Go to the end of linked list
            while(current.next):
                current = current.next
            current.next = newNode
        else:
            self.head = newNode 

    def printLL(self):
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
    def formNumberFromList(l1: LinkedList) -> int:
        mul = 1
        sol = 0
        current = l1.head
        while(current):
            sol += current.val * mul
            mul *= 10
            current = current.next 
        return sol
         
    def addTwoNumbers(l1: LinkedList, l2: LinkedList) -> LinkedList:
        sol = LinkedList()
        solSum = Solution.formNumberFromList(l1) + Solution.formNumberFromList(l2)
        while(solSum != 0):
            sol.insertLL(solSum % 10)
            solSum = solSum // 10
        return sol 
    
# Test 1

l1 = LinkedList()
l1.insertLL(2)
l1.insertLL(4)
l1.insertLL(3)
l1.printLL()

print(Solution.formNumberFromList(l1))

l2 = LinkedList()
l2.insertLL(5)
l2.insertLL(6)
l2.insertLL(4)
l2.printLL()

sol = Solution.addTwoNumbers(l1, l2)
sol.printLL()
