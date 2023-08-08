#include <iostream>
#include <stack>

int main(){
    std::stack<char>stk;

    std::string input;

    std::cin >> input;


    for(auto character : input){
        if(character == '(' || character == '{' || character == '['){
            stk.push(character);
        } else if (! stk.empty() && ((character == '}' && stk.top() == '{') || (character == ']' && stk.top() == '[') || (character == ')' && stk.top() == '('))){
            stk.pop();
        }
    }

    std::cout << (stk.empty() ? "YES" : "NO");
    return 0;
}