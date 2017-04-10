#env bash

set -euo pipefail

function build() {
    filename="$1.cpp"
    g++ $filename
}

build $1
