class Solution {
public:
    int countPoints(string rings) {
        int n=rings.size();
        unordered_map<int,unordered_set<char>> mp; // array of unique colors

        for(int i=0;i<n;i+=2) {
            char colors=rings[i];
            int rod=rings[i+1]-'0'; // char ko int me convert kr bsdk

            mp[rod].insert(colors);
        }
        int count = 0;

        for (auto it : mp) {
            if (it.second.size() == 3)
                count++;
        }

        return count;
    }
};