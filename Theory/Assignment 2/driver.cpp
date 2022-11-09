//  every time expression get new random value
//  if value is to be assigned only when new infix expression is entered then
//  clear the map in setinfix()

//  througgh exception if % / with 0

// also handles 1 to 9
// divide by 0 case
// 1 random value when variable occurs multiple time
// delete the previous nodes when new expression tree is created
#include <iostream>
#include "ExpTree.h"
using namespace std;
int main()
{
    string infix;
    cout << "Enter the infix Expression: ";
    cin >> infix;
    ExpTree e(infix);
    do
    {
        char choice;
        e.menu();
        cin >> choice;
        if (choice == '1')
        {
            cout << "Enter the infix Expression: ";
            cin >> infix;
            e.setinfix(infix);
        }
        else if (choice == '2')
        {
            e.display(e.root, 1);   //display in tree form
            cout << endl;
        }
        else if (choice == '3')
        {
            e.displayPrefix(e.root);
            cout << endl;
        }
        else if (choice == '4')
        {
            e.displayInfix(e.root);
            cout << endl;
        }
        else if (choice == '5')
        {
            e.displayPostfix(e.root);
            cout << endl;
        }
        else if (choice == '6')
        {
            cout << "Evaluated as: " << e.evaluate(e.root) << endl;
        }
        else if (choice == '7')
        {
            break;
        }
        else
        {
            cout << "invalid choice entered........ " << endl;
        }
    } while (1);
    return 0;
}