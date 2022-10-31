#include <iostream>
#include <stack>

using namespace std;
#ifndef TRANSLATOR_TRANS_H
#define TRANSLATOR_TRANS_H


class Trans {
public:
    explicit Trans(string str); // Конструктор
    int compute(); // Подсчёт выражения
//private:
    string s;
    stack<char> my_stack;
    string polish_reverse(); // Преобразование в обратную польскую запись
    short Priority(char c); // Приоритет операции, выражаемой этим символом
};


#endif //TRANSLATOR_TRANS_H
