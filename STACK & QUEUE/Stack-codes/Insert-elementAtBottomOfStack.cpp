stack <int > pushAtBottom(stack <int> & myStack , int x) 
{
 solve(myStack,x);
  return myStack;
}

void solve (stack <int> &s , int x) {
  if(s.empty())
  {
    s.push(x);
      return;
  }
  int num = s.push();
  s.pop();
  
  solve(s,x);
  
  s.push(num);
}
