#!/bin/bash

set -e

mkdir -p app/build/

cmake -S ./app -B ./app/build
cmake --build ./app/build

./app/build/lib_program
