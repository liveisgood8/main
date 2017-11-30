#include <iostream>
#include <string>
#include <stack>

using namespace std;

bool CheckBalance(string &str);

int main()
{
    //string brkts = "(([]{()}))";
    string br;
    cout <<"Enter brackets string: ";
    cin >> br;

    if (CheckBalance(br))
        cout <<"Balanced\n";
    else
        cout <<"Unbalanced\n";

    return 0;
}

bool CheckBalance(string &str) {
    stack<char> brkts;

    for (unsigned int i = 0; i < str.length(); i++) {
        if (str[i] == '(' || str[i] == '[' || str[i] == '{') {
            brkts.push(str[i]);   //Добавляем в стэк открывающуюся скобку
        }
        else if (str[i] == ')' || str[i] == ']' || str[i] == '}') {
            if (brkts.empty()
                    || ( (str[i] == ')') ^ (brkts.top() == '(') )
                    || ( (str[i] == ']') ^ (brkts.top() == '[') )
                    || ( (str[i] == '}') ^ (brkts.top() == '{') )
                    ) {
                return false;
            }
            brkts.pop();  /*
                            Начинаем по ходу строки искать пару открывающейся скобке,
                            если таковую находим,
                            то удаляем верхний элемент стека,
                            который и составил пару найденной закрывающейсе скобке
                        */
        }
    }

    return brkts.empty();   //Проверка, всем ли открывающимся скобкам по итогу нашлась пара
}
