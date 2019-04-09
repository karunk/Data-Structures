#include<bits/stdc++.h>
using namespace std;
class MonotonicQueue{
    deque<pair<int,int> > Q;
    int queue_capacity;
    bool is_increasing;

    bool compare_deque_back(int element) {
        if(Q.empty()) return false;
        if(is_increasing) {
            return (Q.back().first < element);
        } else return (Q.back().first > element);
    }
public:
    MonotonicQueue(int capacity, bool is_increasing=true) {
        MonotonicQueue::is_increasing = is_increasing;
        Q.clear();
        queue_capacity = capacity;
    }

    void push(int element) {
        if(Q.size() == queue_capacity) return;
        int count = 0;
        while(!Q.empty() && compare_deque_back(element)) {
            count+=(Q.back().second+1);
            Q.pop_back();
        }
        Q.push_back(make_pair(element, count));
    }

    void pop() {
        if(Q.front().second > 0) Q.front().second--;
        else Q.pop_front();
    }

    int find_max_element() {
        if(is_increasing && !Q.empty()) {
            return Q.front().first;
        }
        return -1;
    }

    int find_min_element() {
        if(!is_increasing && !Q.empty()) {
            return Q.front().first;
        }
        return -1;
    }
};
int main() {
    MonotonicQueue m(5);
}