class TrieNode {
public:
    TrieNode* children[2];
    TrieNode() {
        children[0]=children[1]=nullptr;
    }
};

class BinaryTrie {
private:
    TrieNode* root;
public:
    BinaryTrie() {
        root = new TrieNode();
    }

    void insert(int num) {
        TrieNode* node = root;
        for (int bit = 30; bit >= 0; bit--) {
            int currentBit = (num >> bit) & 1;
            if (node->children[currentBit] == nullptr) {
                node->children[currentBit] = new TrieNode();
            }
            node = node->children[currentBit];
        }
    }

    int getMaxXor(int num) {
        TrieNode* node = root;
        int maxXor = 0;

        for (int bit = 30; bit >= 0; bit--) {
            int currentBit = (num >> bit) & 1;
            int oppositeBit = currentBit ^ 1;

            if (node->children[oppositeBit] != nullptr) {
                maxXor |= (1 << bit);
                node = node->children[oppositeBit];
            } else {
                node = node->children[currentBit];
            }
        }

        return maxXor;
    }
};

class Solution {
public:
    vector<int> maximizeXor(vector<int>& nums,
                            vector<vector<int>>& queries) {
        sort(nums.begin(), nums.end());

        vector<int> answer(queries.size(), -1);
        vector<array<int, 3>> offlineQueries;

        for (int i = 0; i < (int)queries.size(); i++) {
            offlineQueries.push_back({
                queries[i][1],
                queries[i][0],
                i
            });
        }
        sort(offlineQueries.begin(), offlineQueries.end());
        BinaryTrie trie;
        int index = 0;

        for (const auto& query : offlineQueries) {
            int m = query[0];
            int x = query[1];
            int originalIndex = query[2];

            while (index < (int)nums.size() &&
                   nums[index] <= m) {
                trie.insert(nums[index]);
                index++;
            }
            if (index == 0) {
                answer[originalIndex] = -1;
            } else {
                answer[originalIndex] = trie.getMaxXor(x);
            }
        }

        return answer;
    }
};