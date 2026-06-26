class Solution {
public:
    int furthestDistanceFromOrigin(string moves) {
        int n=moves.size();
        int left=0;
        int right=0;
        int dash=0;

        for(auto ch: moves) {
            if(ch=='L') left++;
            else if(ch=='R') right++;
            else dash++;
        }
        return abs(left-right)+dash;
    }
};