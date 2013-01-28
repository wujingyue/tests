#!/usr/bin/env python

import os
import re

if __name__ == '__main__':
    for dirpath, dirnames, filenames in os.walk('.'):
        for filename in filenames:
            if filename.endswith('.cpp') or filename.endswith('.h'):
                abs_path = os.path.join(dirpath, filename)
                old_file = open(abs_path)
                tmp_file = open('/tmp/tmp', 'w')
                for old_line in old_file:
                    new_line = re.sub('#include "common',
                                      '#include "rcs',
                                      old_line)
                    tmp_file.write(new_line)
                tmp_file.close()
                old_file.close()
                os.system('mv /tmp/tmp ' + abs_path)
