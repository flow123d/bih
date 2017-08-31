import sys
build_path="/home/jb/workspace/bih/build"
sys.path+=[build_path]

#import os

#bih_file = os.path.join(build_path,"bih")
#bih_so_file = os.path.join(build_path,"bih.so")
#assert( os.path.isfile(os.path.join(build_path,"bih")) )
#import shutil
#shutil.copyfile(bih_file, bih_so_file)

import bih as m
assert m.add(1, 2) == 3

