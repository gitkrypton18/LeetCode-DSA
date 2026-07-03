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
    ListNode* findKNode(ListNode* temp, int k) {
        while (--k && temp != nullptr) {
            temp = temp->next;
        }

        return temp;
    }
    ListNode* reverseLL(ListNode* head) {
        ListNode* prev = nullptr;
        ListNode* curr = head;
        while (curr != nullptr) {
            ListNode* temp = curr->next; // Store the next node
            curr->next = prev;           // Reverse the current node's pointer
            prev = curr;                 // Move prev to current node
            curr = temp;                 // Move to the next node
        }
        return prev; // New head of the reversed list
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* temp = head;
        ListNode* prevNode = NULL;
        ListNode* nextNode = NULL;
        ListNode* KNode = NULL;

        while (temp != NULL) {
            KNode = findKNode(temp, k);
            if (KNode == NULL) {
                if (prevNode)
                    prevNode->next = temp; // kth node is last node
                break;
            }
            nextNode = KNode->next; // preserve
            KNode->next = NULL;     // make the LL small
            reverseLL(temp);
            if (temp == head)
                head = KNode;
            else
                prevNode->next = KNode;
            prevNode = temp;
            temp = nextNode;
        }
        return head;
    }
};