#!/usr/bin/python3

class Solution:
    '''
        Given an array of distinct integers candidates and a target integer target, 
        return a list of all unique combinations of candidates where the chosen numbers sum to target. 
        You may return the combinations in any order.

        The same number may be chosen from candidates an unlimited number of times. 
        Two combinations are unique if the frequency of at least one of the chosen numbers is different.

        The test cases are generated such that the number of unique combinations 
        that sum up to target is less than 150 combinations for the given input.
    '''
    def find_numbers(self, candidates: list, target: int, sol, temp: list, index: int):        

        if target == 0:
    
            sol.append(list(temp))
            return

        for i in range(index, len(candidates)):

            if target - candidates[i] >= 0:
                
                temp.append(candidates[i])
                self.find_numbers(candidates, target - candidates[i], sol, temp, i)
                temp.remove(candidates[i])
                 

    def combinationSum(self, candidates: list, target: int):

        sol = []
        temp = []
    
        self.find_numbers(candidates, target, sol, temp, 0)
            
        return sol

if __name__ == '__main__':

    s = Solution()
    
    # Test 1

    print('Test 1:\n')
    candidates1 = [2, 3, 6, 7]
    target1 = 7 
    print('Candidates 1: {}, Target 1: {}'.format(candidates1, target1))
    ans = s.combinationSum(candidates1, target1)
    print('Solution 1: {}'.format(ans))

    # Test 2

    print('\nTest 2:\n')
    candidates2 = [2,3,5]
    target2 = 8
    print('Candidates 2: {}, Target 2: {}'.format(candidates2, target2))
    ans = s.combinationSum(candidates2, target2)
    print('Solution 2: {}'.format(ans))

    # Test 3

    print('\nTest 3:\n')
    candidates3 = [2]
    target3 = 1
    print('Candidates 3: {}, Target 3: {}'.format(candidates3, target3))
    ans = s.combinationSum(candidates3, target3)
    print('Solution 3: {}'.format(ans))
