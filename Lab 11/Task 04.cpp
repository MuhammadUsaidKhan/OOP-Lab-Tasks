#include <iostream>
#include <exception>
#include <string>
#include <cmath>
#include <type_traits>

using namespace std;

class NegativeNumberException : public exception {
    double number;
public:
    NegativeNumberException(double num) : number(num) {}
    const char* what() const noexcept override {
        static string msg = "NegativeNumberException - Input must be non-negative! Got: " + to_string(number);
        return msg.c_str();
    }
};

class InvalidTypeException : public exception {
    string typeName;
public:
    InvalidTypeException(const string& type) : typeName(type) {}
    const char* what() const noexcept override {
        static string msg = "InvalidTypeException - Non-numeric type detected! Type: " + typeName;
        return msg.c_str();
    }
};

template<typename T>
struct is_numeric {
    static const bool value = is_arithmetic<T>::value && !is_same<T, bool>::value;
};

template<typename T>
auto sqrt(T num) {
    
    if constexpr (!is_numeric<T>::value) {
        throw InvalidTypeException(typeid(T).name());
    }
    else {
        if (num < 0) {
            throw NegativeNumberException(num);
        }
        return std::sqrt(num);
    }
}

int main() {
    try {
        cout << "sqrt(25): " << sqrt(25) << endl;
    } catch (const exception& e) {
        cerr << "Error: " << e.what() << endl;
    }

    try {
        cout << "sqrt(-4): " << sqrt(-4) << endl;
    } catch (const exception& e) {
        cerr << "Error: " << e.what() << endl;
    }

    try {
        cout << "sqrt(2.25): " << sqrt(2.25) << endl;
    } catch (const exception& e) {
        cerr << "Error: " << e.what() << endl;
    }

    try {
        cout << "sqrt(\"hello\"): " << sqrt("hello") << endl;
    } catch (const exception& e) {
        cerr << "Error: " << e.what() << endl;
    }

    try {
        cout << "sqrt(true): " << sqrt(true) << endl;
    } catch (const exception& e) {
        cerr << "Error: " << e.what() << endl;
    }

    return 0;
}
