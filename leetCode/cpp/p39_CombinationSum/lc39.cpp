#include <iostream>
#include <vector>

using std::cout;

typedef std::vector<std::vector<int>> Matrix;
typedef std::vector<int> Row;

std::ostream& operator << (std::ostream& os, const Row row) {
    
    for(auto i: row) 
        os << i << " "; 

    os << '\n';

    return os;
}

std::ostream& operator << (std::ostream& os, const Matrix mat) {

    for(auto i: mat)
        os << i;

    os << '\n';

    return os;
}

class Solution {

public:
    void findNumbers(Row candidates, int target, Matrix& sol, Row& temp, int index) {
        
        if(target == 0) {

            sol.push_back(temp);
            return;
        }

        for(int i=0; i < candidates.size(); i++) {
            
            if(target - candidates[i] >= 0) {
                
                temp.push_back(candidates[i]);
                findNumbers(candidates, target - candidates[i], sol, temp, i);
                temp.pop_back();
            }
        }            
    }

    Matrix combinationSum(Row& candidates, int target) {
    
        Matrix sol;     
        Row temp;

        findNumbers(candidates, target, sol, temp, 0);
    
        return sol;
    }
};

int main() {

    Solution s;

    // Test 1:
    cout << "Test 1:" << '\n';
    Row candidates1 = {2, 3, 6, 7};
    cout << "Candidates 1: " << candidates1;
    int target1 = 7;
    cout << "Target 1: " << target1 << '\n';

    Matrix sol1 = s.combinationSum(candidates1, target1);
    cout << "Solution 1:\n" << sol1;

    // Test 2:
    cout << "Test 2:" << '\n';
    Row candidates2 = {2, 3, 5};
    cout << "Candidates 2: " << candidates2;
    int target2 = 8;
    cout << "Target 2: " << target2 << '\n';

    Matrix sol2 = s.combinationSum(candidates2, target2);
    cout << "Solution 2:\n" << sol2;

    // Test 3:
    cout << "Test 3:" << '\n';
    Row candidates3 = {2};
    cout << "Candidates 3: " << candidates3;
    int target3 = 1;
    cout << "Target 3: " << target3 << '\n';

    Matrix sol3 = s.combinationSum(candidates3, target3);
    cout << "Solution 3:\n" << sol3;
 
    return EXIT_SUCCESS;
}
