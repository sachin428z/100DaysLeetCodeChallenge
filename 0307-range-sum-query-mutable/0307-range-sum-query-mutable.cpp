struct SegTree {
    int n;
    vector<long long> tree;

    SegTree(int n) : n(n), tree(4 * n, 0) {}

    void build(vector<int>& nums, int node, int lo, int hi) {
        if (lo == hi) { tree[node] = nums[lo]; return; }
        int mid = lo + (hi - lo) / 2;
        build(nums, 2*node,   lo,    mid);
        build(nums, 2*node+1, mid+1, hi);
        tree[node] = tree[2*node] + tree[2*node+1];   // merge = sum
    }

    void update(int node, int lo, int hi, int idx, long long val) {
        if (lo == hi) { tree[node] = val; return; }
        int mid = lo + (hi - lo) / 2;
        if (idx <= mid) update(2*node,   lo,    mid, idx, val);
        else update(2*node+1, mid+1, hi,  idx, val);
        tree[node] = tree[2*node] + tree[2*node+1];   // update merge
    }

    long long query(int node, int lo, int hi, int l, int r) {
        if (r < lo || hi < l) return 0;               // out of range
        if (l <= lo && hi <= r) return tree[node];    // fully in range
        int mid = lo + (hi - lo) / 2;
        return query(2*node,   lo,    mid, l, r) +
               query(2*node+1, mid+1, hi,  l, r);
    }
};

class NumArray {
public:
     SegTree st;
    int n;

    NumArray(vector<int>& nums) : n(nums.size()), st(nums.size()) {
        st.build(nums,1,0,n-1);
    }
    
    void update(int index, int val) {
        st.update(1,0,n-1,index,val);
    }
    
    int sumRange(int left, int right) {
        return st.query(1,0,n-1,left,right);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */