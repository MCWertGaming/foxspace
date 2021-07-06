#!/usr/bin/env bash
set -ex

# run unit tests
ctest -j10 -C Release -T test --output-on-failure -T test --output-on-failure
