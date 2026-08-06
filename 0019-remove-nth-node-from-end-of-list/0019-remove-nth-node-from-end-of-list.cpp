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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
  
       ListNode* slow = head;
        ListNode* fast = head;

        // Advance fast pointer n steps
        for (int i = 0; i < n; i++) 
            fast = fast->next;
        
        // If fast reached NULL, we need to remove the head node
        if (fast == nullptr) {
            ListNode* newHead = head->next;
            delete head; // Free memory
            return newHead;
        }

        // Move fast until it reaches the LAST node (fast->next == nullptr)
        while (fast->next != nullptr) {
            slow = slow->next;
            fast = fast->next;
        }

        // Delete slow->next
        ListNode* delNode = slow->next;
        slow->next = slow->next->next;
        delete delNode;

        return head;
    }

};
