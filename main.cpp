#include <iostream>
#include "SingleLinkedList.h"

using namespace std;

int main() {
    SingleLinkedList<int> a;
    cout << "INSTRUCTIONS FOR USE:" << endl;
    cout << "Enter '1' to check the list for emptiness" << endl;
    cout << "Enter '2' to add an item to the end of the list and then enter the value" << endl;
    cout << "Enter '3' to add an item to the beggining of the list and then enter the value" << endl;
    cout << "Enter '4' to add an element at the given index and then enter index and value" << endl;
    cout << "Enter '5' to remove the first element" << endl;
    cout << "Enter '6' to remove the last element" << endl;
    cout << "Enter '7' to remove an item by a given value and then enter that value" << endl;
    cout << "Enter '8' to remove an item by a given index and then enter that index" << endl;
    cout << "Enter '9' to find the position of an element by a given value" << endl;
    cout << "Enter '10' to assign a different value to an element at a given index,"
            " first enter the index, and then the new value" << endl;
    cout << "Enter '11' to print the list" << endl;
    cout << "Enter '-1' to terminate the program" << endl;
    while (true) {
        int command;
        cin >> command;
        if (command == -1) {
            return 0;
        }
        if (command == 1) {
            if (a.is_empty()) {
                cout << "true" << endl;
            } else {
                cout << "false" << endl;
            }
        }
        if (command == 2) {
            int val;
            cin >> val;
            a.push_back(val);
        }
        if (command == 3) {
            int val;
            cin >> val;
            a.push_front(val);
        }
        if (command == 4) {
            int index, val;
            cin >> index >> val;
            a.insert(index, val);
        }
        if (command == 5) {
            a.pop_front();
        }
        if (command == 6) {
            a.pop_back();
        }
        if (command == 7) {
            int val;
            cin >> val;
            a.remove(val);
        }
        if (command == 8) {
            int index;
            cin >> index;
            a.pop(index);
        }
        if (command == 9) {
            int val;
            cin >> val;
            cout << a.find(val) << endl;
        }
        if (command == 10) {
            int index, new_val;
            cin >> index >> new_val;
            a[index] = new_val;
        }
        if (command == 11) {
            cout << a << endl;
        }
    }
}
