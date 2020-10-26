#include <bits/stdc++.h>
using namespace std;
//Driver program to test above functions
bool isOperand(char x) {
   return (x >= '1' && x <= '9');
}

//Function to return precedence of operators
int prec(char c)
{
    if(c == '^')
    return 3;
    else if(c == '*' || c == '/')
    return 2;
    else if(c == '+' || c == '-')
    return 1;
    else
    return -1;
}

// The main function to convert infix expression
//to postfix expression
string infixToPostfix(string s)
{
    stack<char> st;
    st.push('N');
    int l = s.length();
    string ns;
    for(int i = 0; i < l; i++)
    {
        // If the scanned character is an operand, add it to output string.
        if((s[i] >= '1' && s[i] <= '9'))
        ns+=s[i];

        // If the scanned character is an ‘(‘, push it to the stack.
        else if(s[i] == '(')

        st.push('(');

        // If the scanned character is an ‘)’, pop and to output string from the stack
        // until an ‘(‘ is encountered.
        else if(s[i] == ')')
        {
            while(st.top() != 'N' && st.top() != '(')
            {
                char c = st.top();
                st.pop();
               ns += c;
            }
            if(st.top() == '(')
            {
                char c = st.top();
                st.pop();
            }
        }

        //If an operator is scanned
        else{
            while(st.top() != 'N' && prec(s[i]) <= prec(st.top()))
            {
                char c = st.top();
                st.pop();
                ns += c;
            }
            st.push(s[i]);
        }

    }
    //Pop all the remaining elements from the stack
    while(st.top() != 'N')
    {
        char c = st.top();
        st.pop();
        ns += c;
    }

    return ns;

}


string infixConversion(string postfix) {
   stack<string> infix;
   for (int i=0; postfix[i]!='\0'; i++) {
      if (isOperand(postfix[i])) {
         string op(1, postfix[i]);
         infix.push(op);
      } else {
         string op1 = infix.top();
         infix.pop();
         string op2 = infix.top();
         infix.pop();
         infix.push("("+op2+postfix[i]+op1 +")");
      }
   }
   return infix.top();
}
int main()
{
    string a;
    cout << "Test 1 :";
    cin >> a;
    cout <<"Answer 1 :" <<infixConversion(infixToPostfix(a)) << "\n";
    cout << "------------------------------------------" << "\n";
    cout << "Test 2 :";
    cin >> a;
    cout <<"Answer 2 :" <<infixConversion(infixToPostfix(a)) << "\n";
    return 0;
}
