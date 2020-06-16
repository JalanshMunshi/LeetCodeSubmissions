// Approach using 1 stack
class MyQueue {
private:
    stack<int> s;
public:
    /** Initialize your data structure here. */
    MyQueue() {
        
    }
    
    /** Push element x to the back of queue. */
    void push(int x) {
        
        if(s.empty())
        {
            s.push(x);
            return;
        }
        int val = s.top();
        s.pop();
        push(x);
        s.push(val);
    }
    
    /** Removes the element from in front of queue and returns that element. */
    int pop() {
        
        int ans = s.top();
        s.pop();
        return ans;
    }
    
    /** Get the front element. */
    int peek() {
        return s.top();
    }
    
    /** Returns whether the queue is empty. */
    bool empty() {
        return s.empty();
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */
// -----------------------------------------------------------
// 
// -----------------------------------------------------------
// Approach using 2 stacks
class MyQueue {
private:
    stack<int> nums, temp;
public:
    /** Initialize your data structure here. */
    MyQueue() {
        
    }
    
    /** Push element x to the back of queue. */
    void push(int x) {
        while(!nums.empty())
        {
            temp.push(nums.top());
            nums.pop();
        }
        nums.push(x);
        while(!temp.empty())
        {
            nums.push(temp.top());
            temp.pop();
        }
    }
    
    /** Removes the element from in front of queue and returns that element. */
    int pop() {
        int t = nums.top();
        nums.pop();
        return t;
    }
    
    /** Get the front element. */
    int peek() {
        return nums.top();
    }
    
    /** Returns whether the queue is empty. */
    bool empty() {
        return nums.empty();
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */