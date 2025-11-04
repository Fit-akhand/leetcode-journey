#include <bits/stdc++.h>
using namespace std;

class StockSpanner {
public:
    stack<pair<int, int>> st;

    StockSpanner() {
        // Constructor — no initialization needed beyond stack
    }

    int next(int price) {
        int span = 1;
        while (!st.empty() && st.top().first <= price) {
            span += st.top().second;
            st.pop();
        }
        st.push({price, span});
        return span;
    }
};

int main() {
    StockSpanner* obj = new StockSpanner();

    int n;
    cout << "Enter number of prices: ";
    cin >> n;

    cout << "Enter prices: ";
    for (int i = 0; i < n; i++) {
        int price;
        cin >> price;
        cout << "Span for " << price << " = " << obj->next(price) << endl;
    }

    delete obj;
    return 0;
}
