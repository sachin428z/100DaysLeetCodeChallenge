class Solution {
public:
    vector<int> decode(vector<int>& encoded, int first) {
        int n=encoded.size();

        vector<int> res;
        res.push_back(first);

        for(int i=0;i<n;i++) {
            res.push_back(res[i]^encoded[i]);
        }
        
        return res;
    }
};