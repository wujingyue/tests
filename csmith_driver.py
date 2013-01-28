#!/usr/bin/env python

import os
import sys
import re

CSMITH_HOME = '/home/jingyue/Research/csmith-2.1.0'

if __name__ == '__main__':
    while True:
        os.system(CSMITH_HOME + '/src/csmith > test.c')
        os.system('clang test.c -o test -I' + CSMITH_HOME + '/runtime')
        os.system('clang test.c -o test.bc -c -emit-llvm -I' + CSMITH_HOME + \
                '/runtime')
        ret = os.system('dynaa_offline.py test --all --time-limit 10')
        if ret != 0:
            break
