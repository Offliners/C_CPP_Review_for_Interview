#include<iostream>
#include<vector>
#include<climits>

using namespace std;

class MinStack {
public:
    vector<int> s;
    vector<int> min_s;

    MinStack() {
        min_s.push_back(INT_MAX);
    }
    
    void push(int val) {
        s.push_back(val);

        if(val <= min_s.back())
            min_s.push_back(val);
    }
    
    void pop() {
        int val = s.back();
        s.pop_back();

        if(val == min_s.back())
            min_s.pop_back();
    }
    
    int top() {
        return s.back();
    }
    
    int getMin() {
        return min_s.back();
    }
};


int main(void)
{
    string cmd;
    MinStack *s;
    while(cin >> cmd)
    {
        if(cmd == "MinStack")
        {
            s = new MinStack();
            cout << endl;
        }
        else if(cmd == "push")
        {
            int val;
            cin >> val;
            s->push(val);
            cout << endl;
        }
        else if(cmd == "top")
        {
            int data = s->top();
            cout << data << endl;
        }
        else if(cmd == "pop")
        {
            s->pop();
            cout << endl;
        }
        else if(cmd == "getMin")
        {
            int data = s->getMin();
            cout << data << endl;
        }
    }

    return 0;
}