//
//  main.cpp
//  Evaluate Reverse Polish Notation
//
//  Created by Yu Bai on 19/8/14.
//  Copyright (c) 2014 Yu Bai. All rights reserved.
//

#include <iostream>
#include <vector>
#include <stack>

using std::vector;
using std::string;

class Solution {
public:
    bool is_op (string input)
    {
        if (("+" == input) || ("-" == input) || ("/" == input) || ("*" == input))
        {
            return true;
        }
        else
            return false;
    }
    
    int str_to_num(string& input)
    {
        int ans = 0;
        int flag = 1;
        size_t len = input.length();
        int i = 0;
        if (input[i] == '-') {
            i++;
            flag = -1;
        }
        for (; i < len; i++)
        {
            ans *= 10;
            ans += (input[i] - '0');
        }
        return ans * flag;
    }
    
    double operation (string& op, int left_num, int right_num)
    {
        if ("+" == op) {
            return left_num + right_num;
        }
        else if ("-" == op)
        {
            return left_num - right_num;
        }
        else if ("*" == op)
        {
            return left_num * right_num;
        }else if ("/" == op)
        {
            return left_num / right_num;
        }
        return -1;
    }

    int evalRPN(vector<string> &tokens) {
        std::stack<int> cache_stack;
        int stack_top_num_left;
        int stack_top_num_right;
        for(auto i : tokens)
        {
            if (!is_op(i)) cache_stack.push(str_to_num(i));
            else
            {
                stack_top_num_left = cache_stack.top();
                cache_stack.pop();
                stack_top_num_right = cache_stack.top();
                cache_stack.pop();
                cache_stack.push(operation(i, stack_top_num_right, stack_top_num_left));
            }
        }
        return cache_stack.top();
    }
};

int main(int argc, const char * argv[])
{
    // insert code here...
    Solution s;
    vector<string> tokens =  {"3","-4","+"};
    std::cout << s.evalRPN(tokens) << std::endl;
    return 0;
}

