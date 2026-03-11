template <typename T>
ArrayStack<T>::ArrayStack(int i) {
    // TODO
    buffer = new T[i];
    this->length = 0;
    maxSize = i;
}

template <typename T>
ArrayStack<T>::ArrayStack(const ArrayStack<T>& copyObj) {
    copy(copyObj);
}

template <typename T>
ArrayStack<T>& ArrayStack<T>::operator=(const ArrayStack<T>& rightObj) {
    if (this != &rightObj) {
        clear();
        copy(rightObj);
    }
    return *this;
}

template <typename T>
ArrayStack<T>::~ArrayStack() {
    clear();
}

template <typename T>
void ArrayStack<T>::clear() {
    // TODO
    delete[] buffer;
    buffer = nullptr;
    this->length = 0;
    maxSize = 0;
}

template <typename T>
void ArrayStack<T>::copy(const ArrayStack<T>& copyObj) {
    // TODO
    maxSize = copyObj.maxSize;
    this->length = copyObj.length;

    buffer = new T[maxSize];
    for (int i = 0; i < this->length; i++) {
        buffer[i] = copyObj.buffer[i];
    }
}

template <typename T>
int ArrayStack<T>::getLength() const {
    return this->length;
}

template <typename T>
int ArrayStack<T>::getMaxSize() const {
    return maxSize;
}

template <typename T>
bool ArrayStack<T>::isEmpty() const {
    return this->length == 0;
}

template <typename T>
bool ArrayStack<T>::isFull() const {
    return this->length == maxSize;
}

template <typename T>
T ArrayStack<T>::peek() const {
    // TODO
    T tmp;
    if (this->length == 0)
        throw string("Empty Stack");
    tmp = buffer[this->length-1];
    return tmp;
}

template <typename T>
void ArrayStack<T>::pop() {
    // TODO
    if (this->length == 0)
        throw string("Stack Underflow");
    this->length--;
}

template <typename T>
void ArrayStack<T>::push(const T& elem) {
    // TODO
    if (this->length >= maxSize)
        throw string("Stack Overflow");
    buffer[this->length++] = elem;
}

template <typename T>
void ArrayStack<T>::rotate(typename Stack<T>::Direction dir) {
    // TODO
    if (this->length == 0)
        throw string("Empty Stack");
    if (this->length == 1)
        return;

    T tmp;
    int i = 0;
    if (dir == Stack<T>::RIGHT) {
        tmp = buffer[this->length - 1];
        for (i = this->length - 1; i > 0; i--) {
            buffer[i] = buffer[i-1];
        }
        buffer[0] = tmp;
    } else {
        tmp = buffer[0];
        for (i = 0; i < this->length - 1; i++) {
            buffer[i] = buffer[i+1];
        }
        buffer[this->length-1] = tmp;
    }
}

template <typename T>
ostream& operator<<(ostream& outStream, const ArrayStack<T>& myObj) {
    if (myObj.isEmpty()) {
        outStream << "Stack is empty, no elements to display.\n";
    }
    else {
        for (int i = myObj.length - 1; i >= 0; i--) {
            outStream << (i == myObj.length - 1 ? "top\t" : "\t")
                      << myObj.buffer[i] << endl;
        }
    }

    return outStream;
}
