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

    def insertNode(self, val):
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
        self.solNum = 0
    
    def formNumberFromList(self, listIndex: int):
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
         
    def addTwoNumbers(self):
        tmp = self.formNumberFromList(1) + self.formNumberFromList(2)
        self.solNum = tmp
        while(tmp != 0):
            self.sol.insertNode(tmp % 10)
            tmp //= 10
        self.sol 

    def testFunction(self, solNum: int, testNum: int):
        start_time = time.time()
        self.addTwoNumbers()                
        end_time = time.time()
        if(self.solNum == solNum):
            print('TEST' + str(testNum) + ': PASSED IN ' + '{:.2f}us'.format((end_time - start_time) * 1000000))
        else:
            print('TEST FAILED')
 
# Test 1
print()
l1 = LinkedList()
l1.insertNode(2)
l1.insertNode(4)
l1.insertNode(3)

l2 = LinkedList()
l2.insertNode(5)
l2.insertNode(6)
l2.insertNode(4)

s = Solution(l1, l2)
s.testFunction(807, 1)

# Test 2
print()
l1 = LinkedList()
l1.insertNode(0)

l2 = LinkedList()
l2.insertNode(0)

s = Solution(l1, l2)
s.testFunction(0, 2)

# Test 3
print()
l1 = LinkedList()
l1.insertNode(9)
l1.insertNode(9)
l1.insertNode(9)
l1.insertNode(9)
l1.insertNode(9)
l1.insertNode(9)
l1.insertNode(9)

l2 = LinkedList()
l2.insertNode(9)
l2.insertNode(9)
l2.insertNode(9)
l2.insertNode(9)

s = Solution(l1, l2)
s.testFunction(10009998, 3)
