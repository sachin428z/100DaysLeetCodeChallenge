class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        int n=arr.size();
        unordered_map<int,int> mpp;

        for(int i=0;i<n;i++) {
            mpp[arr[i]]++;
        }
        
        unordered_set<int> st;
        for(auto it: mpp) {
            if(st.count(it.second)) return false;
            st.insert(it.second);
        }
        return true;
    }
};