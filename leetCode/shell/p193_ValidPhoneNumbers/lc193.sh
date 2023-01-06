#!/bin/bash

# Given a text file file.txt that contains a list of phone numbers (one per line), 
# write a one-liner bash script to print all valid phone numbers.

# You may assume that a valid phone number must appear in one of the following two formats: 
# (xxx) xxx-xxxx or xxx-xxx-xxxx. (x means a digit)

# You may also assume each line in the text file must not contain leading or trailing white spaces.

file="file.txt"
regex1="\([0-9]{3}\) [0-9]{3}-[0-9]{4}"
regex2="[0-9]{3}-[0-9]{3}-[0-9]{4}"

echo "Phone numbers in file:"
cat $file
echo "" # New line

echo "Valid phone numbers in file:"
while read -r line; do
	if [[ $line =~ $regex1 || $line =~ $regex2 ]]; then
		echo "$line"
	fi
done <$file
