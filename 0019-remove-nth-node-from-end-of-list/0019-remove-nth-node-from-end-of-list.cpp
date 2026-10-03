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
private:
    int listLength(ListNode* head) {
        int length = 0;
        while (head != nullptr) {
            length++;
            head = head->next;
        }
        return length;
    }

public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int L = listLength(head);
        
        if (L == n) {
            ListNode* newHead = head->next;
            delete head;
            return newHead;
        }

        int front = L - n;
        ListNode* temp = head;
        
        for (int i = 1; i < front; ++i) {
            temp = temp->next;
        }

        ListNode* toDelete = temp->next;
        temp->next = temp->next->next;
        delete toDelete;

        return head;
    }
};