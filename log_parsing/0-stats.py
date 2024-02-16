#!/usr/bin/python3
"""
script that reads stdin line by line and computes metric
"""


import sys

# Initialize variables to store metrics
total_file_size = 0
status_counts = {200: 0, 301: 0, 400: 0, 401: 0, 403: 0, 404: 0, 405: 0, 500: 0}
line_count = 0

try:
    # Iterate over each line in the standard input
    for line in sys.stdin:
        line_count += 1

        # Split the input line into its components
        parts = line.split()
        
        # Check if the line has the expected number of components
        if len(parts) != 7:
            # Skip the line if the format is not as expected
            continue
        
        # Extract file size and status code from the line
        file_size = int(parts[-1])
        status_code = int(parts[-2])

        # Update total file size
        total_file_size += file_size

        # Update status code count
        if status_code in status_counts:
            status_counts[status_code] += 1

        # Check if 10 lines have been processed
        if line_count % 10 == 0:
            # Print the statistics
            print("File size:", total_file_size)
            for status_code, count in sorted(status_counts.items()):
                if count > 0:
                    print(f"{status_code}: {count}")
            print()
            # Flush the output to ensure it's immediately visible
            sys.stdout.flush()

except KeyboardInterrupt:
    # If interrupted by the user, print the final statistics
    print("File size:", total_file_size)
    for status_code, count in sorted(status_counts.items()):
        if count > 0:
            print(f"{status_code}: {count}")
