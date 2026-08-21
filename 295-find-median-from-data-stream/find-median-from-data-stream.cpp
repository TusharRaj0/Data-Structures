class MedianFinder {
public:
    priority_queue<int> maxh;
    priority_queue<int, vector<int>, greater<int>> minh;

    MedianFinder() {
    }
    
    void addNum(int num) {
        if(maxh.empty() || num <= maxh.top())
            maxh.push(num);
        else
            minh.push(num);

        if(maxh.size() > minh.size() + 1) {
            minh.push(maxh.top());
            maxh.pop();
        }

        if(minh.size() > maxh.size()) {
            maxh.push(minh.top());
            minh.pop();
        }
    }
    
    double findMedian() {
        if(maxh.size() > minh.size())
            return maxh.top();

        return (maxh.top() + minh.top()) / 2.0;
    }
};