class Solution {
public:
    string longestDiverseString(int a, int b, int c) {
        priority_queue<pair<int, char>> max_heap;
        if (a > 0) max_heap.push({a, 'a'});
        if (b > 0) max_heap.push({b, 'b'});
        if (c > 0) max_heap.push({c, 'c'});
        
        string result;
        
        while (!max_heap.empty()) {
            auto [cnt1, char1] = max_heap.top();
            max_heap.pop();
            if (result.size() >= 2 && result[result.size() - 1] == char1 && result[result.size() - 2] == char1) {
                if (max_heap.empty()) break;
                auto [cnt2, char2] = max_heap.top();
                max_heap.pop();
                result += char2;
                if (cnt2 - 1 > 0) max_heap.push({cnt2 - 1, char2});
                max_heap.push({cnt1, char1});
            } else {
                result += char1;
                if (cnt1 - 1 > 0) max_heap.push({cnt1 - 1, char1});
            }
        }
        
        return result;
    }
};