Merger sort IN LINKDEE LIST


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
    ListNode* Mid(ListNode* head){
        if(head==NULL||head->next==NULL)
            return head;
		
        ListNode* slow = head;
        ListNode* fast = head->next;
        while(fast != NULL && fast->next != NULL){
            slow=slow->next;
            fast=fast->next->next;
        }
        return slow;
        }
     
    private:
    ListNode* mergesort(ListNode* a, ListNode* b){
        if(a == NULL) 
            return b;
        if(b == NULL) 
            return a;
        
        ListNode* temp;  
        
        if(a->val <= b->val){
            temp = a;
            temp->next = mergesort(a->next, b);
        }
        else{
            temp = b;
            temp->next = mergesort(a, b->next);
        }
        
        return temp;
    }
    public:
    ListNode* sortList(ListNode* head) {
         if(head == NULL || head->next == NULL){
            return head;
        }
        ListNode* mid = Mid(head);
        ListNode* left = head;
        ListNode* right = mid->next;
        mid->next = NULL;
        ListNode* ans = mergesort(sortList(left),sortList(right));
        return ans;
    }
};
