class Solution {
public:
    int convertTime(string current, string correct) {
        int cur=stoi(current.substr(0,2))*60;
        int target=stoi(correct.substr(0,2))*60;
        cur+=stoi(current.substr(3));
        target+=stoi(correct.substr(3));

        int ans=0;
        vector<int> useTime={60,15,5,1};
        while(cur!=target) {
            for(auto time: useTime) {
                if(cur+time<=target) {
                    cur+=time;
                    ans++;
                    break;
                }
            }
        }
        return ans;
    }
};