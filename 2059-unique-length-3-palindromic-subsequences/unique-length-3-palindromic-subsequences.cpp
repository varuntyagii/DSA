class Solution {
public:
    int countPalindromicSubsequence(string s) {
        unordered_set<char> st; // Single set reused for different characters
        int n = s.size();
        unordered_set<char> unique_letters;

        // Step 1: Collect all unique characters
        for (auto ch : s) {
            unique_letters.insert(ch);
        }

        int result = 0;

        // Step 2: Process each unique character
        for (auto letter : unique_letters) {
            int left = -1, right = -1;

            // Find the first and last occurrence of the character
            for (int i = 0; i < n; i++) {
                if (s[i] == letter) {
                    if (left == -1) {
                        left = i;
                    } else {
                        right = i;
                    }
                }
            }

            // If valid left and right indices exist
            if (left != -1 && right != -1 && right > left + 1) {
                st.clear(); // Clear the set to reuse it for middle characters

                // Insert all middle characters
                for (int mid = left + 1; mid <= right - 1; mid++) {
                    st.insert(s[mid]);
                }

                // Add the count of unique middle characters
                result += st.size();
            }
        }

        return result;
    }
};
