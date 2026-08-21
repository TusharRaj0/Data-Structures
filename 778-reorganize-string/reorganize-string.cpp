class Solution {
public:
    string reorganizeString(string s) {
        unordered_map<char, int> frequency;

        for(char ch : s)
            frequency[ch]++;

        priority_queue<pair<int, char>> maxHeap;

        for(auto entry : frequency)
            maxHeap.push({entry.second, entry.first});

        string result = "";

        while(maxHeap.size() > 1)
        {
            auto current = maxHeap.top();
            maxHeap.pop();

            auto next = maxHeap.top();
            maxHeap.pop();

            result += current.second;
            result += next.second;

            current.first--;
            next.first--;

            if(current.first > 0)
                maxHeap.push(current);

            if(next.first > 0)
                maxHeap.push(next);
        }

        if(!maxHeap.empty())
        {
            auto remaining = maxHeap.top();

            if(remaining.first > 1)
                return "";

            result += remaining.second;
        }

        return result;
    }
};