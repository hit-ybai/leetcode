import java.util.Stack;

public class Solution {
  public static String reverseWords(String s) {
    String[] temp = s.split(" ");
    int len = temp.length;

    Stack <String> stack = new Stack();
    for (int i = 0; i < len; i++)
    {
      if (!temp[i].equals("")) stack.push(temp[i]);
    }

    String ans = "";
    while (false == stack.isEmpty())
    {
      ans += stack.pop();
      if (!stack.isEmpty()) ans += ' ';
    }

    return ans;
  }
}
