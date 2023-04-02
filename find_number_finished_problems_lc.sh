#!/bin/bash

echo "Number of completed LeetCode problems in C:"
c=$(find leetCode/c/ -mindepth 1 -type f -name "*.c" -printf x | wc -c)
echo "$c"

# Change 5 line of README.md file to update the number of finished C/C++ problems
sed -i "5 s/.*/- [ ] [$c\/50] Complete 50 *LeetCode* problems in **C\/C++**/" README.md

echo "Number of completed LeetCode problems in Python:"
py=$(find leetCode/python/ -mindepth 1 -type f -name "*.py" -printf x | wc -c)
echo "$py"

# Change 5 line of README.md file to update the number of finished Python problems
sed -i "6 s/.*/- [ ] [$py\/50] Complete 50 *LeetCode* problems in **Python**/" README.md
