class Solution {
public:
    int finalValueAfterOperations(vector<string>& operations) {
        int n=operations.size();

        int sum=0;
        for(int i=0;i<n;i++) {
            if (operations[i]=="--X" || operations[i]=="X--") sum-=1;
            else sum+=1;
        }
        
        return sum;
    }
};