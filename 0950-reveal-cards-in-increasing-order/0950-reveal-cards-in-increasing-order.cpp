class Solution {
public:
    vector<int> deckRevealedIncreasing(vector<int>& deck) {
        queue<int> q;
        sort(deck.begin(), deck.end());
        for(int i = 0; i < deck.size(); ++i) q.push(i);
        vector<int> ans(deck.size(), 0);
        for(int i = 0; i < deck.size(); ++i) {
            int j = q.front();
            q.pop();
            ans[j] = deck[i];
            if(!q.empty()) {
                q.push(q.front());
                q.pop();
            }
        }
        return ans;
    }
};