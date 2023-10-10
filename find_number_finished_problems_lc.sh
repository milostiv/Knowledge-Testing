#!/bin/bash

echo "Number of completed LeetCode problems in C:"
c=$(find leetCode/c/ -mindepth 1 -type f -name "*.c" -printf x | wc -c)
echo "$c"
echo "Number of completed LeetCode problems in C++:"
cpp=$(find leetCode/cpp/ -mindepth 1 -type f -name "*.cpp" -printf x | wc -c)
echo "$cpp"

# Add them together to find number of problems in C/C++
c=$(( $c + $cpp ))

if [ $c -lt 50 ]
# Change 5 line of README.md file to update the number of finished C/C++ problems
then
sed -i "5 s/.*/- [ ] [$c\/50] Complete 50 *LeetCode* problems in **C\/C++**/" README.md
else
sed -i "5 s/.*/- [x] [$c\/50] Complete 50 *LeetCode* problems in **C\/C++**/" README.md
fi

echo "Number of completed LeetCode problems in Python:"
py=$(find leetCode/python/ -mindepth 1 -type f -name "*.py" -printf x | wc -c)
echo "$py"

if [ $py -lt 50 ]
# Change 5 line of README.md file to update the number of finished Python problems
then
sed -i "6 s/.*/- [ ] [$py\/50] Complete 50 *LeetCode* problems in **Python**/" README.md
else
sed -i "6 s/.*/- [x] [$py\/50] Complete 50 *LeetCode* problems in **Python**/" README.md
fi
