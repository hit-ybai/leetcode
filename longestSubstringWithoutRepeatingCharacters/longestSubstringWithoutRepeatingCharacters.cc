class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        queue<char> current_sub_str;
        int subStringMaxLength = 0;
        
        for (auto it = s.begin() ; it < s.end(); it++) {
            char current_alphabet = *it;
            
            if (is_alphabet_exist(current_alphabet)) {
                sync_max_value( subStringMaxLength, current_sub_str.size() );
                pop_sub_string_until_alphabet( current_alphabet, current_sub_str );
            } else {
                mark_alphabet(current_alphabet);
            }
            
            current_sub_str.push(current_alphabet);
        }
        sync_max_value( subStringMaxLength, current_sub_str.size() );
        return subStringMaxLength;
    }
private:
    static const int SIZE_OF_ASCII    = 128;
    bool alphabet_flag[SIZE_OF_ASCII] = { false };
    
    bool is_alphabet_exist(char alphabet) {
        return alphabet_flag[int(alphabet)];
    }
    void sync_max_value(int &subStringMaxLength, size_t currentSubStringLength) {
        if (currentSubStringLength > subStringMaxLength) {
            subStringMaxLength = int(currentSubStringLength);
        }
    }
    void pop_sub_string_until_alphabet(char alphabet, queue<char> &current_sub_str) {
        for ( char current_alphabet = current_sub_str.front(); current_alphabet != alphabet;
            alphabet_flag[int(current_alphabet)] = false,
            current_sub_str.pop(),
            current_alphabet = current_sub_str.front()
        );
        current_sub_str.pop();
    }
    void mark_alphabet(char alphabet) {
        alphabet_flag[int(alphabet)] = true;
    }
};