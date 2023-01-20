#!/bin/bash

# Given a text file file.txt, transpose its content.
# You may assume that each row has the same number of columns, 
# and each field is separated by the ' ' character.

declare -A original_content
declare -A transposed_content
file="file.txt"

# Get the number of lines
i=$(wc -l $file | awk '{print $1;}') 

# Get the number of words in line
j=$(wc -w $file | awk '{print $1;}')
j=$(($j/$i))

il=1

while read -r line; do 
	jl=1
	for word in $line; do
		original_content[$il,$jl]=$word
		jl=$(($jl+1))
	done
	il=$(($il+1))
done <$file

echo "Original content:"

for ((k=1;k<=i;k++)) do	
	for ((l=1;l<=j;l++)) do
		echo -n "${original_content[$k,$l]} "
	done
	echo "" # New line
done

for ((k=1;k<=i;k++)) do	
	for ((l=1;l<=j;l++)) do
		transposed_content[$l,$k]="${original_content[$k,$l]}"
	done
done

echo "" # Empty line
echo "Transposed content:"

for ((k=1;k<=j;k++)) do	
	for ((l=1;l<=i;l++)) do
		echo -n "${transposed_content[$k,$l]} "
	done
	echo "" # New line
done
