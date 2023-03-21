#include<bits/stdc++.h>
using namespace std;

class MinStack {
private:
        vector<pair<int, int>> minstack;
public:
    MinStack() {
    }
    void push(int val) {
        if(minstack.empty())
            minstack.push_back({val, val});    
        else
        {
            minstack.push_back({val, min(minstack.back().second, val)});
        }

    }
    
    void pop() {
        minstack.pop_back();
    }
    
    int top() {
        return minstack.back().first;
    }
    
    int getMin() {
        return minstack.back().second;
    }   
};

int main()
{
    int num;
    MinStack minStack;
    minStack.push(-10);
    minStack.push(14);
    num = minStack.getMin();
    cout << "min: " << num << endl;
    num = minStack.getMin();
     cout << "min: " << num << endl; 
    minStack.push(-20);
    num = minStack.getMin();
     cout << "min: " << num << endl;
    num = minStack.getMin();
     cout << "min: " << num << endl;
    num = minStack.top(); 
     cout << "top: " << num << endl;
    num = minStack.getMin();
    cout << "min: " << num << endl;
    minStack.pop();
    minStack.push(10);
    minStack.push(-7);
    num = minStack.getMin();
    cout << "min: " << num << endl; 
    minStack.push(-7);
    minStack.pop();
    num = minStack.top(); 
    cout << "top: " << num << endl;
    num = minStack.getMin();
    cout << "min: " << num << endl; 
    minStack.pop();
}