# Missing NULL check after allocation
# CWE-476 | Severity: HIGH
# File: wolfcrypt/src/port/Espressif/esp_sdk_mem_lib.c line 397

**Risk:** Return value of malloc/realloc not checked for NULL. On allocation failure the program dereferences NULL, causing a crash or exploitable condition.

**Fix:** Always check: ptr = malloc(n); if (!ptr) { handle_error(); return; }
