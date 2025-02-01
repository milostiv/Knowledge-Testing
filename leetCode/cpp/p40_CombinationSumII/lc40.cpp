#include <iostream>
#include <vector>
#include <algorithm>

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

        if(target < 0) return;
        
        if(target == 0) {

            sol.push_back(temp);
            return;
        }

        for(int i=index; i < candidates.size(); i++) {

            if(i>index && candidates[i] == candidates[i-1]) continue;
                
            temp.push_back(candidates[i]);
            findNumbers(candidates, target - candidates[i], sol, temp, i+1);
            temp.pop_back();
        }            
    }

    Matrix combinationSum2(Row& candidates, int target) {
    
        Matrix sol;     
        Row temp;

        std::sort(candidates.begin(), candidates.end());        
        findNumbers(candidates, target, sol, temp, 0);
    
        return sol;
    }
};

int main(void) {

    Solution s;

    // Test 1:
    cout << "Test 1:" << '\n';
    Row candidates1 = {10, 1, 2, 7, 6, 1, 5};
    cout << "Candidates 1: " << candidates1;
    int target1 = 8;
    cout << "Target 1: " << target1 << '\n';

    Matrix sol1 = s.combinationSum2(candidates1, target1);
    cout << "Solution 1:\n" << sol1;

    // Test 2:    
    cout << "Test 2:" << '\n';
    Row candidates2 = {2, 5, 2, 1, 2};
    cout << "Candidates 2: " << candidates2;
    int target2 = 5;
    cout << "Target 2: " << target2 << '\n';

    Matrix sol2 = s.combinationSum2(candidates2, target2);
    cout << "Solution 2:\n" << sol2;

    return EXIT_SUCCESS;
}
