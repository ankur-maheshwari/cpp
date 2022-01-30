FEW THINGS: 
RETURN TYPE NODE* LIA BECZ. when i==0 we r updateing head agr return type void lega toh main LL mai head update nhi hoga islia return head and Node* lia

Node* insertNode(Node *head, int i, int data) {
Node *newNode = new Node(data);              
int count = 0;
Node *temp = head;
if(i == 0) { //Case 2
newNode -> next = head;
head = newNode;
return head;
}
while(temp != NULL && count < i - 1) { //Case 3
temp = temp -> next;
count++;
}
if(temp != NULL) {
Node *a = temp -> next;
temp -> next = newNode;
newNode -> next = a;
}
return head; //Returns the new head pointer after insertion
}

int main() {  
int i,data;
cin>>i>>data;
head = insertNode(head,i,data);
 print(head);
}
