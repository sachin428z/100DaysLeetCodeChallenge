class TrieNode {
public:
    TrieNode* children[2];

    TrieNode() {
        children[0] = children[1] = nullptr;
    }
};

class Solution {
private:
    int getMaxBit(vector<int>& nums) {
        int maxNum = 0;

        for (int num : nums) {
            maxNum = max(maxNum, num);
        }

        if (maxNum == 0) return 0;

        return (int)log2(maxNum);
    }

    void insertNumber(TrieNode* root, int num, int maxBit) {
        TrieNode* node = root;

        for (int bit = maxBit; bit >= 0; bit--) {
            int currentBit = (num >> bit) & 1;

            if (node->children[currentBit] == nullptr) {
                node->children[currentBit] = new TrieNode();
            }

            node = node->children[currentBit];
        }
    }

    int getBestXor(TrieNode* root, int num, int maxBit) {
        TrieNode* node = root;
        int currentXor = 0;

        for (int bit = maxBit; bit >= 0; bit--) {
            int currentBit = (num >> bit) & 1;
            int toggledBit = currentBit ^ 1;

            if (node->children[toggledBit] != nullptr) {
                currentXor |= (1 << bit);
                node = node->children[toggledBit];
            } else {
                node = node->children[currentBit];
            }
        }

        return currentXor;
    }

public:
    int findMaximumXOR(vector<int>& nums) {
        int maxBit = getMaxBit(nums);
        TrieNode* root = new TrieNode();

        for (int num : nums) {
            insertNumber(root, num, maxBit);
        }

        int ans = 0;

        for (int num : nums) {
            ans = max(ans, getBestXor(root, num, maxBit));
        }

        return ans;
    }
};