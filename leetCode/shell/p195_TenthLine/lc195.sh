#!/bin/bash

# Read from the file file.txt and output the tenth line to stdout.

# Get the number of lines in file.txt and keep just the first word of the output string
num_ln=$(wc -l file.txt | awk '{print $1;}')

if [ $num_ln -lt 10 ]; then 
	echo "ERROR: Number of lines in file.txt is less than 10"
	exit 1
fi

tenth_ln=$(head -n 10 file.txt | tail -n 1)

echo "Tenth line: $tenth_ln"
