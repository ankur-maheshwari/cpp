bool isValidParenthesis(string expression)
{   stack<char>st;
   for(int i=0;i<expression.size();i++){
       char ch=expression[i];
       if(ch=='(' || ch=='{' || ch=='['){
           st.push(ch);
       }
       else{
           if(!st.empty())
           {
               if( (st.top()=='(' && ch==')' ) || ( (st.top()=='{' && ch=='}') ) || ( (st.top()=='[' && ch==']') ) ){
                   st.pop();
               }else{
                   return false;
               }
           }else
           {
               return false;
           }
       }
   }
if(!st.empty()){
    return false;
}else{
    return true;
}
}

 
