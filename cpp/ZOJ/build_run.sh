#!/bin/bash
# =============================================================================
# C++ Build & Run Script for ZOJ problems
#
# Usage:
#   ./build_run.sh Zoj1004.cpp              # compile + run (interactive)
#   ./build_run.sh Zoj1004.cpp < input.txt   # compile + run with input file
#   ./build_run.sh --build-only Zoj1004.cpp  # compile only, don't run
#   ./build_run.sh --clean                   # remove all built .exe files
#
# Environment: removes Anaconda's old GCC 5.3.0 mingw-w64 DLL path (the
#   only Anaconda entry that conflicts with MSYS2 UCRT64 GCC 15.2.0),
#   then puts MSYS2 at the front. Python still works fine.
# =============================================================================

set -e

SCRIPT_DIR="$(cd "$(dirname "$0")" && pwd)"

# --- 只删除 Anaconda 的老 GCC 5.3.0 DLL 路径 ---
# 不删 Anaconda Python — 很多脚本可能需要 python
fix_path() {
    export PATH=$(printf '%s' "$PATH" | awk -v RS=':' '
        /anaconda3\/Library\/mingw-w64\/bin/ { next }
        /anaconda3\/Library\/usr\/bin/        { next }
        !seen[$0]++ { printf "%s%s", sep, $0; sep=":" }
        END { printf "\n" }
    ')
    export PATH="/d/mys64/ucrt64/bin:/d/mys64/usr/bin:$PATH"
    export PATH=$(printf '%s' "$PATH" | awk -v RS=':' '!seen[$0]++ { printf "%s%s", sep, $0; sep=":" } END { printf "\n" }')
}

fix_path

BUILD_ONLY=false

case "${1:-}" in
    --clean)
        echo "Cleaning built executables..."
        rm -f "$SCRIPT_DIR"/*.exe "$SCRIPT_DIR"/*.o
        echo "Done."
        exit 0
        ;;
    --build-only)
        BUILD_ONLY=true
        shift
        ;;
    -h|--help)
        echo "Usage: $0 [--build-only|--clean] <file.cpp>"
        echo ""
        echo "  file.cpp        Compile and run the specified C++ file"
        echo "  --build-only    Compile only, skip running"
        echo "  --clean         Remove all *.exe and *.o files"
        exit 0
        ;;
esac

CPP_FILE="${1:-}"
if [ -z "$CPP_FILE" ]; then
    echo "Usage: $0 [--build-only|--clean] <file.cpp>"
    exit 1
fi

if [ ! -f "$CPP_FILE" ]; then
    echo "Error: file not found: $CPP_FILE"
    exit 1
fi

BASENAME="${CPP_FILE%.cpp}"
EXE_FILE="${BASENAME}.exe"

echo "================================================"
echo " Compiler: $(g++ --version | head -1)"
echo " Target:   $CPP_FILE -> $EXE_FILE"
echo "================================================"

# Compile
echo "[BUILD] Compiling $CPP_FILE ..."
g++ -std=c++17 -O2 -Wall -o "$EXE_FILE" "$CPP_FILE"
echo "[BUILD] Success: $EXE_FILE"

if $BUILD_ONLY; then
    exit 0
fi

# Run
echo ""
echo "[RUN] Executing $EXE_FILE ..."
echo "----------------------------------------"
"./$EXE_FILE"
RUN_EXIT=$?
echo "----------------------------------------"
echo "[RUN] Exit code: $RUN_EXIT"
