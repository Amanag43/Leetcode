class Solution {
public:
    ListNode* getIntersectionNode(ListNode* headA, ListNode* headB) {
        
        int lenA = 0, lenB = 0;
        
        ListNode* tempA = headA;
        ListNode* tempB = headB;

        // Find length of A
        while (tempA != nullptr) {
            lenA++;
            tempA = tempA->next;
        }

        // Find length of B
        while (tempB != nullptr) {
            lenB++;
            tempB = tempB->next;
        }

        // Move the longer list ahead
        while (lenA > lenB) {
            headA = headA->next;
            lenA--;
        }

        while (lenB > lenA) {
            headB = headB->next;
            lenB--;
        }

        // Now both are at the same distance from intersection
        while (headA != headB) {
            headA = headA->next;
            headB = headB->next;
        }

        return headA;
    }
};
