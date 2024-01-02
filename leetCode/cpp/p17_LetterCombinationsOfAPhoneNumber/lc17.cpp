/* Given a string containing digits from 2-9 inclusive, 
   return all possible letter combinations that the number could represent. 
   Return the answer in any order. */

#include <vector>
#include <string>
#include <iostream>
#include <unordered_map>

using namespace std;

unordered_map<char, string> buttons({{'2', "abc"},
                                     {'3', "def"},
                                     {'4', "ghi"},
                                     {'5', "jkl"},
                                     {'6', "mno"},
                                     {'7', "pqrs"},
                                     {'8', "tuv"},
                                     {'9', "wxyz"}});

class Solution {
public:
    vector<string> letterCombinations(string digits);
    void bfs(int pos, int len, string str, vector<string> &ans, string &digits);
    void printVector(vector<string> &vec);
};

void bfs(int pos, int len, string str, vector<string> &ans, string &digits) {
    
    if(pos == len)
        ans.push_back(str);
    else {
        string letters = buttons[digits[pos]];
        
        for(int i = 0; i < letters.size(); i++)
            bfs(pos+1, len, str+letters[i], ans, digits);
    }
}

vector<string> letterCombinations(string digits) {
    
    vector<string> ans;
     
    if(!digits.size())
        return {};
    
    bfs(0, digits.size(), "", ans, digits);

    return ans;
}

void Solution::printVector(vector<string> &vec) {
   
    for(string s: vec) 
        cout << s << ' ';

    cout << '\n';
}

int main(void) {

    Solution s;

    /* Test 1: */ 
    cout << "Test 1:\n";

    string digits1 = "23";

    cout << "Inputs: " << digits1 << '\n';

    vector<string> res1 = letterCombinations(digits1);
 
    cout << "Result: ";
    s.printVector(res1);

    /* Test 2: */
    cout << "Test 2:\n";

    string digits2 = "";
    
    cout << "Inputs: Empty string" << '\n';

    vector<string> res2 = letterCombinations(digits2);
 
    cout << "Result: ";
    s.printVector(res2);

    /* Test 3: */
    cout << "Test 3:\n";

    string digits3 = "2";

    cout << "Inputs: " << digits3 << '\n';

    vector<string> res3 = letterCombinations(digits3);
 
    cout << "Result: ";
    s.printVector(res3);

    return EXIT_SUCCESS;
}
