class Solution {
public:
    string reverseOnlyLetters(string s) {
        int n = s.size();
        int f = 0, b = n - 1;
        while (f <= b) {
            if ((((int)s[f] >= 65 && (int)s[f] <= 90) ||
                 ((int)s[f] >= 97 && (int)s[f] <= 122)) &&
                (((int)s[b] >= 65 && (int)s[b] <= 90) ||
                 ((int)s[b] >= 97 && (int)s[b] <= 122))) {
                char ch=s[f];
                s[f]=s[b];
                s[b]=ch;
                f++;
                b--;
            } 
            else if ((((int)s[f] >= 65 && (int)s[f] <= 90) ||
                 ((int)s[f] >= 97 && (int)s[f] <= 122))) {
                b--;
            }
            else f++;
        }
        return s;
    }
};