#include<stack>
bool checkBalanced(char *exp) {
    stack<char> p;
    while (*exp)
    {
       if(*exp=='{'||*exp=='('||*exp=='[')
       {
           p.push(*exp);
       }
       else if(*exp==']'||*exp=='}'||*exp==')')
       {    
           if(p.empty())
               return false;
          char x=p.top();
               if(*exp==']'&&x!='[')
                   return false;
               else if(*exp==')'&&x!='(')
                   return false;
               else if(*exp=='}'&&x!='{')
                   return false;
               else
                   p.pop();
           }
        exp++;     
    }
   
    if(p.empty())
    return true;
    else return false;

}
