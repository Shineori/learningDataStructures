#include <iostream>
#include <string>

using namespace std;

class Stack{
    private:
        int top;
        int arr[15];//Max size of the stack, I'm going to predefine it to 15 and hardcode it

    public:
        Stack ()
        {
            top = -1;
            for(int i = 0; i<15;i++)//TWO +'S AND NOT THREE, I SPENT 45MINS TRYING TO FIGURE OUT WHAT THE ISSUE WAS
            {
                arr[i] = 0; //Marking every element of the stack as 0, since it's empty
            }
        }
        bool isEmpty() //This'll return true or false depending on if the stack is empty or not
        {
            if(top == -1)
                return true;
            else
                return false;
        }
        bool isFull()
        {
            if (top==14)
                return true;
            else
                return false;
        }
        void push(int val){
            if (val > 99)
            {
                cout << "Value is too large, please choose something from 0 to 99" << endl;
                return;
            }
            if(isFull())
            {
                cout<<" Stack Overflow Occuring "<<endl;
            }
            else
            {
                top++;
                arr[top] = val;
            }
        }

        int pop()
        {
            if(isEmpty()) //Going to define the underflow, if the stack is empty and we're trying to remove nothing.
            {
                cout<<" Stack Underflow Occuring "<<endl;
                return 0;
            }
            else //If there is someting in the stack afterall, we'll carry this one out instead
            {
                int popValue = arr[top];
                arr[top] = 0;
                top--; //decreasing the top value by 1 since we're popping
                return popValue;
            }
        }

        int count()
        {
            return (top+1);
        }
        int peek(int pos)
        {
            if (isEmpty())
            {
                cout<<" Stack Underflow Occuring "<<endl;
                return 0;
            }
            else
            {
                return arr[pos];
            }
        }

        void change(int pos, int val)
        {
            arr[pos] = val;
            cout<<" Value changed at specified location "<<pos<<endl;
        }

        void display()
        {
            cout<<" All values in the stack are: "<<endl;
            for(int i = 14; i>=0; i--)
            {
                cout<<arr[i]<<endl;
            }
        }
};
int main()
{
    Stack s1;
    int option, position, value;

    do
    {
        cout<<" What operation do you want to perform? Select Option Number. Enter 0 to exit. "<<endl;
        cout<<" 1. Push() "<<endl;
        cout<<" 2. Pop() "<<endl;
        cout<<" 3. isEmpty() "<<endl;
        cout<<" 4. isFull() "<<endl;
        cout<<" 5. peek() "<<endl;
        cout<<" 6. count() "<<endl;
        cout<<" 7. change() "<<endl;
        cout<<" 8. display() "<<endl;
        cout<<" 9. Clear Screen "<<endl<<endl;

        cin>>option;
        switch (option)
        {
            case 0:
                break;
            case 1:
                cout<<" Enter an value to push into the stack "<<endl;
                cin>>value;
                s1.push(value);
                break;
            case 2:
                cout<<" Pop Function Called - Popped Value: "<<s1.pop()<<endl;
                break;
            case 3:
                if(s1.isEmpty())
                    cout<<" Stack is Empty "<<endl;
                else
                    cout<<" Stack is not Empty "<<endl;
                break;
            case 4:
                if(s1.isFull())
                    cout<<" Stack is Full "<<endl;
                else
                    cout<<" Stack is not Full "<<endl;
                break;
            case 5:
                cout<<" Enter position of item you want to peek: "<<endl;
                cin>>position;
                cout<<" Value at position "<<position<<" is "<<s1.peek(position)<<endl;
                break;
            case 6:
                cout<<" Count Function Called - Number of items in the Stack are: "<<s1.count()<<endl;
                break;
            case 7:
                cout<<" Change Function Called - "<<endl;
                cout<<" Enter position of item you want to change: "<<endl;
                cin>>position;
                cout<<" Enter value of item you want to change: "<<endl;
                cin>>value;
                s1.change(position, value);
                break;
            case 8:
                cout<<" Display Function Called - "<<endl;
                s1.display();
                break;
            case 9:
                system("cls"); //clearing the screen so we can start fresh
                break;
            default:
                cout<<" Enter An Option Number "<<endl;
                break;
        }
    }while(option!=0); //Makking sure that it only quits when 0 is pushed.
    return 0;
}