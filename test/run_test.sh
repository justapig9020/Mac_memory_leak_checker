#!/bin/bash

test_expect() {
    target=$1
    expect=$2
    curr=$3
    $curr/../leakcheck.sh $curr/$target > /dev/null
    ret=$?
    if [[ $ret != $expect ]]; then
        RED='\033[0;31m'
        NC='\033[0m' # No Color
        printf "$RED Target $target$NC\n"
        printf "Expect $expect, got $?\n"
        exit 1
    fi
}

GREEN='\033[1;32m'
NC='\033[0m' # No Color
curr_dir=$(dirname $0)
test_expect target/leak3 3 $curr_dir

printf "$GREEN All tests passed$NC\n"
