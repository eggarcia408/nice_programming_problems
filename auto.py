#!/user/bin/python3

import os
import subprocess
import shutil

directories = os.listdir(".")

if "auto.py" in directories:
    directories.remove("auto.py")

print (os.getcwd()) # will give you jdjdjdj/nice_....

root_dir = os.getcwd()

print (directories)
for current in directories:
    os.chdir(root_dir + "/" + current)
    if os.path.isdir(root_dir+"/"+current+"/.git"):
        shutil.rmtree(root_dir+"/"+current+"/.git")
    os.chdir(root_dir)
