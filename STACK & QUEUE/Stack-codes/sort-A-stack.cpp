void sortedStack(stack <int> &stack, int num) {
  if(stack.empty() || (!stack.empty() &&stack.top()<num)) 
  {
    stack.push(num);
    return;
  }
  int n = stack.top();
  stack.pop();
  
  sortedStack(stack,num);
  stack.push(n);
}
 
void home(stack<int> &stack) {
  if(stack.empty()) {
    return;
  }
  int num = stack.top();
  stack.pop();
  
  home(stack);
  sortedStack(stack,num);
}
