#!/bin/sh
set -e

files=`find . -name "*.cpp" | grep -v "./tools/*"`
filter=-build/c++11,-runtime/references,-whitespace/braces,-whitespace/indent,-whitespace/line_length,-whitespace/comments,-build/include_order,-whitespace/tab,-whitespace/newline
echo $files | xargs cpplint --filter=$filter