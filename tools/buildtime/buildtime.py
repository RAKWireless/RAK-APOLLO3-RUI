#!/bin/python3

import re
import sys
from datetime import datetime
import time
if len(sys.argv) < 2:
    print("no argument")
    sys.exit()

t = datetime.now()
buildtime = t.strftime("%H%M%S")
builddate = t.strftime("%Y%m%d")

reading_file = open(sys.argv[1])
new_content = ""
for line in reading_file:
    if re.search("define BUILD_TIME",line):
        line = '#define BUILD_TIME "%s"\n'%buildtime
    if re.search("define BUILD_DATE",line):
        line = '#define BUILD_DATE "%s"\n'%builddate
    new_content += line
reading_file.close()
writing_file = open(sys.argv[1],"w")
writing_file.write(new_content)
writing_file.close()
