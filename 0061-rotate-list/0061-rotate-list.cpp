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
    ListNode* LastNode(ListNode* head, int a) {
        ListNode* newLastNode = head;

        while (newLastNode != nullptr && a > 1) {
            newLastNode = newLastNode->next;
            a--;
        }

        return newLastNode;
    }

    ListNode* rotateRight(ListNode* head, int k) {

        if(head == nullptr || head->next == nullptr || k == 0)
            return head;

        ListNode* tail = head;
        int len = 1;

        while(tail->next != nullptr){
            len++;
            tail = tail->next;
        }

        k %= len;

        if(k == 0)
            return head;

        tail->next = head;

        ListNode* newLastNode = LastNode(head, len - k);

        head = newLastNode->next;
        newLastNode->next = nullptr;

        return head;
    }
};