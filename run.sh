#!/usr/bin/env bash

set -e

FILE="dash"

if [ ! -f "$FILE" ]; then
    make

    echo ""
fi

./dash

echo ""

rm dash



