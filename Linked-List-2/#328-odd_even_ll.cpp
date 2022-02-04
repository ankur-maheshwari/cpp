Input: head = [1,2,3,4,5]
Output: [1,3,5,2,4]

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
    ListNode* oddEvenList(ListNode* head) {
        if(head == NULL ||  head->next == NULL) 
            return NULL ;
    ListNode * odd = head;
    ListNode*even  = head->next;
    ListNode*evenStart = head->next;
    while(odd->next != NULL && even->next != NULL )
    {
        odd->next = even->next;
        odd = odd->next;
        even->next = odd->next;
        even  = even->next;
    }
    odd->next = evenStart;
    if(odd->next != NULL ) 
    {
        even = NULL;
    }
    return head;
    }
};
