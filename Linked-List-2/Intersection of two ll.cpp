class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
          ListNode* ptr1=headA, *ptr2=headB;
		   int n=0, m=0;  
		   while(ptr1!=NULL)
			{
				ptr1=ptr1->next;
				n++;
			}
			while(ptr2!=NULL)
			{
				ptr2=ptr2->next;
				m++;
			}

			ptr1=headA;
			ptr2=headB;
			int sub=abs(m-n); // to get positive value 
			if(m>n)
			{
				for(int i=0; i<sub; i++)
					 ptr2=ptr2->next;
			}
			else
			{
				for(int i=0; i<sub; i++)
					ptr1=ptr1->next;
			}
			while(ptr1 != NULL && ptr2 != NULL)
			{
				if(ptr1==ptr2)  return ptr1;

				ptr1=ptr1->next;
				ptr2=ptr2->next;

			}
			return NULL;
    }
};
