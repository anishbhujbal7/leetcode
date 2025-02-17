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
    ListNode* reverseList(ListNode* head) {
    ListNode* prev = nullptr;   // Step 1: Initialize prev pointer
    ListNode* curr = head;      // Step 2: Initialize curr pointer

    while (curr) {              // Step 3: Iterate until curr is NULL
        ListNode* next = curr->next; // Step 4: Store next node
        curr->next = prev;      // Step 5: Reverse the link
        prev = curr;            // Step 6: Move prev forward
        curr = next;            // Step 7: Move curr forward
    }

    return prev; 
    }
};
