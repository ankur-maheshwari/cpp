#include <iostream>
#include <stack>
using namespace std;

int main () {
 strins name = "home";
  
  stack<char> s;
  for(int i=0;i<name.length();i++) {
    char ch = name[i];
    s.push(ch);
  }
  string ans = "";
  while(! s.empty()){
   char ch = s.top();
    ans.push_back(ch);
    s.pop();
  }
  
  cout<<"REVERSE STRING IS : "<<ans;
}
