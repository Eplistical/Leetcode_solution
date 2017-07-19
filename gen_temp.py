#!/usr/bin/env python3

import sys
import os

title = "{:03d}_{}".format(int(sys.argv[1][:-1]), "".join(sys.argv[2:]))
os.system('cp -r Prototype ' + title)
os.system('mv ' + title + '/source.cpp ' + title + '/' + title + '.cpp')
os.system('mkdir ' + title + '/build');
