#include <iostream>

using namespace std;

class parent{
    // Parent class
    int number;

    void checkEven(){
        if (number % 2 == 0) {
            std::cout << "\n Even" << std::endl;
        }
        else {
            std::cout << "\n Odd" << std::endl;
        }
    }

public:

    parent(){
        cout << "Parent class object initiated" << endl;
    }

    void enter() {
        cout << "Enter the number : ";
        cin >> number;
    }

    void enter(int num) {
        number = num;
    }

    void display() {
        checkEven();
        cout << "The number is : " << number << endl;
    }

    ~parent(){
        cout << "Parent Destroyed" << endl;
    }
};

class child : public parent{
    // Child class derived from the parent
    int number2;

  public:

    child() {
        cout << "Child class object initiated" << endl;
    }

    void enterChild() {
        cout << "Enter the number : ";
        cin >> number2;
    }

    void compare(int num) {
        if (num > number2) {
            cout << num << " is larger" << endl;
        }
        else {
            cout << "Child Number is larger" << endl;
        }
    }

    ~child(){
        cout << "Child destroyed" << endl;
    }
};

int main() {
    child num2;
    num2.enterChild();
    num2.compare(6);

    return 0;
}

/*
====== OUTPUT ======

Parent class object initiated
Child class object initiated
Enter the number : 4
6 is larger
Child destroyed
Parent Destroyed

*/
