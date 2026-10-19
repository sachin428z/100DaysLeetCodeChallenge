class Solution {
public:
    int mergeSort(vector<int>& arr, int left, int right) {
        if(left>=right) return 0;
        int mid=left+(right-left)/2;
        int pairs=0;

        pairs+=mergeSort(arr,left,mid);
        pairs+=mergeSort(arr,mid+1,right);
        pairs+=countCrossPairs(arr,left,mid,right);
        mergeSortedHalves(arr,left,mid,right);

        return pairs;
    }
    int countCrossPairs(vector<int>& arr, int left,int mid, int right) {
        int pairs=0;
        int rightPointer=mid+1;

        for(int leftPointer=left;leftPointer<=mid;leftPointer++) {
            long long leftValue=arr[leftPointer];
            while(rightPointer<=right && leftValue>2LL*arr[rightPointer]) rightPointer++;
            pairs+=rightPointer-(mid+1);
        }
        return pairs;
    }
    void mergeSortedHalves(vector<int>& arr, int left, int mid, int right) {
        vector<int> merged;
        int first=left;
        int second=mid+1;

        while(first<=mid && second<=right) {
            if(arr[first]<=arr[second]) {
                merged.push_back(arr[first]);
                first++;
            } else {
                merged.push_back(arr[second]);
                second++;
            }
        }
        while(first<=mid) {
            merged.push_back(arr[first]);
            first++;
        }
        while(second<=right) {
            merged.push_back(arr[second]);
            second++;
        }
        for(int index=0;index<merged.size();index++) {
            arr[left+index]=merged[index];
        }
    }
    int reversePairs(vector<int>& nums) {
        vector<int> arr=nums;
        int n=arr.size();
        if(n<2) return 0;
        return mergeSort(arr,0,n-1);
    }
};