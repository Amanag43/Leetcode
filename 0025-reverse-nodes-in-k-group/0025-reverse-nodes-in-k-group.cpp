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
      ListNode* reverseKGroup(ListNode* head, int k) {

        ListNode* temp = head;
        ListNode* prevGroupTail = nullptr;
ListNode* newHead = nullptr;

        while (temp != nullptr) {

            // Count k nodes
            int cnt = 0;
            ListNode* check = temp;

            while (check != nullptr && cnt < k) {
                check = check->next;
                cnt++;
            }

            // Less than k nodes remain
            if (cnt < k){
                break;
        }
ListNode* groupStart = temp;
            ListNode* prev = nullptr;
            ListNode* curr = temp;
            for (int i = 0; i < k; i++) {
                ListNode* next = curr->next;
                curr->next = prev;
                prev = curr;
                curr = next;
            }
        if (newHead == nullptr)
    newHead = prev;
else
    prevGroupTail->next = prev;

groupStart->next = curr;

prevGroupTail = groupStart;
temp = curr;
        }


        return newHead;
    }
};