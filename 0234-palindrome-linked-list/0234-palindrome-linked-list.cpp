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
        ListNode* prev = nullptr;
        ListNode* curr = head;
        while (curr != nullptr) {
            ListNode* temp = curr->next; // Store the next node
            curr->next = prev;            // Reverse the current node's pointer
            prev = curr;                  // Move prev to current node
            curr = temp;                  // Move to the next node
        }
        return prev; // New head of the reversed list
    }
    bool isPalindrome(ListNode* head) {
        if(head==nullptr||head->next==nullptr) return true;
        ListNode* slow=head;
        ListNode* fast=head;
        while(fast->next != nullptr && fast->next->next != nullptr){
            slow=slow->next,fast=fast->next->next;
        }
        // now slow is at the mid of the linkedlist even legth first mid
        // ccalling rrevers
        
        ListNode* first=head;
        ListNode* newHead=reverseList(slow->next);
        ListNode* second=newHead;

        while(second!=NULL){
            if(first->val!=second->val) return false;
            first=first->next,second=second->next;
        }
        reverseList(newHead);
        return true;
    }
};