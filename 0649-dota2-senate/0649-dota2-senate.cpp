class Solution {
public:
    string predictPartyVictory(string senate) {
       queue<int> rad, dir;
        int n = senate.length();
        // Add all senators to respect queue with index
        for (int i = 0; i < n; i++){
            if (senate[i] == 'R'){
                rad.push(i);
            }
            else {
                dir.push(i);
            }
        }
        // Use increasing n to keep track of position
        while (!rad.empty() && !dir.empty()){
            // Only "winner" stays in their queue
            if (rad.front() < dir.front()){
                rad.push(n++);
            }
            else {
                dir.push(n++);
            }
            rad.pop(), dir.pop();
        }
        return (rad.empty()) ? ("Dire") : ("Radiant"); 
    }
};