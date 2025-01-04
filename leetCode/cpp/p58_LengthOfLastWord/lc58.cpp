#include <iostream>
#include <string>

using std::cout;
using std::endl;

class Solution {

public:
    static int lengthOfLastWord(std::string s);
};

int Solution::lengthOfLastWord(std::string s) {
    
    int len = 0;

    for(int i = 0; i < s.length(); i++) {
    
        if(i != 0 && s[i] != ' ') {
            if(s[i-1] != ' ') len++;
            else len = 1;
        }
        else continue;
    }

    return len;
}

int main(void) {
    
    // Test 1:
    std::string s1 = "Hello World";
    cout << "Input string 1: " << '\"' << s1 << '\"' << endl;
    cout << "Length of last word: " << Solution::lengthOfLastWord(s1) << endl;
    
    // Test 2:
    std::string s2 = "   fly me   to   the moon  ";
    cout << "Input string 2: " << '\"' << s2 << '\"' << endl;
    cout << "Length of last word: " << Solution::lengthOfLastWord(s2) << endl;

    // Test 3:
    std::string s3 = "luffy is still joyboy";
    cout << "Input string 3: " << '\"' << s3 << '\"' << endl;
    cout << "Length of last word: " << Solution::lengthOfLastWord(s3) << endl;
            
    return EXIT_SUCCESS; 
}
