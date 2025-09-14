#include <iostream>
#include <queue>
using namespace std;

class Stack {
    queue<int> q;
public:
    void push(int x) {
        q.push(x);
        for (int i = 0; i < q.size() - 1; i++) {
            q.push(q.front());
            q.pop();
        }
    }

    void pop() {
        if (q.empty()) { cout << "Stack empty\n"; return; }
        cout << q.front() << " popped\n";
        q.pop();
    }

    void top() {
        if (q.empty()) cout << "Stack empty\n";
        else cout << "Top: " << q.front() << endl;
    }
};

int main() {
    Stack s;
    s.push(5);
    s.push(15);
    s.push(25);
    s.top();
    s.pop();
    s.top();
    return 0;
}
