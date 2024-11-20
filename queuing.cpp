#include <iostream>
#include <string>

using namespace std;

int top = -1;
int arr[15] = {0};

bool isEmpty() {
    return top == -1;
}

bool isFull() {
    return top == 14;
}

void push(int val) {
    if (val > 99) {
        cout << "Value is too large, please choose something from 0 to 99" << endl;
        return;
    }
    if (isFull()) {
        cout << "Stack Overflow Occurring" << endl;
    } else {
        top++;
        arr[top] = val;
    }
}

int pop() {
    if (isEmpty()) {
        cout << "Stack Underflow Occurring" << endl;
        return 0;
    } else {
        int popValue = arr[top];
        arr[top] = 0;
        top--;
        return popValue;
    }
}

int count() {
    return top + 1;
}

int peek(int pos) {
    if (isEmpty()) {
        cout << "Stack Underflow Occurring" << endl;
        return 0;
    } else {
        return arr[pos];
    }
}

void change(int pos, int val) {
    arr[pos] = val;
    cout << "Value changed at specified location " << pos << endl;
}

void display() {
    cout << "All values in the stack are: " << endl;
    for (int i = 14; i >= 0; i--) {
        cout << arr[i] << endl;
    }
}

int main() {
    int option, position, value;

    do {
        cout << "What operation do you want to perform? Select Option Number. Enter 0 to exit." << endl;
        cout << "1. Push()" << endl;
        cout << "2. Pop()" << endl;
        cout << "3. isEmpty()" << endl;
        cout << "4. isFull()" << endl;
        cout << "5. peek()" << endl;
        cout << "6. count()" << endl;
        cout << "7. change()" << endl;
        cout << "8. display()" << endl;
        cout << "9. Clear Screen" << endl << endl;

        cin >> option;
        switch (option) {
            case 0:
                break;
            case 1:
                cout << "Enter a value to push into the stack" << endl;
                cin >> value;
                push(value);
                break;
            case 2:
                cout << "Pop Function Called - Popped Value: " << pop() << endl;
                break;
            case 3:
                if (isEmpty())
                    cout << "Stack is Empty" << endl;
                else
                    cout << "Stack is not Empty" << endl;
                break;
            case 4:
                if (isFull())
                    cout << "Stack is Full" << endl;
                else
                    cout << "Stack is not Full" << endl;
                break;
            case 5:
                cout << "Enter position of item you want to peek: " << endl;
                cin >> position;
                cout << "Value at position " << position << " is " << peek(position) << endl;
                break;
            case 6:
                cout << "Count Function Called - Number of items in the Stack are: " << count() << endl;
                break;
            case 7:
                cout << "Change Function Called - " << endl;
                cout << "Enter position of item you want to change: " << endl;
                cin >> position;
                cout << "Enter value of item you want to change: " << endl;
                cin >> value;
                change(position, value);
                break;
            case 8:
                cout << "Display Function Called - " << endl;
                display();
                break;
            case 9:
                system("cls");
                break;
            default:
                cout << "Enter An Option Number" << endl;
                break;
        }
    } while (option != 0);
    return 0;
}