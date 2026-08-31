class Solution {
public:
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        ios_base::sync_with_stdio(false);
        if(head == nullptr || head->next == nullptr || head->next->next == nullptr) {
            return {-1, -1};
        }
        vector<int> v;
        int i = 1;
        ListNode* temp = head;
        ListNode* prev = head;
        while (temp->next) {
            if ((temp->val < prev->val && temp->val < temp->next->val) || (temp->val > prev->val && temp->val > temp->next->val)) {
                v.push_back(i);
            }
            i++;
            prev = temp;
            temp = temp->next;
        }
        if (v.size() < 2) {
            return {-1, -1};
        }
        int mini = INT_MAX;
        for (int i = 1; i < v.size(); i++) {
            mini = min(mini, v[i] - v[i - 1]);
        }
        return {mini, v.back() - v.front()};
    }
};