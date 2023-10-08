#!/usr/bin/python3

class Solution:
    '''
        Given a string s consisting of words and spaces, 
        return the length of the last word in the string.

        A word is a maximal substring consisting of non-space characters only.


    '''
    def lastWord(self, s: str) -> str:
        
        last_word = ''
        length = len(s)

        for i in range(length-1, 0, -1):
            
            if s[i] == ' ' and i != 0:
                return last_word[::-1]
            else:
                last_word += s[i]

    def lengthOfLastWord(self, s: str) -> int:
        
        last_word = self.lastWord(s.strip())
        
        return len(last_word) 
        
if __name__ == '__main__':

    s = Solution()

    # Test 1:
    
    print('Test 1:')
    
    str1 = 'Hello World'
    
    print('Text: \"' + str1, end = '')
    print('\"') 

    print('Length of the last word: ' + str(s.lengthOfLastWord(str1)))

    # Test 2:
    
    print('\nTest 2:')
    
    str2 = '   fly me   to   the moon  '
    
    print('Text: \"' + str2, end = '')
    print('\"') 

    print('Length of the last word: ' + str(s.lengthOfLastWord(str2)))

    # Test 3:

    print('\nTest 3:')
    
    str3 = 'luffy is still joyboy'
    
    print('Text: \"' + str3, end = '')
    print('\"') 

    print('Length of the last word: ' + str(s.lengthOfLastWord(str3)))  
