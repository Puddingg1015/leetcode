/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

struct ListNode* deleteMiddle(struct ListNode* head) {
        int len = 0;
        struct ListNode *_curr = head;
        while (_curr) {
            _curr = _curr->next;
            len++;
        }
        int m = len / 2;
        if (len == 1) {
            return NULL;
        }
        struct ListNode *curr = head;
        struct ListNode *prev = NULL;
        int i = 0;
        while (curr) {
            if (i == m) {
                prev->next = curr->next;
                free(curr);
                curr = NULL;
                break;
            }
            prev = curr;
            curr = curr->next;
            i++;
        }
        return head;
        
}