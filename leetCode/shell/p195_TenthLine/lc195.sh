#!/bin/bash

# Read from the file file.txt and output the tenth line to stdout.

file_name=$1

if [ $# -lt 1 ]; then
	echo "ERROR: File name not specified"
	exit 1
fi

# Get the number of lines in file.txt and keep just the first word of the output string
num_ln=$(wc -l $file_name | awk '{print $1;}')

if [ $num_ln -lt 10 ]; then 
	echo "ERROR: Number of lines in file.txt is less than 10"
	exit 1
fi

tenth_ln=$(head -n 10 $file_name | tail -n 1)

echo "Tenth line: $tenth_ln"
