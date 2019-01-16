#!/bin/sh

echo "What do I do???"

run_script() {
    echo "./run"
    echo "  Run Codeforces solution against input."
    echo "  File types    :   .py, .cc, .js"
    echo "  Usage         :   ./run"
    echo ""
}

new_script() {
    echo "./new"
    echo "  Generate new Codeforces template."
    echo "  File types    :   .py, .cc, .js"
    echo "  Usage         :   ./new cc|py|js 123 A"
    echo "  Example       :   ./new cc 4 A"
    echo "                  Generates a new C++ file for Codeforces problem 4A."
    echo ""
}

run_script
new_script

echo "Ending..."
exit