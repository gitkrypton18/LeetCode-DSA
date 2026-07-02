class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if (head == NULL) return head;

        ListNode* dummy = new ListNode(-1);
        dummy->next = head;

        ListNode* prev = dummy;
        ListNode* temp = head;
        ListNode* nextNode;

        while (temp != NULL) {

            nextNode = temp->next;

            // Skip all duplicates of temp
            while (nextNode != NULL && nextNode->val == temp->val) {
                nextNode = nextNode->next;
            }

            // No duplicates
            if (temp->next == nextNode) {
                prev = temp;
            }
            // Duplicates found
            else {
                prev->next = nextNode;
            }

            temp = nextNode;
        }

        return dummy->next;
    }
};