#!/usr/bin/python3
"""
script that reads stdin line by line and computes metric
"""


import sys

total_file_size = 0
status_counts = {200: 0, 301: 0, 400: 0, 401: 0, 403: 0, 404: 0, 405: 0, 500: 0}
line_count = 0

try:
    for line in sys.stdin:
        line_count += 1
        parts = line.split()
        if len(parts) != 7:
            continue
        
        file_size = int(parts[-1])
        status_code = int(parts[-2])

        total_file_size += file_size

        if status_code in status_counts:
            status_counts[status_code] += 1

        if line_count % 10 == 0:
            print("File size:", total_file_size)
            for status_code, count in sorted(status_counts.items()):
                if count > 0:
                    print(f"{status_code}: {count}")
            print()
            sys.stdout.flush()

except KeyboardInterrupt:
    print("File size:", total_file_size)
    for status_code, count in sorted(status_counts.items()):
        if count > 0:
            print(f"{status_code}: {count}")
