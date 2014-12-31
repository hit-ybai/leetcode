#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int> &numbers, int target) {
        std::unordered_map<int, int> num_idx_map;
        auto n = numbers.size();
        for (int i = 0; i < n; i++)
            num_idx_map[numbers[i]] = i + 1;

        for (int i = 0; i < n - 1; i++) {
            if (num_idx_map.find(target - numbers[i]) != num_idx_map.end()) {
                int current_num_idx = i + 1;
                int match_num_idx = num_idx_map[target - numbers[i]];

                if (match_num_idx != current_num_idx)
                    return { current_num_idx,  match_num_idx };
            }
        }
    }
};