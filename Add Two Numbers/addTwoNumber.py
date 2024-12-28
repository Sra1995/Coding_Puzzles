# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def addTwoNumbers(self, l1: Optional[ListNode], l2: Optional[ListNode]) -> Optional[ListNode]:
        dummy = ListNode(0)  # Create a dummy node to simplify the result list
        current = dummy  # Pointer to build the result list

        carry = 0  # Initialize carry for the sum

        # Iterate as long as there are nodes in l1 or l2, or a carry to process
        while l1 or l2 or carry:
            # Get the current values from l1 and l2, or 0 if the list is exhausted
            x = l1.val if l1 else 0
            y = l2.val if l2 else 0

            # Calculate the sum of the current digits and the carry
            val = x + y + carry
            carry = val // 10  # Update the carry for the next iteration
            val = val % 10  # Get the digit for the current node

            # Add the digit as a new node in the result list
            current.next = ListNode(val)
            current = current.next  # Move the pointer forward

            # Advance the l1 and l2 pointers if there are more nodes
            l1 = l1.next if l1 else None
            l2 = l2.next if l2 else None

        # Return the next node of the dummy, which is the head of the result list
        return dummy.next
