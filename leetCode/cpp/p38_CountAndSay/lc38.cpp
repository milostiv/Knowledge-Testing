#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    string countAndSay(int n);
};

string Solution::countAndSay(int n) {

    string res = "1";

    for(int i=1; i<n; i++) {

        int count = 0;
        char prev = '.';
        string curr_str = "";

        for(char ch : res) {
            if(ch == prev || prev == '.')
                count++;
            else {
                curr_str += to_string(count) + prev;        
                count = 1;
            }
            prev = ch;
        }
        
        curr_str += to_string(count) + prev;
        res = curr_str;
    }
 
    return res;    
}

int main(void) {

    Solution s;

    /* Test 1: */ 
    cout << "Test 1:\n";

    int n1 = 1;

    cout << "Input 1: " << n1 << '\n';

    cout << "Solution 1: " << s.countAndSay(n1) << '\n';

    /* Test 2: */ 
    cout << "\nTest 2:\n";

    int n2 = 4;

    cout << "Input 2: " << n2 << '\n';

    cout << "Solution 2: " << s.countAndSay(n2) << '\n';

    return EXIT_SUCCESS;
}
