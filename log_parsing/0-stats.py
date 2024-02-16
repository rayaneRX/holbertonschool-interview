#!/usr/bin/python3
"""
script that reads stdin line by line and computes metric
"""


import sys
from collections import defaultdict

def print_statistics(total_file_size, status_code_counts):
    print(f"File size: {total_file_size}")
    for code in sorted(status_code_counts.keys()):
        print(f"{code}: {status_code_counts[code]}")

def process_input(line):
    parts = line.split()
    if len(parts) != 7:
        return None, None
    ip, _, _, status_code, file_size = parts[0], parts[4], parts[6], parts[8], parts[9]
    if not (status_code.isdigit() and file_size.isdigit()):
        return None, None
    return int(status_code), int(file_size)

total_file_size = 0
status_code_counts = defaultdict(int)
line_count = 0

try:
    for line in sys.stdin:
        line = line.strip()
        status_code, file_size = process_input(line)
        if status_code is None:
            continue
        total_file_size += file_size
        status_code_counts[status_code] += 1
        line_count += 1
        if line_count == 10:
            print_statistics(total_file_size, status_code_counts)
            line_count = 0
except KeyboardInterrupt:
    print_statistics(total_file_size, status_code_counts)
    sys.exit(0)
