class Solution {
public:
    int countSymmetricIntegers(int low, int high) {
        int cnt=0;
        for(int i=low;i<=high;i++) {
            string str=to_string(i);
            int len=str.length();

            if(len%2!=0) continue;
            int half=len/2;
            int leftSum=0;
            int rightSum=0;

            for(int i=0;i<half;i++) leftSum+=str[i]-'0';
            for(int i=half;i<len;i++) rightSum+=str[i]-'0';

            if(leftSum==rightSum) cnt++;
         }
         return cnt;
    }
};