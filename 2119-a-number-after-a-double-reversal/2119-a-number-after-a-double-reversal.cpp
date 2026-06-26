class Solution {
public:
    bool isSameAfterReversals(int num) {
        int temp=num;
        long long reversed1=0,reversed2=0;

        while(num) {
            reversed1=reversed1*10+num%10;
            num=num/10;
        }
        while(reversed1) {
            reversed2=reversed2*10+reversed1%10;
            reversed1=reversed1/10;
        }
        if(reversed2==temp) return true;
        else return false;
    }
};