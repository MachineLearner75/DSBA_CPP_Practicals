#include <iostream>
#include <exception>

#include "stack.h"

using std::cout;
using std::endl;
using std::exception;

int main() {
    Stack <int> a(10);

    try {
        a.push(10);
        a.push(2);
        a.push(10);
        a.push(5);
        a.push(10);
        a.push(12220);
        a.print();
        a.pop();
        a.print();

        cout << "top: " << a.top() << endl;
    } catch (exception &e) {
        cout << e.what() << endl;
}
