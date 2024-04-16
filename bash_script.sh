#!/bin/bash

# Check if exactly one argument is provided
if [ "$#" -ne 1 ]; then
    echo "Usage: $0 <duration in seconds>"
    exit 1
fi

# Ensure the argument is a number
if ! [[ "$1" =~ ^[0-9]+$ ]]; then
    echo "Error: Duration must be a positive integer."
    exit 1
fi

duration=$1

# Start the C program in the background
./threads &
program_pid=$!

echo "Program started with PID $program_pid, will send SIGINT after $duration seconds."

# Wait for the specified duration
sleep $duration

# Send SIGINT signal to the program
kill -SIGINT $program_pid

# Wait for the program to exit
wait $program_pid
echo "Program has exited cleanly."

exit 0
