/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        // Create a dummy head to simplify edge cases and track the start of the result list
        ListNode* dummyhead = new ListNode(0);
        ListNode* current = dummyhead; // Pointer to build the new list
        int carry = 0; // Initialize carry for digits that sum to 10 or more

        // Iterate while there are still nodes in l1, l2, or a carry remains
        while (l1 != NULL || l2 != NULL || carry != 0) 
        {
            // Get the current values from l1 and l2; if null, use 0
            int x = l1 ? l1->val : 0;
            int y = l2 ? l2->val : 0;

            // Calculate the sum of the current digits and the carry
            int sum = carry + x + y;

            // Update the carry (sum / 10 determines the carry for the next digit)
            carry = sum / 10;

            // Create a new node with the digit value (sum % 10) and link it
            current->next = new ListNode(sum % 10);

            // Move to the next node in the result list
            current = current->next;

            // Move to the next nodes in l1 and l2 (or null if already at the end)
            l1 = l1 ? l1->next : nullptr;
            l2 = l2 ? l2->next : nullptr;
        }

        // Skip the dummy head and get the actual result list
        ListNode* result = dummyhead->next;

        // Free the memory for the dummy head node
        delete dummyhead;

        // Return the resulting linked list
        return result;
    }
};

