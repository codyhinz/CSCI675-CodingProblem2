class Solution {
public:
    int getMinSwaps(string num, int k) {
        int n = num.length();
        string target = num;
        
        // Generate the kth smallest wonderful integer
        for (int i = 0; i < k; i++) {
            next_permutation(target.begin(), target.end());
        }
        
        int swaps = 0;
        
        // Count the minimum number of adjacent digit swaps
        for (int i = 0; i < n; i++) {
            if (num[i] != target[i]) {
                int j = i + 1;
                while (j < n && num[j] != target[i]) {
                    j++;
                }
                while (j > i) {
                    swap(num[j], num[j-1]);
                    j--;
                    swaps++;
                }
            }
        }
        
        return swaps;
    }
};