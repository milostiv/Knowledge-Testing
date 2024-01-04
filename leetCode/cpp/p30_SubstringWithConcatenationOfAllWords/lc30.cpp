#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<int> findSubstring(string s, vector<string> &words);    
    void printVector(vector<string>& vec);
    void printVector(vector<int>& vec);
};

void Solution::printVector(vector<string>& vec) {
   
    for(string str: vec) 
        cout << str << ' ';

    cout << '\n';
}

void Solution::printVector(vector<int>& vec) {
   
    for(int str: vec) 
        cout << str << ' ';

    cout << '\n';
}

vector<int> Solution::findSubstring(string s, vector<string> &words) {

    unsigned int k = words.size();
    unsigned int l = words[0].length();
    vector<int> ans;
    unordered_map<string, int> count;

    if(s.empty() || words.empty())
        return {};
    
    for(const string& word : words)
        count[word]++;

    for(int i=0; i < s.length() - k * l + 1; i++) {
        unordered_map<string, int> seen;
        int j;

        for(j=0; j < k; j++) {
            const string& word = s.substr(i + j * l, l);
            seen[word]++;
 
            if(seen[word] > count[word])
                break;            
        }

        if(j == k)
            ans.push_back(i);
    }
    
    return ans;
}

int main(void) {

    Solution s;
        
    /* Test 1: */
    cout << "Test 1:\n";

    string str1 = "barfoothefoobarman";
    vector<string> words1 = {"foo", "bar"};

    cout << "String 1: " << str1 << '\n';
    cout << "Words 1: ";
    s.printVector(words1);

    vector<int> sol1 = s.findSubstring(str1, words1);
  
    cout << "Solution 1: ";
    s.printVector(sol1);
    cout << '\n';

    /* Test 2: */
    cout << "Test 2:\n";

    string str2 = "wordgoodgoodgoodbestword";
    vector<string> words2 = {"word", "good", "best", "word"};

    cout << "String 2: " << str2 << '\n';
    cout << "Words 2: ";
    s.printVector(words2);

    vector<int> sol2 = s.findSubstring(str2, words2);
  
    cout << "Solution 2: ";
    s.printVector(sol2);
    cout << '\n';

    /* Test 3: */
    cout << "Test 3:\n";

    string str3 = "barfoofoobarthefoobarman";
    vector<string> words3 = {"bar", "foo", "the"};

    cout << "String 3: " << str3 << '\n';
    cout << "Words 3: ";
    s.printVector(words3);

    vector<int> sol3 = s.findSubstring(str3, words3);
  
    cout << "Solution 3: ";
    s.printVector(sol3);
    cout << '\n';
    
    return EXIT_SUCCESS; 
}
