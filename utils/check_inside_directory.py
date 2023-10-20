

import os
import re
from collections import Counter
import argparse

# Argument parsing setup
parser = argparse.ArgumentParser(description="Check unique filename prefixes in a directory.")
parser.add_argument('--dir', required=True, help="Path to the directory to check.")
args = parser.parse_args()

# Get list of all files in directory
file_list = os.listdir(args.dir)

# Regular expression pattern for matching non-digit characters at the start of the filename
pattern = re.compile(r'^\D*')

# regular expression pattern for matching non-digit characters in the whole filename


# Extract prefixes from filenames
prefixes = [pattern.match(filename).group() for filename in file_list]


# straight print out unique prefix name when found one 
# for prefix in prefixes:
    # print(prefix)


# Count occurrences of each prefix
prefix_counts = Counter(prefixes)

# Generate unique prefixes list from prefix_counts keys
unique_prefixes = list(prefix_counts.keys())

# Print unique prefixes with their counts
for unique_prefix in unique_prefixes:
    print(f'{unique_prefix}: {prefix_counts.get(unique_prefix, 0)}')




