#include<bits/stdc++.h>
using namespace std;

class MinStack {
private:
        vector<int> minstack;
        vector<int> min;
        int size = 0;
        int minnum = 0;
public:
    MinStack() { 
        size = 0;
        minnum = 0;
    }
    void push(int val) {
        this->minstack.push_back(val);
        size++;
        if(size == 1)
            minnum = val;
        else if(val < min[size-2])
        {
            //cout << "val: " << val << " size: " << size <<  "min[size-1]: " << min[size-2] << endl;
            minnum = val;
        }
        
        else
        {
            minnum = min[size-2];
        }
        
        this->min.push_back(minnum);

    }
    
    void pop() {
        this->minstack.pop_back();
        this->min.pop_back();
        size--;
        
    }
    
    int top() {
        return this->minstack.back();
    }
    
    int getMin() {
        return this->min.back();
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