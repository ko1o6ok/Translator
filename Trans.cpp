//
// Created by ф on 25.10.2022.
//

#include "Trans.h"

Trans::Trans(string str) {
    s = str;
}

int Trans::compute() {
    return 0;
}

string Trans::polish_reverse() {
    string Res;
    for (char &symbol: s) {
        switch (symbol) {
            case '0':
            case '1':
            case '2':
            case '3':
            case '4':
            case '5':
            case '6':
            case '7':
            case '8':
            case '9':
            {
                Res.push_back(symbol);
                break;
            }
            case '(':
            {
                my_stack.push(symbol);
                break;
            }
            case ')':
            {
                while(!(my_stack.empty())&&(my_stack.top() != '(')){
                    Res.push_back(my_stack.top());
                    my_stack.pop();
                }
                my_stack.pop();
                break;
            }
            case '+':
            case '-':
            case '*':
            case '/':
                if(!my_stack.empty())
                    while (!my_stack.empty()&&(Priority(my_stack.top()) >= Priority(symbol))) {
                        Res.push_back(my_stack.top());
                        my_stack.pop();
                    }
                my_stack.push(symbol);
        }
    }
    while (!my_stack.empty()){
        Res.push_back(my_stack.top());
        my_stack.pop();
    }
    return Res;
}

short Trans::Priority(char c) {
    switch (c) {
        case '(':
            return 0;
        case '+':
            return 1;
        case '-':
            return 1;
        case '*':
            return 2;
        case '/':
            return 2;
        default:
            return -1;
    }
}
