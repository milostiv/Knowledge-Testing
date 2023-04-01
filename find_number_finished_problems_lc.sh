#!/bin/bash

echo "Number of completed LeetCode problems in C:"
find leetCode/c/ -mindepth 1 -type f -name "*.c" -printf x | wc -c

echo "Number of completed LeetCode problems in Python:"
find leetCode/python/ -mindepth 1 -type f -name "*.py" -printf x | wc -c
