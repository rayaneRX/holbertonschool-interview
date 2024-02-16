#!/usr/bin/python3
"""
Log parsing
"""

import sys


if __name__ == '__main__':

    total_filesize = 0
    line_count = 0
    http_status_codes = [
        "200", "301", "400", "401",
        "403", "404", "405", "500"
    ]
    status_code_stats = {code: 0 for code in http_status_codes}

    def print_statistics(stats: dict, file_size: int) -> None:
        """
        Prints the accumulated statistics
        """
        print("File size: {:d}".format(file_size))
        for code, count in sorted(stats.items()):
            if count:
                print("{}: {}".format(code, count))

    try:
        for line in sys.stdin:
            line_count += 1
            data = line.split()
            try:
                status_code = data[-2]
                if status_code in status_code_stats:
                    status_code_stats[status_code] += 1
            except BaseException:
                pass
            try:
                total_filesize += int(data[-1])
            except BaseException:
                pass
            if line_count % 10 == 0:
                print_statistics(status_code_stats, total_filesize)
        print_statistics(status_code_stats, total_filesize)
    except KeyboardInterrupt:
        print_statistics(status_code_stats, total_filesize)
        raise
