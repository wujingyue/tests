#!/usr/bin/env python

import os
import sys
import pty
import subprocess

master, slave = os.openpty()
master = os.fdopen(master)

child = subprocess.Popen('ls --color=auto', shell=True, stdout=slave, close_fds=True)
while child.poll() is None:
    line = master.readline()
    sys.stdout.write(line)
child.wait()
