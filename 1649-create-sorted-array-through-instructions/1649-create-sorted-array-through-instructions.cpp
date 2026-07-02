class Solution {
public:
    int c[100001];

    int createSortedArray(vector<int>& instructions) {
        memset(c, 0, sizeof(c));

        int res = 0;
        int n = instructions.size();
        int mod = 1e9 + 7;

        for (int i = 0; i < n; i++) {
            int smaller = get(instructions[i] - 1);
            int greater = i - get(instructions[i]);

            res = (res + min(smaller, greater)) % mod;

            update(instructions[i]);
        }

        return res;
    }

    void update(int x) {
        while (x < 100001) {
            c[x]++;
            x += (x & -x);
        }
    }

    int get(int x) {
        int sum = 0;

        while (x > 0) {
            sum += c[x];
            x -= (x & -x);
        }

        return sum;
    }
};