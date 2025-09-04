#!/usr/bin/env python3

import sys
import os
import time

if len(sys.argv) < 2:
    print("Usage: buildtime.py <version.c>")
    sys.exit(1)

version_file = sys.argv[1]
fmt = "%Y-%m-%d %H:%M:%S"
build_time = time.strftime(fmt)

version_dir = os.path.dirname(version_file)
if not os.path.exists(version_dir):
    os.makedirs(version_dir)

with open(version_file, 'w') as f:
    f.write(f'const char* build_time = "{build_time}";\n')

print(f"Build time: {build_time}")