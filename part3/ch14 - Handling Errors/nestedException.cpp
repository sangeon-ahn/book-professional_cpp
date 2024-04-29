#include <iostream>
#include <exception>
#include <string>
#include <memory>
using namespace std;

class MyException : public exception
{
    public:
        MyException(string message) : m_message{std::move(message)} {}
        const char* what() const noexcept override {
            return m_message.c_str();
        }
    private:
        string m_message;
};

void doSomething()
{
    try {
        throw runtime_error { "Throwing a runtime_error exception"};
    } catch ( const runtime_error& e) {
        cout << "Func: " << __func__ << " caught a runtime error" << endl;
        cout << "Func: " << __func__ << " throwing MyException" << endl;
        throw_with_nested(
            MyException{"MyException with nested runtime_error"}
        );
    }
}

int main()
{
    try {
        doSomething();
    } catch (const MyException& e) {
        cout << "Func: " << __func__ << " caught MyException: " << e.what() << endl;

        // 1. 옛날 방식
            // const auto* nested {dynamic_cast<const nested_exception*>(&e)};

            // if (nested) {
            //     try {
            //         nested->rethrow_nested();
            //     } catch (const runtime_error& e) {
            //         cout << "Nested exception: " << e.what() << endl;
            //     }
            // }

        // 2. 최신 방식
        try {
            rethrow_if_nested(e);
        } catch (const runtime_error& e) {
            cout << "Nested exception: " << e.what() << endl;
        }
    }
}