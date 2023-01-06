#!/usr/bin/python

class Solution:
	"""
	You are given a string s and an array of strings words. All the strings of words are of the same length.
	
	A concatenated substring in s is a substring that contains all the strings of any permutation of words concatenated.
	
	For example, if words = ["ab","cd","ef"], then "abcdef", "abefcd", "cdabef", "cdefab", "efabcd", and "efcdab" are all concatenated strings. 
	"acdbef" is not a concatenated substring because it is not the concatenation of any permutation of words.
	Return the starting indices of all the concatenated substrings in s. You can return the answer in any order.
	"""

	def clear_words_from_dict(self, words_cnt: dict):
		
		for word in words_cnt:
			words_cnt[word] = 0

	def check_list_completion(self, words_cnt: dict):
		
		dict_size = len(words_cnt)
		num_of_word_inst = 0

		for word in words_cnt:
			
			if words_cnt[word] == 1:
				num_of_word_inst += 1
			
			if words_cnt[word] > 1:
				return False

		if num_of_word_inst == dict_size:
			return True
		else:
			return False
	
	def findSubstring(self, s: str, words: list) -> list:
		
		result = list()

		# Check if string exists
		if s is None or len(s) == 0 or words is None or len(words) == 0:
			return result

		words_cnt = dict()
	
		for word in words:
			words_cnt[word] = 0

		word_length = len(words[0])

		word_array_length = len(words) * word_length

		for i in range(len(s) - word_array_length + 1):
			
			self.clear_words_from_dict(words_cnt)
			word = s[i:i+3]		
	
			if word in words_cnt:
	
				words_cnt[word] += 1
		
				j = i + 3

				while s[j:j+3] in words_cnt:

					if words_cnt[s[j:j+3]] == 0:
							
						words_cnt[s[j:j+3]] += 1	
							
						if self.check_list_completion(words_cnt):
							result.append(i)
							i = i + 2
							break

						else:		
							j += 3	
					
					else:
						break
				

		return result
		
s = Solution()

# Test 1:

s1 = 'barfoothefoobarman'
words1 = ['foo','bar']

print(s.findSubstring(s1, words1))

# Test 2:

s2 = 'wordgoodgoodgoodbestword'
words2 = ['word','good','best','word']

print(s.findSubstring(s2, words2))

# Test 3:

s3 = 'barfoofoobarthefoobarman'
words3 = ['bar', 'foo', 'the']

print(s.findSubstring(s3, words3))
