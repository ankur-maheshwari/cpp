void InsertAtBottom (stack<int> &s , int element) {
  if(s.empty()) {
    s.push(element);
      return;
  }
  int num = s.top();
  s.pop();

  InsertAtBottom(s,element);
  s.push(num);
}

void reverse (stack <int > &stack) {
  if(stack.empty()) {
    return;
  }
  int num = stack.top();
  s.pop();
  
  reverse(stack);
  InsertAtBottom(stack,num);
}
