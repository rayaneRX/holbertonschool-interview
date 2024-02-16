#!/usr/bin/python3
"""
Script that reads stdin line by line and computes metrics
"""
import sys

# Dictionary to store counts of different HTTP status codes
status_code_counts = {
    '200': 0,
    '301': 0,
    '400': 0,
    '401': 0,
    '403': 0,
    '404': 0,
    '405': 0,
    '500': 0
}
total_file_size = 0  # Variable to store total size of files processed
lines_processed = 0  # Counter for number of lines processed

try:
    # Loop through each line from standard input (stdin)
    for line in sys.stdin:
        # Split the line by space to extract necessary information
        data = line.split(' ')

        # Check if line contains enough elements to extract status and size
        if len(data) > 6:
            status_code, size = data[-2:]  # Extract status code and size
            total_file_size += int(size)   # Add size to total_file_size
            # Check if status code is in status_code_counts
            if status_code in status_code_counts:
                # Increment count for this status code
                status_code_counts[status_code] += 1
            lines_processed += 1  # Increment lines_processed counter

        # Print metrics every 10 lines processed
        if lines_processed % 10 == 0:
            print('File size: {}'.format(total_file_size))
            # Print status code counts in sorted order
            for (code, count) in sorted(status_code_counts.items()):
                if count > 0:
                    print('{}: {}'.format(code, count))
            lines_processed = 0  # Reset lines_processed counter

except KeyboardInterrupt:
    pass  # Handle KeyboardInterrupt (Ctrl+C) gracefully

finally:
    # Print final metrics after
    print('File size: {}'.format(total_file_size))
    for (code, count) in sorted(status_code_counts.items()):
        if count > 0:
            print('{}: {}'.format(code, count))
