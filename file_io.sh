#!/bin/bash

# 1. Single Character
echo -n "A" > file1.txt
read -n 1 char < file1.txt
echo "Single Character: $char"

# 2. Set of Characters
echo -n "ABCDE" > file2.txt
read -n 4 chars < file2.txt
echo "Set of Characters: $chars"


# 3. Single String
echo "HelloWorld" > file3.txt
read str < file3.txt
echo "Single String: $str"

# 4. Set of Strings (Multiple Lines)
echo -e "One\nTwo\nThree" > file4.txt
echo "Set of Strings:"
while read line; do
    echo "String: $line"
done < file4.txt

# 5. Single Number
echo "42" > file5.txt
read num < file5.txt
echo "Single Number: $num"

# 6. Set of Numbers
echo -e "10\n20\n30\n40" > file6.txt
echo "Set of Numbers:"
while read number; do
    echo "Number: $number"
done < file6.txt
