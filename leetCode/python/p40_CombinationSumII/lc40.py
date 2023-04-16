#!/usr/bin/python3

class Solution:
    '''
        Given a collection of candidate numbers (candidates) and a target number (target), 
        find all unique combinations in candidates where the candidate numbers sum to target.

        Each number in candidates may only be used once in the combination.

        Note: The solution set must not contain duplicate combinations.
    ''' 
    def find_numbers(self, candidates: list, target: int, sol, temp: list, index: int):        
        
        if target == 0 and temp not in sol:

            sol.append(temp.copy())
            return

        for i in range(index, len(candidates)):
            
            if target - candidates[i] >= 0:
                
                temp.append(candidates[i])
                self.find_numbers(candidates, target - candidates[i], sol, temp, i+1)
                temp.pop()
    
    def combinationSum2(self, candidates: list, target: int):
        
        sol = []
        temp = []

        candidates.sort()    
        self.find_numbers(candidates, target, sol, temp, 0)

        return sol

if __name__ == '__main__':

    s = Solution()

    # Test 1:
    print('Test 1:\n')
    candidates1 = [10, 1, 2, 7, 6, 1, 5] 
    target1 = 8
    print('Candidates 1: {}, Target 1: {}'.format(candidates1, target1))
    ans = s.combinationSum2(candidates1, target1)
    print('Solution 1: {}'.format(ans))

    # Test 2:
    print('\nTest 2:\n')
    candidates2 = [2, 5, 2, 1, 2] 
    target2 = 5
    print('Candidates 2: {}, Target 2: {}'.format(candidates2, target2))
    ans = s.combinationSum2(candidates2, target2)
    print('Solution 2: {}'.format(ans))
