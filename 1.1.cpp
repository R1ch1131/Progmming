#include <iostream>
#include <stack>

using namespace std;

bool isValid(string str) {
    stack<char> bracketsStack;
    for (char sym : str) {
        if (sym == '(' || sym == '{' || sym == '[') {
            bracketsStack.push(sym);
        } else {
            if (bracketsStack.empty() || (sym == ')' && bracketsStack.top() != '(') ||
                (sym == '}' && bracketsStack.top() != '{') || (sym == ']' && bracketsStack.top() != '[')) {
                return false;
            }
            bracketsStack.pop();
        }
    }
    return bracketsStack.empty();
}

int main() {
    bool result = isValid("{([(])}");
    cout << result << endl;

    return 0;
}