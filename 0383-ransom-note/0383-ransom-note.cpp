class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        int freq[26] = {0};

        // Count characters in magazine
        for (char c : magazine) {
            freq[c - 'a']++;
        }

        // Use characters for ransom note
        for (char c : ransomNote) {
            freq[c - 'a']--;

            if (freq[c - 'a'] < 0) {
                return false;
            }
        }

        return true;
    }
};
