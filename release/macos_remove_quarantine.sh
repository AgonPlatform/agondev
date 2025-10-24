#!/usr/bin/env zsh
# remove_quarantine_bin.sh
# Removes the macOS "downloaded from the Internet" quarantine attribute
# from all files under the "bin/" directory next to this script.

set -euo pipefail

# Resolve the directory where this script is located
SCRIPT_DIR="$(cd "$(dirname "$0")" && pwd)"
TARGET_DIR="${SCRIPT_DIR}/bin"

echo "----------------------------------------------------"
echo " Removing quarantine attributes from:"
echo "   ${TARGET_DIR}"

if [[ ! -d "$TARGET_DIR" ]]; then
  echo "Error: bin/ directory not found at ${TARGET_DIR}"
  exit 1
fi

# Try recursive xattr removal (fast path)
if xattr -h 2>&1 | grep -q -- '-r'; then
  echo "   Using xattr -r to clear com.apple.quarantine recursively..."
  xattr -r -d com.apple.quarantine "$TARGET_DIR" 2>/dev/null || true
else
  echo "   Falling back to per-file cleanup..."
  find "$TARGET_DIR" -xdev \( -type f -o -type d -o -type l \) -print0 \
    | while IFS= read -r -d '' file; do
        if xattr -p com.apple.quarantine "$file" >/dev/null 2>&1; then
          xattr -d com.apple.quarantine "$file" 2>/dev/null || true
          echo "   Cleared: $file"
        fi
      done
fi

echo " Done! Quarantine attributes removed from bin/."
echo "----------------------------------------------------"

