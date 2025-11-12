#include <bits/stdc++.h>
using namespace std;

class MinStack {
public:
    vector<pair<int, int>> v;

    MinStack() {
        // Constructor (no initialization needed)
    }

    void push(int val) {
        if (v.empty()) {
            v.push_back({val, val});
        } else {
            int currentMin = min(val, v.back().second);
            v.push_back({val, currentMin});
        }
    }

    void pop() {
        if (!v.empty()) {
            v.pop_back();
        }
    }

    int top() {
        if (!v.empty()) {
            return v.back().first;
        }
        throw runtime_error("Stack is empty!");
    }

    int getMin() {
        if (!v.empty()) {
            return v.back().second;
        }
        throw runtime_error("Stack is empty!");
    }
};

// Example main() function for VS Code testing
int main() {
    MinStack* obj = new MinStack();
    obj->push(-2);
    obj->push(0);
    obj->push(-3);
    cout << "Current minimum: " << obj->getMin() << endl;  // Output: -3
    obj->pop();
    cout << "Top element: " << obj->top() << endl;         // Output: 0
    cout << "Current minimum: " << obj->getMin() << endl;  // Output: -2

    delete obj;
    return 0;
}
