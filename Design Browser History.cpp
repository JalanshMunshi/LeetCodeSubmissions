class BrowserHistory {
public:
    stack<string> backward, forw;
    BrowserHistory(string homepage) {
        backward.push(homepage);
    }
    
    void visit(string url) {
        
        backward.push(url);
        while(!forw.empty())
            forw.pop();
    }
    
    string back(int steps) {
        while(steps-- && backward.size()>1)
        {
            string t = backward.top();
            backward.pop();
            forw.push(t);
        }
        return backward.top();
    }
    
    string forward(int steps) {
        while(steps-- && !forw.empty())
        {
            string t = forw.top();
            forw.pop();
            backward.push(t);
        }
        return backward.top();
    }
};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */