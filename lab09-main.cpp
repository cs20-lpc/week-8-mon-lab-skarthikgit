#include "ArrayStack.hpp"
#include <iostream>
#include <string>
using namespace std;

void fillStacks(ArrayStack<int>& a, ArrayStack<int>& b) {
    for (int i = 0; i < 10; i++) {
        cout << i << " ";
        a.push(i);
        b.push(i);
    }
    cout << endl;
}

void popFiveFromB(ArrayStack<int>& b) {
    for (int i = 0; i < 5; i++) {
        int topVal = b.peek();
        cout << "Popping " << topVal << " from stack B" << endl;
        b.pop();
    }
}

int main() {
    ArrayStack<int> stackA(10);
    ArrayStack<int> stackB(10);

    fillStacks(stackA, stackB);

    if (stackA.isFull()) {
        cout << "Stack A is full!" << endl;
    }

    cout << "Stack A length: " << stackA.getLength() << endl;
    cout << "Stack B length: " << stackB.getLength() << endl;

    try {
        stackA.push(10);
    }
    catch (const string&) {
        cout << "push: error, stack is full, avoiding overflow" << endl;
    }

    popFiveFromB(stackB);
    cout << "Stack B length: " << stackB.getLength() << endl;

    stackB.clear();
    if (stackB.isEmpty()) {
        cout << "Stack B is now empty after being cleared" << endl;
    }

    try {
        stackB.pop();
    }
    catch (const string&) {
        cout << "pop: error, stack is empty, avoiding underflow" << endl;
    }

    try {
        stackB.peek();
    }
    catch (const string&) {
        cout << "peek: error, stack is empty, cannot access the top" << endl;
    }

    cout << "Stack A length: " << stackA.getLength() << endl;
    ArrayStack<int> stackC(stackA);
    cout << "Stack C length: " << stackC.getLength() << endl;

    return 0;
}
