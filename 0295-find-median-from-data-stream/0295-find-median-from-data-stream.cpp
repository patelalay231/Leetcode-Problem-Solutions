class MedianFinder {
public:
    priority_queue<int>left; // max heap
    priority_queue<int,vector<int>,greater<int>>right; // min heap
    MedianFinder() { // default constructor
        
    }
    
    void addNum(int num) { // O(logn)
        if(left.size() == 0 || num < left.top()) left.push(num);
        else right.push(num);
        // if left has 2 more element than right
        if(left.size() > right.size()+1){
            right.push(left.top());
            left.pop();
        }
        // if right has 2 more element than left
        if(right.size() > left.size()+1){
            left.push(right.top());
            right.pop();
        }
    }
    
    double findMedian() { // O(1)
        if(left.size() == right.size()) return (left.top()+right.top())/2.0;
        else {
            if(left.size() > right.size()) return left.top();
            else return right.top();
        }
    }
};