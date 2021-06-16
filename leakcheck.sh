#!/bin/bash

path=$(dirname $0)
checker="$path"/lib/libleakcheck.dylib
DYLD_INSERT_LIBRARIES=$checker $1
exit $?
