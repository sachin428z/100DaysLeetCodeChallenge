class Solution {
public:
    int digitSum(int i) {
        int sum=0;
        while(i!=0) {
            sum+=i%10;
            i/=10;
        }
        return sum;
    }

    int countEven(int num) {
        int cnt=0;

        for(int i=1;i<=num;i++) {
            if(digitSum(i)%2==0) cnt++;
        }
        return cnt;
    }
};