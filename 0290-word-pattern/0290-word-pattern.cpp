class Solution {
public:
    bool wordPattern(string pattern, string s) {
        unordered_map<char, string> mp;
        unordered_map<string, char> rev;

        int i = 0;
        int j = 0;

        while (i < pattern.size()) {
            // If no word is left
            if (j >= s.size())
                return false;

            // Extract one word
            string word = "";

            while (j < s.size() && s[j] != ' ') {
                word += s[j];
                j++;
            }

            // Skip spaces
            while (j < s.size() && s[j] == ' ') {
                j++;
            }

            char ch = pattern[i];

            // Check character -> word mapping
            if (mp.count(ch)) {
                if (mp[ch] != word)
                    return false;
            }
            else {
                mp[ch] = word;
            }

            // Check word -> character mapping
            if (rev.count(word)) {
                if (rev[word] != ch)
                    return false;
            }
            else {
                rev[word] = ch;
            }

            i++;
        }

        // Extra word remaining
        if (j < s.size())
            return false;

        return true;
    }
};