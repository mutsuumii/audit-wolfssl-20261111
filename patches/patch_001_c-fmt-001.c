# Format string vulnerability
# CWE-134 | Severity: CRITICAL
# File: IDE/Renesas/e2studio/RA6M4/test/src/wolf_client.c line 128

**Risk:** User-controlled string passed as printf format argument. Attacker reads stack memory or overwrites return addresses via %n.

**Fix:** Use a literal format string: printf("%s", user_input). Never pass user data as the format argument.
