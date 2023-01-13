#!/bin/bash

# Given a text file file.txt, transpose its content.
# You may assume that each row has the same number of columns, 
# and each field is separated by the ' ' character.

file="file.txt"

# Get the number of lines
i=$(wc -l $file | awk '{print $1;}') 

# Get the number of words in line
j=$(wc -w $file | awk '{print $1;}')
j=$(($j/$i))

while read -r line; do 
	echo "$line"
done <$file
