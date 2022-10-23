#!/bin/sh
set -e
echo Build and run...
g++ -o sounder sounder.cpp

./sounder 44100 | aplay -r 44100
