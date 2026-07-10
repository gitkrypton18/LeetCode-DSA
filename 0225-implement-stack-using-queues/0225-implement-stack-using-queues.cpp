class MyStack {
public:
    queue<int> q;

    MyStack() {

    }

    void push(int x) {
        int s = q.size();
        q.push(x);

        // Rotate the previous elements behind the new element
        while (s--) {
            q.push(q.front());
            q.pop();
        }
    }

    int pop() {
        int val = q.front();
        q.pop();
        return val;
    }

    int top() {
        return q.front();
    }

    bool empty() {
        return q.empty();
    }
};