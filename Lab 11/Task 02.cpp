#include <iostream>
#include <exception>
#include <string>

using namespace std;

class StackOverflowException : public exception {
public:
    const char* what() const noexcept override {
        return "StackOverflowException - Stack is full!";
    }
};
class StackUnderflowException : public exception {
public:
    const char* what() const noexcept override {
        return "StackUnderflowException - Stack is empty!";
    }
};

template <typename T, size_t Capacity = 5>
class Stack {
private:
    T data[Capacity];
    size_t topIndex;

public:
    Stack() : topIndex(0) {}

    void push(const T& item) {
        if (topIndex >= Capacity) {
            throw StackOverflowException();
        }
        data[topIndex++] = item;
    }

    T pop() {
        if (topIndex == 0) {
            throw StackUnderflowException();
        }
        return data[--topIndex];
    }

    bool isEmpty() const {
        return topIndex == 0;
    }

    bool isFull() const {
        return topIndex >= Capacity;
    }

    size_t size() const {
        return topIndex;
    }
};

int main() {
    Stack<int> stack;

    try {
        cout << "Pushing elements until full:" << endl;
        for (int i = 1; i <= 6; i++) {
            stack.push(i);
            cout << "Pushed: " << i << " (Size: " << stack.size() << ")" << endl;
        }
    } catch (const StackOverflowException& e) {
        cout << "Error: " << e.what() << endl;
    }

    try {
        cout << "\nPopping all elements:" << endl;
        while (true) {
            cout << "Popped: " << stack.pop() << " (Size: " << stack.size() << ")" << endl;
        }
    } catch (const StackUnderflowException& e) {
        cout << "Error: " << e.what() << endl;
    }

    return 0;
}
