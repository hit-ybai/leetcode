class Solution {
public:
    int max = 0;
    queue<char> current_sub_str;
    bool flag[128] = { false };
    
    int lengthOfLongestSubstring(string s) {
        size_t length = s.length();
        if (0 == length) return int(length);
        
        for (int i = 0; i < length - 1; i++) {
            if ( flag[int( s[i] )] ) {
                if (max < current_sub_str.size()) max = int(current_sub_str.size());
                while ((current_sub_str.front() != s[i])) {
                    flag[int( current_sub_str.front() )] = false;
                    current_sub_str.pop();
                }
                current_sub_str.pop();
            } else flag[int( s[i] )] = true;

            current_sub_str.push(s[i]);
        }
        int is_last_char_available = !flag[int( s[length - 1] )];
        return ( max > current_sub_str.size() ? max : int(current_sub_str.size()) + is_last_char_available );
    }
};