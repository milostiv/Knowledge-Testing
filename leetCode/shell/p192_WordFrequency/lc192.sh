#!/bin/bash

# Write a bash script to calculate the frequency
# of each word in a text file words.txt.
# 
# For simplicity sake, you may assume: 
# - words.txt contains only lowercase characters and space ' ' characters.
# - Each word must consist of lowercase characters only.
# - Words are separated by one or more whitespace characters.

file="words.txt"

# First trim all the empty spaces and new lines (tr ' ' '\n')
# Then sort the leftover text (sort)
# Then count the uniq words in text (uniq -c)
# Sort output in reverse order (sort -r)
# Then remove the empty spaces in the begining of the output (sed 's/^\s*//')
tr ' ' '\n' < $file | sort | uniq -c | sort -r | sed 's/^\s*//'
