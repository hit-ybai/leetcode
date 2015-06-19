#include <cstddef>

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    int getNodeVal(ListNode* node) {
        return node ? node->val : 0;
    }
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *ans_pointer = NULL, *ans_head = NULL;
        
        int sum = 0;
        bool carry_flag = false;
        while (true) {
            sum        = getNodeVal(l1) + getNodeVal(l2) + carry_flag;
            carry_flag = ( sum >= 10 );
            sum        = ( sum < 10 ) ? sum :  ( sum - 10 );
            
            if (ans_pointer) {
                ans_pointer->next = new ListNode(sum);
                ans_pointer       = ans_pointer->next;
            } else {
                ans_head    = new ListNode(sum);
                ans_pointer = ans_head;
            }
            l1 = l1 ? l1->next : NULL;
            l2 = l2 ? l2->next : NULL;
            if ( !(l1 || l2) ) {
                if (carry_flag) { ans_pointer->next = new ListNode(1); }
                break;
            }
        }
        return ans_head;
    }
};
