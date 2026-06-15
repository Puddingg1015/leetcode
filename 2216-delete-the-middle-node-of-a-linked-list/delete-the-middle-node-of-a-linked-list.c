/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

struct ListNode* deleteMiddle(struct ListNode* head) {
        int len = 0;
        struct ListNode *curr = head;
        while (curr) {
            curr = curr->next;
            len++;
        }
        int m = len / 2;
        if (len == 1) {
            return NULL;
        }
        curr = head;
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