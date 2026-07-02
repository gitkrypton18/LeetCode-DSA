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
    // Find the first middle node (for even-length lists)
    ListNode* middleNode(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head->next;

        while (fast != nullptr && fast->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;
        }

        return slow;
    }

    // Merge two sorted linked lists
    ListNode* merge(ListNode* h1, ListNode* h2) {
        ListNode* dummyNode = new ListNode(-1);
        ListNode* temp = dummyNode;

        while (h1 != nullptr && h2 != nullptr) {
            if (h1->val <= h2->val) {
                temp->next = h1;
                h1 = h1->next;
            } else {
                temp->next = h2;
                h2 = h2->next;
            }
            temp = temp->next;
        }

        if (h1 != nullptr)
            temp->next = h1;
        else
            temp->next = h2;

        ListNode* ans = dummyNode->next;
        delete dummyNode;   // Prevent memory leak
        return ans;
    }

    // Merge Sort
    ListNode* sortList(ListNode* head) {
        // Base case
        if (head == nullptr || head->next == nullptr)
            return head;

        // Split into two halves
        ListNode* mid = middleNode(head);
        ListNode* left = head;
        ListNode* right = mid->next;
        mid->next = nullptr;

        // Recursively sort both halves
        left = sortList(left);
        right = sortList(right);

        // Merge sorted halves
        return merge(left, right);
    }
};