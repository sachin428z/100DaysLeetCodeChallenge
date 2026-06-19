class Solution {
public:
    int trap(vector<int>& height) {
        // int n=height.size();
        // int prefix[n],suffix[n];
        // prefix[0]=height[0];
        // for(int i=0;i<n;i++) {
        //     prefix[i]=max(prefix[i-1],height[i]);
        // }
        // suffix[n-1]=height[n-1];
        // for(int i=n-2;i>=0;i--) {
        //     suffix[i]=max(suffix[i+1],height[i]);
        // }
        // int waterTrapped=0;
        // for(int i=0;i<n;i++) {
        //     waterTrapped+=min(prefix[i],suffix[i])-height[i];
        // }
        // return waterTrapped;

        int n=height.size();
        int left=0,right=n-1;
        int res=0;
        int maxLeft=0,maxRight=0;
        while(left<=right) {
            if (height[left]<=height[right]) {
                if(height[left]>=maxLeft) {
                    maxLeft=height[left];
                } else {
                    res+=maxLeft-height[left];
                }
                left++;
            } else {
                if(height[right]>=maxRight) {
                    maxRight=height[right];
                } else {
                    res+=maxRight-height[right];
                }
                right--;
            }
        }
        return  res;
    }
};