#!/bin/bash

# Assign argument to variable
aem="$1"

hash_output=$(echo -n "$1" | sha256sum | awk '{print $1}')

echo "Hash output: $hash_output"

echo "Hash output: $hash_output" > "hash_output.txt"

