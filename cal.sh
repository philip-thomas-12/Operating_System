#!/bin/bash

# Read number from input file
read num < input.txt

# Output file
output="table.txt"
echo "Multiplication Table of $num" > $output

# Generate multiplication table
for i in {1..10}
do
    echo "$num x $i = $((num * i))" >> $output
done

echo "Multiplication table written to $output"
