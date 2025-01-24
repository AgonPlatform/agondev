# Print lines until we encounter the .ifdef PREFER_OS_CRT line
$0 ~ /\.ifdef PREFER_OS_CRT/ { found_ifdef = 1; next }

# Print everything before the .ifdef PREFER_OS_CRT
!found_ifdef { print }

# Once .else is found, start printing between .else and .endif
$0 ~ /\.else/ { in_else = 1; next }

# Stop printing after .endif and reset the flag
$0 ~ /\.endif/ { in_else = 0; next }

# Print lines between .else and .endif
in_else { print }

