#include<bits/stdc++.h>
using namespace std ;


bool isOperator(char ch) {
    return ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '^';
}

int performOperation(char op, int operand1, int operand2) {
    switch (op) {
        case '+': return operand1 + operand2;
        case '-': return operand1 - operand2;
        case '*': return operand1 * operand2;
        case '/': return operand1 / operand2;
        case '^': return pow(operand1, operand2);
        default: return 0;
    }
}

int evaluatePrefix(string expression) {
    stack<int> stk;

    // Traverse the expression from right to left
    for (int i = expression.size() - 1; i >= 0; i--) {
        char ch = expression[i];

        if (isdigit(ch)) {
            // If the character is a digit, push it onto the stack
            stk.push(ch - '0');
        } else if (isOperator(ch)) {
            // If the character is an operator, pop two operands
            int operand1 = stk.top(); stk.pop();
            int operand2 = stk.top(); stk.pop();

            // Perform the operation and push the result back onto the stack
            int result = performOperation(ch, operand1, operand2);
            stk.push(result);
        }
    }

    // The final result is at the top of the stack
    return stk.top();
}

// Function to evaluate a postfix expression
int evaluatePostfix(string expression) {
    stack<int> stk;

    // Traverse the expression from left to right
    for (char ch : expression) {
        if (isdigit(ch)) {
            // If the character is a digit, push it onto the stack
            stk.push(ch - '0');
        } else if (isOperator(ch)) {
            // If the character is an operator, pop two operands
            int operand2 = stk.top(); stk.pop();
            int operand1 = stk.top(); stk.pop();

            // Perform the operation and push the result back onto the stack
            int result = performOperation(ch, operand1, operand2);
            stk.push(result);
        }
    }

    // The final result is at the top of the stack
    return stk.top();
}

int main() {
    string prefixExpression = "-+*23*549";
    cout << "The result of the prefix expression is: " << evaluatePrefix(prefixExpression) << endl;

    string postfixExpression = "23*54*+9-";
    cout << "The result of the postfix expression is: " << evaluatePostfix(postfixExpression) << endl;
    return 0;
}