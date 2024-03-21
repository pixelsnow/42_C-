#!/bin/bash

# Function to generate a sequence of non-repeated random numbers
generate_unique_random_numbers() {
    local count=$1
    local min=$2
    local max=$3

    # Generate a list of all possible numbers
    local all_numbers=$(seq $min $max)

    # Shuffle the list of numbers using gshuf
    local shuffled_numbers=$(echo $all_numbers | tr ' ' '\n' | gshuf | tr '\n' ' ')

    # Extract the first count numbers from the shuffled list
    local unique_numbers=$(echo $shuffled_numbers | cut -d' ' -f1-$count)

    # Output the sequence of non-repeated random numbers to stdout
    echo $unique_numbers
}

# Generate 3000 non-repeated random numbers between 1 and 100000
generate_unique_random_numbers 3000 1 100000
