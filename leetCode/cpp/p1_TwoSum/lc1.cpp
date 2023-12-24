/* Given an array of integers nums and an integer target, 
return indices of the two numbers such that they add up to target.

You may assume that each input would have exactly one solution, 
and you may not use the same element twice.

You can return the answer in any order. */

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target);
    void printVector(vector<int>& vec);
};

vector<int> Solution::twoSum(vector<int>& nums, int target) {

    unordered_map<int,int> sum;

    for(int i = 0; i < nums.size(); i++) {
        int difference = target - nums[i];
        
        if(sum.find(difference) != sum.end())
            return {sum[difference], i};
        else
            sum[nums[i]] = i; 
    }

    return {};
}

void Solution::printVector(vector<int>& vec) {
   
    for(int i: vec) 
        cout << i << ' ';

    cout << '\n';
}

int main(void) {
   
    Solution s;
 
    /* Test 1: */ 
    cout << "Test 1:\n";

    vector<int> nums1 = {2, 7, 11, 15};
    int target1 = 9;

    cout << "Inputs 1: ";
    s.printVector(nums1);

    cout << "Target 1: " << target1 << '\n';

    vector<int> sol1;
    sol1 = s.twoSum(nums1, target1); 

    cout << "Solution 1: ";
    s.printVector(sol1);
    cout << '\n';

    /* Test 2: */
    cout << "Test 2:\n";

    vector<int> nums2 = {3, 2, 4};
    int target2 = 6;

    cout << "Inputs 2: ";
    s.printVector(nums2);

    cout << "Target 2: " << target2 << '\n';

    vector<int> sol2;
    sol2 = s.twoSum(nums2, target2); 

    cout << "Solution 2: ";
    s.printVector(sol2);
    cout << '\n';

    /* Test 3: */
    cout << "Test 3:\n";

    vector<int> nums3 = {3, 3};
    int target3 = 6;

    cout << "Inputs 3: ";
    s.printVector(nums3);

    cout << "Target 3: " << target3 << '\n';

    vector<int> sol3;
    sol3 = s.twoSum(nums3, target3); 

    cout << "Solution 3: ";
    s.printVector(sol3);
    cout << '\n';

    return EXIT_SUCCESS; 
}
