#!/bin/bash

# Start web server in the background
python3 -m http.server &

# Watch files and rebuild on change
ls *.cpp src/*.c | entr ./build.sh