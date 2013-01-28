#!/usr/bin/env python

import re
import sys

def decrement(match_obj):
    index = int(match_obj.group(0))
    index -= 1
    return str(index)

if __name__ == '__main__':
    input_str = ''.join([line.strip() for line in sys.stdin.readlines()])
    output_str = re.sub('\\d+', decrement, input_str)
    print output_str
