#include "ArrayStack.hpp"
#include <iostream>
#include <string>
using namespace std;

void testBasicStack() {
    cout << "\n--- Basic push/peek/pop/clear test ---\n";
    ArrayStack<int> s(3);

    cout << "Initial stack:\n" << s;

    s.push(10);
    s.push(20);
    s.push(30);
    cout << "After pushing 10, 20, 30:\n" << s;
    cout << "Peek: " << s.peek() << endl;

    try {
        s.push(40);
    }
    catch (const string& e) {
        cout << "Expected exception on push to full stack: " << e << endl;
    }

    s.pop();
    cout << "After one pop:\n" << s;

    s.clear();
    cout << "After clear:\n" << s;

    try {
        s.peek();
    }
    catch (const string& e) {
        cout << "Expected exception on peek empty stack: " << e << endl;
    }
}

template <typename T>
void testRotate(ArrayStack<T>& s) {
    cout << "\n--- Rotate test ---\n";
    cout << "Start:\n" << s;

    s.rotate(Stack<T>::RIGHT);
    cout << "After rotate RIGHT:\n" << s;

    s.rotate(Stack<T>::LEFT);
    cout << "After rotate LEFT:\n" << s;
}

int main() {
    cout << "ArrayStack Driver\n";

    testBasicStack();

    ArrayStack<int> r(5);
    r.push(1);
    r.push(2);
    r.push(3);
    testRotate(r);

    cout << "\n--- Copy constructor / assignment test ---\n";
    ArrayStack<string> a(4);
    a.push("A");
    a.push("B");
    a.push("C");

    ArrayStack<string> b(a); // copy constructor
    cout << "Original a:\n" << a;
    cout << "Copied b:\n" << b;

    ArrayStack<string> c(2);
    c = a; // assignment
    cout << "Assigned c:\n" << c;

    return 0;
}
