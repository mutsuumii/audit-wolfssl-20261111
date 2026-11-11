# Security audit: wolfSSL/wolfssl

Date: 2026-11-11 | Auditor: [mutsuumii](https://github.com/mutsuumii)

## Summary

Found 192 issue(s): 6 critical, 186 high.

## Findings

### 1. [CRITICAL] Format string vulnerability

**CWE-134** | `IDE/Renesas/e2studio/RA6M4/test/src/wolf_client.c` line 128

User-controlled string passed as printf format argument. Attacker reads stack memory or overwrites return addresses via %n.

```
printf("ERROR: can't load certificate data\n");
```

**Fix:** Use a literal format string: printf("%s", user_input). Never pass user data as the format argument.
---

### 2. [HIGH] Use-after-free pattern

**CWE-416** | `IDE/Renesas/e2studio/RA6M4/test/src/wolf_client.c` line 283

Freed pointer not immediately set to NULL. Dangling pointer reuse corrupts heap and can lead to code execution.

```
wolfSSL_free(ssl);
```

**Fix:** Set pointer to NULL immediately after free(). Enable AddressSanitizer in CI: -fsanitize=address.
---

### 3. [HIGH] Use-after-free pattern

**CWE-416** | `IDE/Renesas/e2studio/RA6M4/test/src/wolf_client.c` line 308

Freed pointer not immediately set to NULL. Dangling pointer reuse corrupts heap and can lead to code execution.

```
wolfSSL_CTX_free(client_ctx);
```

**Fix:** Set pointer to NULL immediately after free(). Enable AddressSanitizer in CI: -fsanitize=address.
---

### 4. [CRITICAL] Format string vulnerability

**CWE-134** | `IDE/iotsafe/memory-tls.c` line 468

User-controlled string passed as printf format argument. Attacker reads stack memory or overwrites return addresses via %n.

```
printf("++++++ Server received msg from client: '%s'\n", buf);
```

**Fix:** Use a literal format string: printf("%s", user_input). Never pass user data as the format argument.
---

### 5. [HIGH] Use-after-free pattern

**CWE-416** | `IDE/iotsafe/memory-tls.c` line 495

Freed pointer not immediately set to NULL. Dangling pointer reuse corrupts heap and can lead to code execution.

```
wolfSSL_free(cli_ssl);
```

**Fix:** Set pointer to NULL immediately after free(). Enable AddressSanitizer in CI: -fsanitize=address.
---

### 6. [HIGH] Use-after-free pattern

**CWE-416** | `IDE/iotsafe/memory-tls.c` line 496

Freed pointer not immediately set to NULL. Dangling pointer reuse corrupts heap and can lead to code execution.

```
wolfSSL_CTX_free(cli_ctx);
```

**Fix:** Set pointer to NULL immediately after free(). Enable AddressSanitizer in CI: -fsanitize=address.
---

### 7. [HIGH] Use-after-free pattern

**CWE-416** | `IDE/iotsafe/memory-tls.c` line 497

Freed pointer not immediately set to NULL. Dangling pointer reuse corrupts heap and can lead to code execution.

```
wolfSSL_free(srv_ssl);
```

**Fix:** Set pointer to NULL immediately after free(). Enable AddressSanitizer in CI: -fsanitize=address.
---

### 8. [HIGH] Use-after-free pattern

**CWE-416** | `IDE/iotsafe/memory-tls.c` line 498

Freed pointer not immediately set to NULL. Dangling pointer reuse corrupts heap and can lead to code execution.

```
wolfSSL_CTX_free(srv_ctx);
```

**Fix:** Set pointer to NULL immediately after free(). Enable AddressSanitizer in CI: -fsanitize=address.
---

### 9. [HIGH] Use-after-free pattern

**CWE-416** | `src/quic.c` line 1302

Freed pointer not immediately set to NULL. Dangling pointer reuse corrupts heap and can lead to code execution.

```
wolfSSL_EVP_PKEY_CTX_free(pctx);
```

**Fix:** Set pointer to NULL immediately after free(). Enable AddressSanitizer in CI: -fsanitize=address.
---

### 10. [HIGH] Use-after-free pattern

**CWE-416** | `src/quic.c` line 1346

Freed pointer not immediately set to NULL. Dangling pointer reuse corrupts heap and can lead to code execution.

```
wolfSSL_EVP_PKEY_CTX_free(pctx);
```

**Fix:** Set pointer to NULL immediately after free(). Enable AddressSanitizer in CI: -fsanitize=address.
---

### 11. [HIGH] Use-after-free pattern

**CWE-416** | `src/quic.c` line 1391

Freed pointer not immediately set to NULL. Dangling pointer reuse corrupts heap and can lead to code execution.

```
wolfSSL_EVP_PKEY_CTX_free(pctx);
```

**Fix:** Set pointer to NULL immediately after free(). Enable AddressSanitizer in CI: -fsanitize=address.
---

### 12. [HIGH] Use-after-free pattern

**CWE-416** | `src/quic.c` line 1413

Freed pointer not immediately set to NULL. Dangling pointer reuse corrupts heap and can lead to code execution.

```
wolfSSL_EVP_CIPHER_CTX_free(ctx);
```

**Fix:** Set pointer to NULL immediately after free(). Enable AddressSanitizer in CI: -fsanitize=address.
---

### 13. [HIGH] Use-after-free pattern

**CWE-416** | `tests/api/test_compress.c` line 812

Freed pointer not immediately set to NULL. Dangling pointer reuse corrupts heap and can lead to code execution.

```
wolfSSL_free(ssl);
```

**Fix:** Set pointer to NULL immediately after free(). Enable AddressSanitizer in CI: -fsanitize=address.
---

### 14. [HIGH] Use-after-free pattern

**CWE-416** | `tests/api/test_compress.c` line 813

Freed pointer not immediately set to NULL. Dangling pointer reuse corrupts heap and can lead to code execution.

```
wolfSSL_CTX_free(ctx);
```

**Fix:** Set pointer to NULL immediately after free(). Enable AddressSanitizer in CI: -fsanitize=address.
---

### 15. [HIGH] Use-after-free pattern

**CWE-416** | `doc/dox_comments/header_files/dh.h` line 320

Freed pointer not immediately set to NULL. Dangling pointer reuse corrupts heap and can lead to code execution.

```
wolfSSL_DH_free(dh);
```

**Fix:** Set pointer to NULL immediately after free(). Enable AddressSanitizer in CI: -fsanitize=address.
---

### 16. [HIGH] Use-after-free pattern

**CWE-416** | `doc/dox_comments/header_files/dh.h` line 359

Freed pointer not immediately set to NULL. Dangling pointer reuse corrupts heap and can lead to code execution.

```
wolfSSL_DH_free(dh);
```

**Fix:** Set pointer to NULL immediately after free(). Enable AddressSanitizer in CI: -fsanitize=address.
---

### 17. [HIGH] Use-after-free pattern

**CWE-416** | `wolfcrypt/src/sp_dsp32.c` line 4531

Freed pointer not immediately set to NULL. Dangling pointer reuse corrupts heap and can lead to code execution.

```
void wc_ecc_fp_free(void)
```

**Fix:** Set pointer to NULL immediately after free(). Enable AddressSanitizer in CI: -fsanitize=address.
---

### 18. [HIGH] Integer overflow in size calculation

**CWE-190** | `wolfcrypt/src/port/intel/quickassist_sync.c` line 1694

Arithmetic in allocator argument can overflow to a small value, causing under-allocation and subsequent heap overflow.

```
ptr = malloc(size + sizeof(qaeMemHeader));
```

**Fix:** Validate sizes before arithmetic. Use calloc(n, size) for n*size. Check: if (n > SIZE_MAX / size) abort().
---

### 19. [HIGH] Use-after-free pattern

**CWE-416** | `wolfcrypt/src/port/intel/quickassist_sync.c` line 1659

Freed pointer not immediately set to NULL. Dangling pointer reuse corrupts heap and can lead to code execution.

```
free(ptr);
```

**Fix:** Set pointer to NULL immediately after free(). Enable AddressSanitizer in CI: -fsanitize=address.
---

### 20. [HIGH] Missing NULL check after allocation

**CWE-476** | `wolfcrypt/src/port/intel/quickassist_sync.c` line 1694

Return value of malloc/realloc not checked for NULL. On allocation failure the program dereferences NULL, causing a crash or exploitable condition.

```
ptr = malloc(size + sizeof(qaeMemHeader));
```

**Fix:** Always check: ptr = malloc(n); if (!ptr) { handle_error(); return; }
---

### 21. [HIGH] Use-after-free pattern

**CWE-416** | `tests/api/test_mlkem.h` line 40

Freed pointer not immediately set to NULL. Dangling pointer reuse corrupts heap and can lead to code execution.

```
int test_wc_mlkem_cb_free(void);
```

**Fix:** Set pointer to NULL immediately after free(). Enable AddressSanitizer in CI: -fsanitize=address.
---

### 22. [CRITICAL] Format string vulnerability

**CWE-134** | `linuxkm/lkcapi_ecdsa_glue.c` line 1147

User-controlled string passed as printf format argument. Attacker reads stack memory or overwrites return addresses via %n.

```
pr_err("error: allocating raw_sig buffer failed.\n");
```

**Fix:** Use a literal format string: printf("%s", user_input). Never pass user data as the format argument.
---

### 23. [CRITICAL] Format string vulnerability

**CWE-134** | `linuxkm/lkcapi_ecdsa_glue.c` line 1312

User-controlled string passed as printf format argument. Attacker reads stack memory or overwrites return addresses via %n.

```
pr_err("error: allocating param_copy buffer failed.\n");
```

**Fix:** Use a literal format string: printf("%s", user_input). Never pass user data as the format argument.
---

### 24. [HIGH] Integer overflow in size calculation

**CWE-190** | `linuxkm/lkcapi_ecdsa_glue.c` line 667

Arithmetic in allocator argument can overflow to a small value, causing under-allocation and subsequent heap overflow.

```
work_buffer = (byte *)malloc((2U * ctx->curve_len) + ECC_MAX_SIG_SIZE);
```

**Fix:** Validate sizes before arithmetic. Use calloc(n, size) for n*size. Check: if (n > SIZE_MAX / size) abort().
---

### 25. [HIGH] Integer overflow in size calculation

**CWE-190** | `linuxkm/lkcapi_ecdsa_glue.c` line 803

Arithmetic in allocator argument can overflow to a small value, causing under-allocation and subsequent heap overflow.

```
sig = malloc(sig_len + hash_len);
```

**Fix:** Validate sizes before arithmetic. Use calloc(n, size) for n*size. Check: if (n > SIZE_MAX / size) abort().
---

### 26. [HIGH] Integer overflow in size calculation

**CWE-190** | `linuxkm/lkcapi_ecdsa_glue.c` line 1310

Arithmetic in allocator argument can overflow to a small value, causing under-allocation and subsequent heap overflow.

```
param_copy = (byte *)malloc(sig_len + hash_len);
```

**Fix:** Validate sizes before arithmetic. Use calloc(n, size) for n*size. Check: if (n > SIZE_MAX / size) abort().
---

### 27. [HIGH] Use-after-free pattern

**CWE-416** | `linuxkm/lkcapi_ecdsa_glue.c` line 159

Freed pointer not immediately set to NULL. Dangling pointer reuse corrupts heap and can lead to code execution.

```
free(key);
```

**Fix:** Set pointer to NULL immediately after free(). Enable AddressSanitizer in CI: -fsanitize=address.
---

### 28. [HIGH] Use-after-free pattern

**CWE-416** | `linuxkm/lkcapi_ecdsa_glue.c` line 169

Freed pointer not immediately set to NULL. Dangling pointer reuse corrupts heap and can lead to code execution.

```
wc_ecc_free(key);
```

**Fix:** Set pointer to NULL immediately after free(). Enable AddressSanitizer in CI: -fsanitize=address.
---

### 29. [HIGH] Use-after-free pattern

**CWE-416** | `linuxkm/lkcapi_ecdsa_glue.c` line 171

Freed pointer not immediately set to NULL. Dangling pointer reuse corrupts heap and can lead to code execution.

```
free(key);
```

**Fix:** Set pointer to NULL immediately after free(). Enable AddressSanitizer in CI: -fsanitize=address.
---

### 30. [HIGH] Use-after-free pattern

**CWE-416** | `linuxkm/lkcapi_ecdsa_glue.c` line 729

Freed pointer not immediately set to NULL. Dangling pointer reuse corrupts heap and can lead to code execution.

```
free(work_buffer);
```

**Fix:** Set pointer to NULL immediately after free(). Enable AddressSanitizer in CI: -fsanitize=address.
---

### 31. [HIGH] Use-after-free pattern

**CWE-416** | `linuxkm/lkcapi_ecdsa_glue.c` line 847

Freed pointer not immediately set to NULL. Dangling pointer reuse corrupts heap and can lead to code execution.

```
free(sig);
```

**Fix:** Set pointer to NULL immediately after free(). Enable AddressSanitizer in CI: -fsanitize=address.
---

### 32. [HIGH] Use-after-free pattern

**CWE-416** | `linuxkm/lkcapi_ecdsa_glue.c` line 1284

Freed pointer not immediately set to NULL. Dangling pointer reuse corrupts heap and can lead to code execution.

```
free(raw_sig);
```

**Fix:** Set pointer to NULL immediately after free(). Enable AddressSanitizer in CI: -fsanitize=address.
---

### 33. [HIGH] Use-after-free pattern

**CWE-416** | `linuxkm/lkcapi_ecdsa_glue.c` line 1472

Freed pointer not immediately set to NULL. Dangling pointer reuse corrupts heap and can lead to code execution.

```
if (param_copy) { free(param_copy); }
```

**Fix:** Set pointer to NULL immediately after free(). Enable AddressSanitizer in CI: -fsanitize=address.
---

### 34. [HIGH] Missing NULL check after allocation

**CWE-476** | `linuxkm/lkcapi_ecdsa_glue.c` line 154

Return value of malloc/realloc not checked for NULL. On allocation failure the program dereferences NULL, causing a crash or exploitable condition.

```
ecc_key *key = (ecc_key *)malloc(sizeof(*key));
```

**Fix:** Always check: ptr = malloc(n); if (!ptr) { handle_error(); return; }
---

### 35. [HIGH] Missing NULL check after allocation

**CWE-476** | `linuxkm/lkcapi_ecdsa_glue.c` line 667

Return value of malloc/realloc not checked for NULL. On allocation failure the program dereferences NULL, causing a crash or exploitable condition.

```
work_buffer = (byte *)malloc((2U * ctx->curve_len) + ECC_MAX_SIG_SIZE);
```

**Fix:** Always check: ptr = malloc(n); if (!ptr) { handle_error(); return; }
---

### 36. [HIGH] Missing NULL check after allocation

**CWE-476** | `linuxkm/lkcapi_ecdsa_glue.c` line 803

Return value of malloc/realloc not checked for NULL. On allocation failure the program dereferences NULL, causing a crash or exploitable condition.

```
sig = malloc(sig_len + hash_len);
```

**Fix:** Always check: ptr = malloc(n); if (!ptr) { handle_error(); return; }
---

### 37. [HIGH] Missing NULL check after allocation

**CWE-476** | `linuxkm/lkcapi_ecdsa_glue.c` line 1310

Return value of malloc/realloc not checked for NULL. On allocation failure the program dereferences NULL, causing a crash or exploitable condition.

```
param_copy = (byte *)malloc(sig_len + hash_len);
```

**Fix:** Always check: ptr = malloc(n); if (!ptr) { handle_error(); return; }
---

### 38. [HIGH] Missing NULL check after allocation

**CWE-476** | `linuxkm/lkcapi_ecdsa_glue.c` line 1403

Return value of malloc/realloc not checked for NULL. On allocation failure the program dereferences NULL, causing a crash or exploitable condition.

```
bad_sig = malloc(sig_len);
```

**Fix:** Always check: ptr = malloc(n); if (!ptr) { handle_error(); return; }
---

### 39. [HIGH] Use-after-free pattern

**CWE-416** | `tests/api/test_ossl_x509_ext.c` line 58

Freed pointer not immediately set to NULL. Dangling pointer reuse corrupts heap and can lead to code execution.

```
wolfSSL_X509_free(x509);
```

**Fix:** Set pointer to NULL immediately after free(). Enable AddressSanitizer in CI: -fsanitize=address.
---

### 40. [HIGH] Use-after-free pattern

**CWE-416** | `tests/api/test_ossl_x509_ext.c` line 80

Freed pointer not immediately set to NULL. Dangling pointer reuse corrupts heap and can lead to code execution.

```
X509_free(x509);
```

**Fix:** Set pointer to NULL immediately after free(). Enable AddressSanitizer in CI: -fsanitize=address.
---

### 41. [HIGH] Use-after-free pattern

**CWE-416** | `tests/api/test_ossl_x509_ext.c` line 96

Freed pointer not immediately set to NULL. Dangling pointer reuse corrupts heap and can lead to code execution.

```
X509_free(x509);
```

**Fix:** Set pointer to NULL immediately after free(). Enable AddressSanitizer in CI: -fsanitize=address.
---

### 42. [HIGH] Use-after-free pattern

**CWE-416** | `tests/api/test_ossl_x509_ext.c` line 133

Freed pointer not immediately set to NULL. Dangling pointer reuse corrupts heap and can lead to code execution.

```
wolfSSL_X509_free(x509);
```

**Fix:** Set pointer to NULL immediately after free(). Enable AddressSanitizer in CI: -fsanitize=address.
---

### 43. [HIGH] Use-after-free pattern

**CWE-416** | `tests/api/test_ossl_x509_ext.c` line 150

Freed pointer not immediately set to NULL. Dangling pointer reuse corrupts heap and can lead to code execution.

```
wolfSSL_X509_free(x509);
```

**Fix:** Set pointer to NULL immediately after free(). Enable AddressSanitizer in CI: -fsanitize=address.
---

### 44. [HIGH] Use-after-free pattern

**CWE-416** | `tests/api/test_ossl_x509_ext.c` line 183

Freed pointer not immediately set to NULL. Dangling pointer reuse corrupts heap and can lead to code execution.

```
wolfSSL_X509_free(x509);
```

**Fix:** Set pointer to NULL immediately after free(). Enable AddressSanitizer in CI: -fsanitize=address.
---

### 45. [HIGH] Use-after-free pattern

**CWE-416** | `tests/api/test_ossl_x509_ext.c` line 215

Freed pointer not immediately set to NULL. Dangling pointer reuse corrupts heap and can lead to code execution.

```
X509_free(x509);
```

**Fix:** Set pointer to NULL immediately after free(). Enable AddressSanitizer in CI: -fsanitize=address.
---

### 46. [HIGH] Use-after-free pattern

**CWE-416** | `tests/api/test_ossl_x509_ext.c` line 237

Freed pointer not immediately set to NULL. Dangling pointer reuse corrupts heap and can lead to code execution.

```
wolfSSL_X509_free(x509);
```

**Fix:** Set pointer to NULL immediately after free(). Enable AddressSanitizer in CI: -fsanitize=address.
---

### 47. [HIGH] Use-after-free pattern

**CWE-416** | `tests/api/test_ossl_x509_ext.c` line 249

Freed pointer not immediately set to NULL. Dangling pointer reuse corrupts heap and can lead to code execution.

```
wolfSSL_X509_free(x509);
```

**Fix:** Set pointer to NULL immediately after free(). Enable AddressSanitizer in CI: -fsanitize=address.
---

### 48. [HIGH] Use-after-free pattern

**CWE-416** | `tests/api/test_ossl_x509_ext.c` line 301

Freed pointer not immediately set to NULL. Dangling pointer reuse corrupts heap and can lead to code execution.

```
wolfSSL_ASN1_INTEGER_free(pathLen);
```

**Fix:** Set pointer to NULL immediately after free(). Enable AddressSanitizer in CI: -fsanitize=address.
---

### 49. [HIGH] Use-after-free pattern

**CWE-416** | `tests/api/test_ossl_x509_ext.c` line 302

Freed pointer not immediately set to NULL. Dangling pointer reuse corrupts heap and can lead to code execution.

```
wolfSSL_ASN1_OBJECT_free(obj);
```

**Fix:** Set pointer to NULL immediately after free(). Enable AddressSanitizer in CI: -fsanitize=address.
---

### 50. [HIGH] Use-after-free pattern

**CWE-416** | `tests/api/test_ossl_x509_ext.c` line 303

Freed pointer not immediately set to NULL. Dangling pointer reuse corrupts heap and can lead to code execution.

```
wolfSSL_X509_EXTENSION_free(ext);
```

**Fix:** Set pointer to NULL immediately after free(). Enable AddressSanitizer in CI: -fsanitize=address.
---

### 51. [HIGH] Use-after-free pattern

**CWE-416** | `tests/api/test_ossl_x509_ext.c` line 336

Freed pointer not immediately set to NULL. Dangling pointer reuse corrupts heap and can lead to code execution.

```
wolfSSL_ASN1_STRING_free(str);
```

**Fix:** Set pointer to NULL immediately after free(). Enable AddressSanitizer in CI: -fsanitize=address.
---

### 52. [HIGH] Use-after-free pattern

**CWE-416** | `tests/api/test_ossl_x509_ext.c` line 346

Freed pointer not immediately set to NULL. Dangling pointer reuse corrupts heap and can lead to code execution.

```
wolfSSL_ASN1_STRING_free(str);
```

**Fix:** Set pointer to NULL immediately after free(). Enable AddressSanitizer in CI: -fsanitize=address.
---

### 53. [HIGH] Use-after-free pattern

**CWE-416** | `tests/api/test_ossl_x509_ext.c` line 355

Freed pointer not immediately set to NULL. Dangling pointer reuse corrupts heap and can lead to code execution.

```
wolfSSL_ASN1_STRING_free(str);
```

**Fix:** Set pointer to NULL immediately after free(). Enable AddressSanitizer in CI: -fsanitize=address.
---

### 54. [HIGH] Use-after-free pattern

**CWE-416** | `tests/api/test_ossl_x509_ext.c` line 362

Freed pointer not immediately set to NULL. Dangling pointer reuse corrupts heap and can lead to code execution.

```
wolfSSL_ASN1_STRING_free(str);
```

**Fix:** Set pointer to NULL immediately after free(). Enable AddressSanitizer in CI: -fsanitize=address.
---

### 55. [HIGH] Use-after-free pattern

**CWE-416** | `tests/api/test_ossl_x509_ext.c` line 363

Freed pointer not immediately set to NULL. Dangling pointer reuse corrupts heap and can lead to code execution.

```
wolfSSL_ASN1_OBJECT_free(obj);
```

**Fix:** Set pointer to NULL immediately after free(). Enable AddressSanitizer in CI: -fsanitize=address.
---

### 56. [HIGH] Use-after-free pattern

**CWE-416** | `tests/api/test_ossl_x509_ext.c` line 364

Freed pointer not immediately set to NULL. Dangling pointer reuse corrupts heap and can lead to code execution.

```
wolfSSL_X509_EXTENSION_free(ext);
```

**Fix:** Set pointer to NULL immediately after free(). Enable AddressSanitizer in CI: -fsanitize=address.
---

### 57. [HIGH] Use-after-free pattern

**CWE-416** | `tests/api/test_ossl_x509_ext.c` line 397

Freed pointer not immediately set to NULL. Dangling pointer reuse corrupts heap and can lead to code execution.

```
wolfSSL_ASN1_STRING_free(str);
```

**Fix:** Set pointer to NULL immediately after free(). Enable AddressSanitizer in CI: -fsanitize=address.
---

### 58. [HIGH] Use-after-free pattern

**CWE-416** | `tests/api/test_ossl_x509_ext.c` line 407

Freed pointer not immediately set to NULL. Dangling pointer reuse corrupts heap and can lead to code execution.

```
wolfSSL_ASN1_STRING_free(str);
```

**Fix:** Set pointer to NULL immediately after free(). Enable AddressSanitizer in CI: -fsanitize=address.
---

### 59. [HIGH] Use-after-free pattern

**CWE-416** | `tests/api/test_ossl_x509_ext.c` line 416

Freed pointer not immediately set to NULL. Dangling pointer reuse corrupts heap and can lead to code execution.

```
wolfSSL_ASN1_STRING_free(str);
```

**Fix:** Set pointer to NULL immediately after free(). Enable AddressSanitizer in CI: -fsanitize=address.
---

### 60. [HIGH] Use-after-free pattern

**CWE-416** | `tests/api/test_ossl_x509_ext.c` line 423

Freed pointer not immediately set to NULL. Dangling pointer reuse corrupts heap and can lead to code execution.

```
wolfSSL_ASN1_STRING_free(str);
```

**Fix:** Set pointer to NULL immediately after free(). Enable AddressSanitizer in CI: -fsanitize=address.
---

### 61. [HIGH] Use-after-free pattern

**CWE-416** | `tests/api/test_ossl_x509_ext.c` line 424

Freed pointer not immediately set to NULL. Dangling pointer reuse corrupts heap and can lead to code execution.

```
wolfSSL_ASN1_OBJECT_free(obj);
```

**Fix:** Set pointer to NULL immediately after free(). Enable AddressSanitizer in CI: -fsanitize=address.
---

### 62. [HIGH] Use-after-free pattern

**CWE-416** | `tests/api/test_ossl_x509_ext.c` line 425

Freed pointer not immediately set to NULL. Dangling pointer reuse corrupts heap and can lead to code execution.

```
wolfSSL_X509_EXTENSION_free(ext);
```

**Fix:** Set pointer to NULL immediately after free(). Enable AddressSanitizer in CI: -fsanitize=address.
---

### 63. [HIGH] Use-after-free pattern

**CWE-416** | `tests/api/test_ossl_x509_ext.c` line 482

Freed pointer not immediately set to NULL. Dangling pointer reuse corrupts heap and can lead to code execution.

```
wolfSSL_ASN1_STRING_free(str);
```

**Fix:** Set pointer to NULL immediately after free(). Enable AddressSanitizer in CI: -fsanitize=address.
---

### 64. [HIGH] Use-after-free pattern

**CWE-416** | `tests/api/test_ossl_x509_ext.c` line 483

Freed pointer not immediately set to NULL. Dangling pointer reuse corrupts heap and can lead to code execution.

```
wolfSSL_ASN1_OBJECT_free(obj);
```

**Fix:** Set pointer to NULL immediately after free(). Enable AddressSanitizer in CI: -fsanitize=address.
---

### 65. [HIGH] Use-after-free pattern

**CWE-416** | `tests/api/test_ossl_x509_ext.c` line 484

Freed pointer not immediately set to NULL. Dangling pointer reuse corrupts heap and can lead to code execution.

```
wolfSSL_X509_EXTENSION_free(ext);
```

**Fix:** Set pointer to NULL immediately after free(). Enable AddressSanitizer in CI: -fsanitize=address.
---

### 66. [HIGH] Use-after-free pattern

**CWE-416** | `tests/api/test_ossl_x509_ext.c` line 517

Freed pointer not immediately set to NULL. Dangling pointer reuse corrupts heap and can lead to code execution.

```
wolfSSL_ASN1_STRING_free(str);
```

**Fix:** Set pointer to NULL immediately after free(). Enable AddressSanitizer in CI: -fsanitize=address.
---

### 67. [HIGH] Use-after-free pattern

**CWE-416** | `tests/api/test_ossl_x509_ext.c` line 518

Freed pointer not immediately set to NULL. Dangling pointer reuse corrupts heap and can lead to code execution.

```
wolfSSL_ASN1_OBJECT_free(obj);
```

**Fix:** Set pointer to NULL immediately after free(). Enable AddressSanitizer in CI: -fsanitize=address.
---

### 68. [HIGH] Use-after-free pattern

**CWE-416** | `tests/api/test_ossl_x509_ext.c` line 519

Freed pointer not immediately set to NULL. Dangling pointer reuse corrupts heap and can lead to code execution.

```
wolfSSL_X509_EXTENSION_free(ext);
```

**Fix:** Set pointer to NULL immediately after free(). Enable AddressSanitizer in CI: -fsanitize=address.
---

### 69. [HIGH] Use-after-free pattern

**CWE-416** | `tests/api/test_ossl_x509_ext.c` line 581

Freed pointer not immediately set to NULL. Dangling pointer reuse corrupts heap and can lead to code execution.

```
wolfSSL_X509_EXTENSION_free(ext);
```

**Fix:** Set pointer to NULL immediately after free(). Enable AddressSanitizer in CI: -fsanitize=address.
---

### 70. [HIGH] Use-after-free pattern

**CWE-416** | `tests/api/test_ossl_x509_ext.c` line 582

Freed pointer not immediately set to NULL. Dangling pointer reuse corrupts heap and can lead to code execution.

```
wolfSSL_ASN1_OBJECT_free(obj);
```

**Fix:** Set pointer to NULL immediately after free(). Enable AddressSanitizer in CI: -fsanitize=address.
---

### 71. [HIGH] Use-after-free pattern

**CWE-416** | `tests/api/test_ossl_x509_ext.c` line 583

Freed pointer not immediately set to NULL. Dangling pointer reuse corrupts heap and can lead to code execution.

```
wolfSSL_ASN1_STRING_free(data);
```

**Fix:** Set pointer to NULL immediately after free(). Enable AddressSanitizer in CI: -fsanitize=address.
---

### 72. [HIGH] Use-after-free pattern

**CWE-416** | `tests/api/test_ossl_x509_ext.c` line 584

Freed pointer not immediately set to NULL. Dangling pointer reuse corrupts heap and can lead to code execution.

```
wolfSSL_X509_EXTENSION_free(ext_empty);
```

**Fix:** Set pointer to NULL immediately after free(). Enable AddressSanitizer in CI: -fsanitize=address.
---

### 73. [HIGH] Use-after-free pattern

**CWE-416** | `tests/api/test_ossl_x509_ext.c` line 592

Freed pointer not immediately set to NULL. Dangling pointer reuse corrupts heap and can lead to code execution.

```
wolfSSL_X509_free(x509);
```

**Fix:** Set pointer to NULL immediately after free(). Enable AddressSanitizer in CI: -fsanitize=address.
---

### 74. [HIGH] Use-after-free pattern

**CWE-416** | `tests/api/test_ossl_x509_ext.c` line 653

Freed pointer not immediately set to NULL. Dangling pointer reuse corrupts heap and can lead to code execution.

```
wolfSSL_ASN1_OBJECT_free(obj);
```

**Fix:** Set pointer to NULL immediately after free(). Enable AddressSanitizer in CI: -fsanitize=address.
---

### 75. [HIGH] Use-after-free pattern

**CWE-416** | `tests/api/test_ossl_x509_ext.c` line 655

Freed pointer not immediately set to NULL. Dangling pointer reuse corrupts heap and can lead to code execution.

```
wolfSSL_GENERAL_NAME_free(gn);
```

**Fix:** Set pointer to NULL immediately after free(). Enable AddressSanitizer in CI: -fsanitize=address.
---

### 76. [HIGH] Use-after-free pattern

**CWE-416** | `tests/api/test_ossl_x509_ext.c` line 656

Freed pointer not immediately set to NULL. Dangling pointer reuse corrupts heap and can lead to code execution.

```
wolfSSL_X509_NAME_free(dirName);
```

**Fix:** Set pointer to NULL immediately after free(). Enable AddressSanitizer in CI: -fsanitize=address.
---

### 77. [HIGH] Use-after-free pattern

**CWE-416** | `tests/api/test_ossl_x509_ext.c` line 657

Freed pointer not immediately set to NULL. Dangling pointer reuse corrupts heap and can lead to code execution.

```
wolfSSL_X509_EXTENSION_free(ext);
```

**Fix:** Set pointer to NULL immediately after free(). Enable AddressSanitizer in CI: -fsanitize=address.
---

### 78. [HIGH] Use-after-free pattern

**CWE-416** | `tests/api/test_ossl_x509_ext.c` line 658

Freed pointer not immediately set to NULL. Dangling pointer reuse corrupts heap and can lead to code execution.

```
wolfSSL_X509_free(x509);
```

**Fix:** Set pointer to NULL immediately after free(). Enable AddressSanitizer in CI: -fsanitize=address.
---

### 79. [HIGH] Use-after-free pattern

**CWE-416** | `tests/api/test_ossl_x509_ext.c` line 677

Freed pointer not immediately set to NULL. Dangling pointer reuse corrupts heap and can lead to code execution.

```
wolfSSL_X509_free(x509);
```

**Fix:** Set pointer to NULL immediately after free(). Enable AddressSanitizer in CI: -fsanitize=address.
---

### 80. [HIGH] Use-after-free pattern

**CWE-416** | `tests/api/test_ossl_x509_ext.c` line 683

Freed pointer not immediately set to NULL. Dangling pointer reuse corrupts heap and can lead to code execution.

```
wolfSSL_X509_free(x509);
```

**Fix:** Set pointer to NULL immediately after free(). Enable AddressSanitizer in CI: -fsanitize=address.
---

### 81. [HIGH] Use-after-free pattern

**CWE-416** | `tests/api/test_ossl_x509_ext.c` line 688

Freed pointer not immediately set to NULL. Dangling pointer reuse corrupts heap and can lead to code execution.

```
wolfSSL_X509_free(x509);
```

**Fix:** Set pointer to NULL immediately after free(). Enable AddressSanitizer in CI: -fsanitize=address.
---

### 82. [HIGH] Use-after-free pattern

**CWE-416** | `tests/api/test_ossl_x509_ext.c` line 698

Freed pointer not immediately set to NULL. Dangling pointer reuse corrupts heap and can lead to code execution.

```
wolfSSL_X509_free(x509);
```

**Fix:** Set pointer to NULL immediately after free(). Enable AddressSanitizer in CI: -fsanitize=address.
---

### 83. [HIGH] Use-after-free pattern

**CWE-416** | `tests/api/test_ossl_x509_ext.c` line 748

Freed pointer not immediately set to NULL. Dangling pointer reuse corrupts heap and can lead to code execution.

```
wolfSSL_X509_free(x509);
```

**Fix:** Set pointer to NULL immediately after free(). Enable AddressSanitizer in CI: -fsanitize=address.
---

### 84. [HIGH] Use-after-free pattern

**CWE-416** | `tests/api/test_ossl_x509_ext.c` line 762

Freed pointer not immediately set to NULL. Dangling pointer reuse corrupts heap and can lead to code execution.

```
wolfSSL_X509_EXTENSION_free(NULL);
```

**Fix:** Set pointer to NULL immediately after free(). Enable AddressSanitizer in CI: -fsanitize=address.
---

### 85. [HIGH] Use-after-free pattern

**CWE-416** | `tests/api/test_ossl_x509_ext.c` line 763

Freed pointer not immediately set to NULL. Dangling pointer reuse corrupts heap and can lead to code execution.

```
wolfSSL_X509_EXTENSION_free(ext);
```

**Fix:** Set pointer to NULL immediately after free(). Enable AddressSanitizer in CI: -fsanitize=address.
---

### 86. [HIGH] Use-after-free pattern

**CWE-416** | `tests/api/test_ossl_x509_ext.c` line 779

Freed pointer not immediately set to NULL. Dangling pointer reuse corrupts heap and can lead to code execution.

```
wolfSSL_X509_EXTENSION_free(dup);
```

**Fix:** Set pointer to NULL immediately after free(). Enable AddressSanitizer in CI: -fsanitize=address.
---

### 87. [HIGH] Use-after-free pattern

**CWE-416** | `tests/api/test_ossl_x509_ext.c` line 780

Freed pointer not immediately set to NULL. Dangling pointer reuse corrupts heap and can lead to code execution.

```
wolfSSL_X509_EXTENSION_free(ext);
```

**Fix:** Set pointer to NULL immediately after free(). Enable AddressSanitizer in CI: -fsanitize=address.
---

### 88. [HIGH] Use-after-free pattern

**CWE-416** | `tests/api/test_ossl_x509_ext.c` line 807

Freed pointer not immediately set to NULL. Dangling pointer reuse corrupts heap and can lead to code execution.

```
wolfSSL_X509_EXTENSION_free(dup);
```

**Fix:** Set pointer to NULL immediately after free(). Enable AddressSanitizer in CI: -fsanitize=address.
---

### 89. [HIGH] Use-after-free pattern

**CWE-416** | `tests/api/test_ossl_x509_ext.c` line 812

Freed pointer not immediately set to NULL. Dangling pointer reuse corrupts heap and can lead to code execution.

```
wolfSSL_X509_free(x509);
```

**Fix:** Set pointer to NULL immediately after free(). Enable AddressSanitizer in CI: -fsanitize=address.
---

### 90. [HIGH] Use-after-free pattern

**CWE-416** | `tests/api/test_ossl_x509_ext.c` line 848

Freed pointer not immediately set to NULL. Dangling pointer reuse corrupts heap and can lead to code execution.

```
wolfSSL_X509_free(x509);
```

**Fix:** Set pointer to NULL immediately after free(). Enable AddressSanitizer in CI: -fsanitize=address.
---

### 91. [HIGH] Use-after-free pattern

**CWE-416** | `tests/api/test_ossl_x509_ext.c` line 893

Freed pointer not immediately set to NULL. Dangling pointer reuse corrupts heap and can lead to code execution.

```
wolfSSL_ASN1_STRING_free(str);
```

**Fix:** Set pointer to NULL immediately after free(). Enable AddressSanitizer in CI: -fsanitize=address.
---

### 92. [HIGH] Use-after-free pattern

**CWE-416** | `tests/api/test_ossl_x509_ext.c` line 894

Freed pointer not immediately set to NULL. Dangling pointer reuse corrupts heap and can lead to code execution.

```
wolfSSL_X509_EXTENSION_free(ext);
```

**Fix:** Set pointer to NULL immediately after free(). Enable AddressSanitizer in CI: -fsanitize=address.
---

### 93. [HIGH] Use-after-free pattern

**CWE-416** | `tests/api/test_ossl_x509_ext.c` line 919

Freed pointer not immediately set to NULL. Dangling pointer reuse corrupts heap and can lead to code execution.

```
wolfSSL_X509_free(x509);
```

**Fix:** Set pointer to NULL immediately after free(). Enable AddressSanitizer in CI: -fsanitize=address.
---

### 94. [HIGH] Use-after-free pattern

**CWE-416** | `tests/api/test_ossl_x509_ext.c` line 963

Freed pointer not immediately set to NULL. Dangling pointer reuse corrupts heap and can lead to code execution.

```
wolfSSL_X509_EXTENSION_free(ext2);
```

**Fix:** Set pointer to NULL immediately after free(). Enable AddressSanitizer in CI: -fsanitize=address.
---

### 95. [HIGH] Use-after-free pattern

**CWE-416** | `tests/api/test_ossl_x509_ext.c` line 974

Freed pointer not immediately set to NULL. Dangling pointer reuse corrupts heap and can lead to code execution.

```
wolfSSL_X509_EXTENSION_free(ext3);
```

**Fix:** Set pointer to NULL immediately after free(). Enable AddressSanitizer in CI: -fsanitize=address.
---

### 96. [HIGH] Use-after-free pattern

**CWE-416** | `tests/api/test_ossl_x509_ext.c` line 985

Freed pointer not immediately set to NULL. Dangling pointer reuse corrupts heap and can lead to code execution.

```
wolfSSL_X509_free(empty);
```

**Fix:** Set pointer to NULL immediately after free(). Enable AddressSanitizer in CI: -fsanitize=address.
---

### 97. [HIGH] Use-after-free pattern

**CWE-416** | `tests/api/test_ossl_x509_ext.c` line 994

Freed pointer not immediately set to NULL. Dangling pointer reuse corrupts heap and can lead to code execution.

```
wolfSSL_X509_free(x509);
```

**Fix:** Set pointer to NULL immediately after free(). Enable AddressSanitizer in CI: -fsanitize=address.
---

### 98. [HIGH] Use-after-free pattern

**CWE-416** | `tests/api/test_ossl_x509_ext.c` line 1039

Freed pointer not immediately set to NULL. Dangling pointer reuse corrupts heap and can lead to code execution.

```
wolfSSL_X509_free(subject);
```

**Fix:** Set pointer to NULL immediately after free(). Enable AddressSanitizer in CI: -fsanitize=address.
---

### 99. [HIGH] Use-after-free pattern

**CWE-416** | `tests/api/test_ossl_x509_ext.c` line 1040

Freed pointer not immediately set to NULL. Dangling pointer reuse corrupts heap and can lead to code execution.

```
wolfSSL_X509_free(issuer);
```

**Fix:** Set pointer to NULL immediately after free(). Enable AddressSanitizer in CI: -fsanitize=address.
---

### 100. [HIGH] Use-after-free pattern

**CWE-416** | `tests/api/test_ossl_x509_ext.c` line 1084

Freed pointer not immediately set to NULL. Dangling pointer reuse corrupts heap and can lead to code execution.

```
wolfSSL_ASN1_OBJECT_free(obj);
```

**Fix:** Set pointer to NULL immediately after free(). Enable AddressSanitizer in CI: -fsanitize=address.
---

### 101. [HIGH] Use-after-free pattern

**CWE-416** | `tests/api/test_ossl_x509_ext.c` line 1085

Freed pointer not immediately set to NULL. Dangling pointer reuse corrupts heap and can lead to code execution.

```
wolfSSL_X509_EXTENSION_free(ext);
```

**Fix:** Set pointer to NULL immediately after free(). Enable AddressSanitizer in CI: -fsanitize=address.
---

### 102. [HIGH] Use-after-free pattern

**CWE-416** | `tests/api/test_ossl_x509_ext.c` line 1110

Freed pointer not immediately set to NULL. Dangling pointer reuse corrupts heap and can lead to code execution.

```
wolfSSL_X509_free(x509);
```

**Fix:** Set pointer to NULL immediately after free(). Enable AddressSanitizer in CI: -fsanitize=address.
---

### 103. [HIGH] Use-after-free pattern

**CWE-416** | `tests/api/test_ossl_x509_ext.c` line 1187

Freed pointer not immediately set to NULL. Dangling pointer reuse corrupts heap and can lead to code execution.

```
X509_EXTENSION_free(ext);
```

**Fix:** Set pointer to NULL immediately after free(). Enable AddressSanitizer in CI: -fsanitize=address.
---

### 104. [HIGH] Use-after-free pattern

**CWE-416** | `tests/api/test_ossl_x509_ext.c` line 1194

Freed pointer not immediately set to NULL. Dangling pointer reuse corrupts heap and can lead to code execution.

```
X509_EXTENSION_free(ext);
```

**Fix:** Set pointer to NULL immediately after free(). Enable AddressSanitizer in CI: -fsanitize=address.
---

### 105. [HIGH] Use-after-free pattern

**CWE-416** | `tests/api/test_ossl_x509_ext.c` line 1210

Freed pointer not immediately set to NULL. Dangling pointer reuse corrupts heap and can lead to code execution.

```
X509_EXTENSION_free(ext);
```

**Fix:** Set pointer to NULL immediately after free(). Enable AddressSanitizer in CI: -fsanitize=address.
---

### 106. [HIGH] Use-after-free pattern

**CWE-416** | `tests/api/test_ossl_x509_ext.c` line 1213

Freed pointer not immediately set to NULL. Dangling pointer reuse corrupts heap and can lead to code execution.

```
X509_free(x509);
```

**Fix:** Set pointer to NULL immediately after free(). Enable AddressSanitizer in CI: -fsanitize=address.
---

### 107. [HIGH] Use-after-free pattern

**CWE-416** | `tests/api/test_ossl_x509_ext.c` line 1250

Freed pointer not immediately set to NULL. Dangling pointer reuse corrupts heap and can lead to code execution.

```
wolfSSL_BASIC_CONSTRAINTS_free(bc);
```

**Fix:** Set pointer to NULL immediately after free(). Enable AddressSanitizer in CI: -fsanitize=address.
---

### 108. [HIGH] Use-after-free pattern

**CWE-416** | `tests/api/test_ossl_x509_ext.c` line 1267

Freed pointer not immediately set to NULL. Dangling pointer reuse corrupts heap and can lead to code execution.

```
wolfSSL_BASIC_CONSTRAINTS_free(bc);
```

**Fix:** Set pointer to NULL immediately after free(). Enable AddressSanitizer in CI: -fsanitize=address.
---

### 109. [HIGH] Use-after-free pattern

**CWE-416** | `tests/api/test_ossl_x509_ext.c` line 1287

Freed pointer not immediately set to NULL. Dangling pointer reuse corrupts heap and can lead to code execution.

```
wolfSSL_ASN1_INTEGER_free(pathLen);
```

**Fix:** Set pointer to NULL immediately after free(). Enable AddressSanitizer in CI: -fsanitize=address.
---

### 110. [HIGH] Use-after-free pattern

**CWE-416** | `tests/api/test_ossl_x509_ext.c` line 1288

Freed pointer not immediately set to NULL. Dangling pointer reuse corrupts heap and can lead to code execution.

```
wolfSSL_BASIC_CONSTRAINTS_free(bc);
```

**Fix:** Set pointer to NULL immediately after free(). Enable AddressSanitizer in CI: -fsanitize=address.
---

### 111. [HIGH] Use-after-free pattern

**CWE-416** | `tests/api/test_ossl_x509_ext.c` line 1289

Freed pointer not immediately set to NULL. Dangling pointer reuse corrupts heap and can lead to code execution.

```
wolfSSL_ASN1_OBJECT_free(obj);
```

**Fix:** Set pointer to NULL immediately after free(). Enable AddressSanitizer in CI: -fsanitize=address.
---

### 112. [HIGH] Use-after-free pattern

**CWE-416** | `tests/api/test_ossl_x509_ext.c` line 1290

Freed pointer not immediately set to NULL. Dangling pointer reuse corrupts heap and can lead to code execution.

```
wolfSSL_X509_EXTENSION_free(ext);
```

**Fix:** Set pointer to NULL immediately after free(). Enable AddressSanitizer in CI: -fsanitize=address.
---

### 113. [HIGH] Use-after-free pattern

**CWE-416** | `tests/api/test_ossl_x509_ext.c` line 1316

Freed pointer not immediately set to NULL. Dangling pointer reuse corrupts heap and can lead to code execution.

```
wolfSSL_BASIC_CONSTRAINTS_free(bc);
```

**Fix:** Set pointer to NULL immediately after free(). Enable AddressSanitizer in CI: -fsanitize=address.
---

### 114. [HIGH] Use-after-free pattern

**CWE-416** | `tests/api/test_ossl_x509_ext.c` line 1318

Freed pointer not immediately set to NULL. Dangling pointer reuse corrupts heap and can lead to code execution.

```
wolfSSL_X509_free(x509);
```

**Fix:** Set pointer to NULL immediately after free(). Enable AddressSanitizer in CI: -fsanitize=address.
---

### 115. [HIGH] Use-after-free pattern

**CWE-416** | `tests/api/test_ossl_x509_ext.c` line 1333

Freed pointer not immediately set to NULL. Dangling pointer reuse corrupts heap and can lead to code execution.

```
wolfSSL_BASIC_CONSTRAINTS_free(bc);
```

**Fix:** Set pointer to NULL immediately after free(). Enable AddressSanitizer in CI: -fsanitize=address.
---

### 116. [HIGH] Use-after-free pattern

**CWE-416** | `tests/api/test_ossl_x509_ext.c` line 1335

Freed pointer not immediately set to NULL. Dangling pointer reuse corrupts heap and can lead to code execution.

```
wolfSSL_X509_free(x509);
```

**Fix:** Set pointer to NULL immediately after free(). Enable AddressSanitizer in CI: -fsanitize=address.
---

### 117. [HIGH] Use-after-free pattern

**CWE-416** | `tests/api/test_ossl_x509_ext.c` line 1353

Freed pointer not immediately set to NULL. Dangling pointer reuse corrupts heap and can lead to code execution.

```
wolfSSL_BASIC_CONSTRAINTS_free(bc);
```

**Fix:** Set pointer to NULL immediately after free(). Enable AddressSanitizer in CI: -fsanitize=address.
---

### 118. [HIGH] Use-after-free pattern

**CWE-416** | `tests/api/test_ossl_x509_ext.c` line 1355

Freed pointer not immediately set to NULL. Dangling pointer reuse corrupts heap and can lead to code execution.

```
wolfSSL_X509_free(x509);
```

**Fix:** Set pointer to NULL immediately after free(). Enable AddressSanitizer in CI: -fsanitize=address.
---

### 119. [HIGH] Use-after-free pattern

**CWE-416** | `tests/api/test_ossl_x509_ext.c` line 1390

Freed pointer not immediately set to NULL. Dangling pointer reuse corrupts heap and can lead to code execution.

```
wolfSSL_sk_free(sk);
```

**Fix:** Set pointer to NULL immediately after free(). Enable AddressSanitizer in CI: -fsanitize=address.
---

### 120. [HIGH] Use-after-free pattern

**CWE-416** | `tests/api/test_ossl_x509_ext.c` line 1391

Freed pointer not immediately set to NULL. Dangling pointer reuse corrupts heap and can lead to code execution.

```
wolfSSL_ASN1_OBJECT_free(obj);
```

**Fix:** Set pointer to NULL immediately after free(). Enable AddressSanitizer in CI: -fsanitize=address.
---

### 121. [HIGH] Use-after-free pattern

**CWE-416** | `tests/api/test_ossl_x509_ext.c` line 1392

Freed pointer not immediately set to NULL. Dangling pointer reuse corrupts heap and can lead to code execution.

```
wolfSSL_X509_EXTENSION_free(ext);
```

**Fix:** Set pointer to NULL immediately after free(). Enable AddressSanitizer in CI: -fsanitize=address.
---

### 122. [HIGH] Use-after-free pattern

**CWE-416** | `tests/api/test_ossl_x509_ext.c` line 1429

Freed pointer not immediately set to NULL. Dangling pointer reuse corrupts heap and can lead to code execution.

```
wolfSSL_AUTHORITY_INFO_ACCESS_free(aia);
```

**Fix:** Set pointer to NULL immediately after free(). Enable AddressSanitizer in CI: -fsanitize=address.
---

### 123. [HIGH] Use-after-free pattern

**CWE-416** | `tests/api/test_ossl_x509_ext.c` line 1450

Freed pointer not immediately set to NULL. Dangling pointer reuse corrupts heap and can lead to code execution.

```
wolfSSL_ACCESS_DESCRIPTION_free(NULL);
```

**Fix:** Set pointer to NULL immediately after free(). Enable AddressSanitizer in CI: -fsanitize=address.
---

### 124. [HIGH] Use-after-free pattern

**CWE-416** | `tests/api/test_ossl_x509_ext.c` line 1454

Freed pointer not immediately set to NULL. Dangling pointer reuse corrupts heap and can lead to code execution.

```
wolfSSL_ASN1_OBJECT_free(entry);
```

**Fix:** Set pointer to NULL immediately after free(). Enable AddressSanitizer in CI: -fsanitize=address.
---

### 125. [HIGH] Use-after-free pattern

**CWE-416** | `tests/api/test_ossl_x509_ext.c` line 1455

Freed pointer not immediately set to NULL. Dangling pointer reuse corrupts heap and can lead to code execution.

```
wolfSSL_sk_free(node);
```

**Fix:** Set pointer to NULL immediately after free(). Enable AddressSanitizer in CI: -fsanitize=address.
---

### 126. [HIGH] Use-after-free pattern

**CWE-416** | `tests/api/test_ossl_x509_ext.c` line 1456

Freed pointer not immediately set to NULL. Dangling pointer reuse corrupts heap and can lead to code execution.

```
wolfSSL_ASN1_OBJECT_free(obj);
```

**Fix:** Set pointer to NULL immediately after free(). Enable AddressSanitizer in CI: -fsanitize=address.
---

### 127. [HIGH] Use-after-free pattern

**CWE-416** | `tests/api/test_ossl_x509_ext.c` line 1457

Freed pointer not immediately set to NULL. Dangling pointer reuse corrupts heap and can lead to code execution.

```
wolfSSL_X509_EXTENSION_free(ext);
```

**Fix:** Set pointer to NULL immediately after free(). Enable AddressSanitizer in CI: -fsanitize=address.
---

### 128. [HIGH] Use-after-free pattern

**CWE-416** | `tests/api/test_ossl_x509_ext.c` line 1517

Freed pointer not immediately set to NULL. Dangling pointer reuse corrupts heap and can lead to code execution.

```
wolfSSL_ASN1_OBJECT_free(obj);
```

**Fix:** Set pointer to NULL immediately after free(). Enable AddressSanitizer in CI: -fsanitize=address.
---

### 129. [HIGH] Use-after-free pattern

**CWE-416** | `tests/api/test_ossl_x509_ext.c` line 1519

Freed pointer not immediately set to NULL. Dangling pointer reuse corrupts heap and can lead to code execution.

```
wolfSSL_X509_EXTENSION_free(ext);
```

**Fix:** Set pointer to NULL immediately after free(). Enable AddressSanitizer in CI: -fsanitize=address.
---

### 130. [HIGH] Use-after-free pattern

**CWE-416** | `tests/api/test_ossl_x509_ext.c` line 1543

Freed pointer not immediately set to NULL. Dangling pointer reuse corrupts heap and can lead to code execution.

```
X509_EXTENSION_free(ext2);
```

**Fix:** Set pointer to NULL immediately after free(). Enable AddressSanitizer in CI: -fsanitize=address.
---

### 131. [HIGH] Use-after-free pattern

**CWE-416** | `tests/api/test_ossl_x509_ext.c` line 1548

Freed pointer not immediately set to NULL. Dangling pointer reuse corrupts heap and can lead to code execution.

```
wolfSSL_BASIC_CONSTRAINTS_free(bc);
```

**Fix:** Set pointer to NULL immediately after free(). Enable AddressSanitizer in CI: -fsanitize=address.
---

### 132. [HIGH] Use-after-free pattern

**CWE-416** | `tests/api/test_ossl_x509_ext.c` line 1569

Freed pointer not immediately set to NULL. Dangling pointer reuse corrupts heap and can lead to code execution.

```
X509_EXTENSION_free(ext2);
```

**Fix:** Set pointer to NULL immediately after free(). Enable AddressSanitizer in CI: -fsanitize=address.
---

### 133. [HIGH] Use-after-free pattern

**CWE-416** | `tests/api/test_ossl_x509_ext.c` line 1574

Freed pointer not immediately set to NULL. Dangling pointer reuse corrupts heap and can lead to code execution.

```
wolfSSL_ASN1_STRING_free(asn1str);
```

**Fix:** Set pointer to NULL immediately after free(). Enable AddressSanitizer in CI: -fsanitize=address.
---

### 134. [HIGH] Use-after-free pattern

**CWE-416** | `tests/api/test_ossl_x509_ext.c` line 1600

Freed pointer not immediately set to NULL. Dangling pointer reuse corrupts heap and can lead to code execution.

```
X509_EXTENSION_free(ext2);
```

**Fix:** Set pointer to NULL immediately after free(). Enable AddressSanitizer in CI: -fsanitize=address.
---

### 135. [HIGH] Use-after-free pattern

**CWE-416** | `tests/api/test_ossl_x509_ext.c` line 1614

Freed pointer not immediately set to NULL. Dangling pointer reuse corrupts heap and can lead to code execution.

```
wolfSSL_AUTHORITY_KEYID_free(aKeyId);
```

**Fix:** Set pointer to NULL immediately after free(). Enable AddressSanitizer in CI: -fsanitize=address.
---

### 136. [HIGH] Use-after-free pattern

**CWE-416** | `tests/api/test_ossl_x509_ext.c` line 1631

Freed pointer not immediately set to NULL. Dangling pointer reuse corrupts heap and can lead to code execution.

```
X509_EXTENSION_free(ext2);
```

**Fix:** Set pointer to NULL immediately after free(). Enable AddressSanitizer in CI: -fsanitize=address.
---

### 137. [HIGH] Use-after-free pattern

**CWE-416** | `tests/api/test_ossl_x509_ext.c` line 1647

Freed pointer not immediately set to NULL. Dangling pointer reuse corrupts heap and can lead to code execution.

```
wolfSSL_ASN1_STRING_free(asn1str);
```

**Fix:** Set pointer to NULL immediately after free(). Enable AddressSanitizer in CI: -fsanitize=address.
---

### 138. [HIGH] Use-after-free pattern

**CWE-416** | `tests/api/test_ossl_x509_ext.c` line 1712

Freed pointer not immediately set to NULL. Dangling pointer reuse corrupts heap and can lead to code execution.

```
wolfSSL_X509_free(x509);
```

**Fix:** Set pointer to NULL immediately after free(). Enable AddressSanitizer in CI: -fsanitize=address.
---

### 139. [HIGH] Use-after-free pattern

**CWE-416** | `tests/api/test_ossl_x509_ext.c` line 1762

Freed pointer not immediately set to NULL. Dangling pointer reuse corrupts heap and can lead to code execution.

```
wolfSSL_BIO_free(bio);
```

**Fix:** Set pointer to NULL immediately after free(). Enable AddressSanitizer in CI: -fsanitize=address.
---

### 140. [HIGH] Use-after-free pattern

**CWE-416** | `tests/api/test_ossl_x509_ext.c` line 1763

Freed pointer not immediately set to NULL. Dangling pointer reuse corrupts heap and can lead to code execution.

```
wolfSSL_X509_free(x509);
```

**Fix:** Set pointer to NULL immediately after free(). Enable AddressSanitizer in CI: -fsanitize=address.
---

### 141. [HIGH] Use-after-free pattern

**CWE-416** | `tests/api/test_ossl_x509_ext.c` line 1797

Freed pointer not immediately set to NULL. Dangling pointer reuse corrupts heap and can lead to code execution.

```
BIO_free(bio);
```

**Fix:** Set pointer to NULL immediately after free(). Enable AddressSanitizer in CI: -fsanitize=address.
---

### 142. [HIGH] Use-after-free pattern

**CWE-416** | `tests/api/test_ossl_x509_ext.c` line 1798

Freed pointer not immediately set to NULL. Dangling pointer reuse corrupts heap and can lead to code execution.

```
X509_free(x509);
```

**Fix:** Set pointer to NULL immediately after free(). Enable AddressSanitizer in CI: -fsanitize=address.
---

### 143. [HIGH] Use-after-free pattern

**CWE-416** | `tests/api/test_ossl_x509_ext.c` line 1836

Freed pointer not immediately set to NULL. Dangling pointer reuse corrupts heap and can lead to code execution.

```
wolfSSL_ASN1_OBJECT_free(obj);
```

**Fix:** Set pointer to NULL immediately after free(). Enable AddressSanitizer in CI: -fsanitize=address.
---

### 144. [HIGH] Use-after-free pattern

**CWE-416** | `tests/api/test_ossl_x509_ext.c` line 1837

Freed pointer not immediately set to NULL. Dangling pointer reuse corrupts heap and can lead to code execution.

```
X509_EXTENSION_free(ext);
```

**Fix:** Set pointer to NULL immediately after free(). Enable AddressSanitizer in CI: -fsanitize=address.
---

### 145. [HIGH] Use-after-free pattern

**CWE-416** | `tests/api/test_ossl_x509_ext.c` line 1838

Freed pointer not immediately set to NULL. Dangling pointer reuse corrupts heap and can lead to code execution.

```
BIO_free(bio);
```

**Fix:** Set pointer to NULL immediately after free(). Enable AddressSanitizer in CI: -fsanitize=address.
---

### 146. [HIGH] Use-after-free pattern

**CWE-416** | `tests/api/test_ossl_x509_ext.c` line 1879

Freed pointer not immediately set to NULL. Dangling pointer reuse corrupts heap and can lead to code execution.

```
X509_free(x509);
```

**Fix:** Set pointer to NULL immediately after free(). Enable AddressSanitizer in CI: -fsanitize=address.
---

### 147. [HIGH] Use-after-free pattern

**CWE-416** | `tests/api/test_ossl_x509_ext.c` line 1942

Freed pointer not immediately set to NULL. Dangling pointer reuse corrupts heap and can lead to code execution.

```
NAME_CONSTRAINTS_free(nc);
```

**Fix:** Set pointer to NULL immediately after free(). Enable AddressSanitizer in CI: -fsanitize=address.
---

### 148. [HIGH] Use-after-free pattern

**CWE-416** | `tests/api/test_ossl_x509_ext.c` line 1944

Freed pointer not immediately set to NULL. Dangling pointer reuse corrupts heap and can lead to code execution.

```
X509_free(x509);
```

**Fix:** Set pointer to NULL immediately after free(). Enable AddressSanitizer in CI: -fsanitize=address.
---

### 149. [HIGH] Use-after-free pattern

**CWE-416** | `tests/api/test_ossl_x509_ext.c` line 1948

Freed pointer not immediately set to NULL. Dangling pointer reuse corrupts heap and can lead to code execution.

```
NAME_CONSTRAINTS_free(NULL);
```

**Fix:** Set pointer to NULL immediately after free(). Enable AddressSanitizer in CI: -fsanitize=address.
---

### 150. [HIGH] Use-after-free pattern

**CWE-416** | `tests/api/test_ossl_x509_ext.c` line 1949

Freed pointer not immediately set to NULL. Dangling pointer reuse corrupts heap and can lead to code execution.

```
wolfSSL_GENERAL_SUBTREE_free(NULL);
```

**Fix:** Set pointer to NULL immediately after free(). Enable AddressSanitizer in CI: -fsanitize=address.
---

### 151. [HIGH] Use-after-free pattern

**CWE-416** | `tests/api/test_ossl_x509_ext.c` line 2018

Freed pointer not immediately set to NULL. Dangling pointer reuse corrupts heap and can lead to code execution.

```
NAME_CONSTRAINTS_free(nc);
```

**Fix:** Set pointer to NULL immediately after free(). Enable AddressSanitizer in CI: -fsanitize=address.
---

### 152. [HIGH] Use-after-free pattern

**CWE-416** | `tests/api/test_ossl_x509_ext.c` line 2019

Freed pointer not immediately set to NULL. Dangling pointer reuse corrupts heap and can lead to code execution.

```
X509_free(x509);
```

**Fix:** Set pointer to NULL immediately after free(). Enable AddressSanitizer in CI: -fsanitize=address.
---

### 153. [HIGH] Use-after-free pattern

**CWE-416** | `tests/api/test_ossl_x509_ext.c` line 2077

Freed pointer not immediately set to NULL. Dangling pointer reuse corrupts heap and can lead to code execution.

```
NAME_CONSTRAINTS_free(nc);
```

**Fix:** Set pointer to NULL immediately after free(). Enable AddressSanitizer in CI: -fsanitize=address.
---

### 154. [HIGH] Use-after-free pattern

**CWE-416** | `tests/api/test_ossl_x509_ext.c` line 2078

Freed pointer not immediately set to NULL. Dangling pointer reuse corrupts heap and can lead to code execution.

```
X509_free(x509);
```

**Fix:** Set pointer to NULL immediately after free(). Enable AddressSanitizer in CI: -fsanitize=address.
---

### 155. [HIGH] Use-after-free pattern

**CWE-416** | `tests/api/test_ossl_x509_ext.c` line 2197

Freed pointer not immediately set to NULL. Dangling pointer reuse corrupts heap and can lead to code execution.

```
NAME_CONSTRAINTS_free(nc);
```

**Fix:** Set pointer to NULL immediately after free(). Enable AddressSanitizer in CI: -fsanitize=address.
---

### 156. [HIGH] Use-after-free pattern

**CWE-416** | `tests/api/test_ossl_x509_ext.c` line 2198

Freed pointer not immediately set to NULL. Dangling pointer reuse corrupts heap and can lead to code execution.

```
X509_free(x509);
```

**Fix:** Set pointer to NULL immediately after free(). Enable AddressSanitizer in CI: -fsanitize=address.
---

### 157. [HIGH] Use-after-free pattern

**CWE-416** | `tests/api/test_ossl_x509_ext.c` line 2287

Freed pointer not immediately set to NULL. Dangling pointer reuse corrupts heap and can lead to code execution.

```
NAME_CONSTRAINTS_free(nc);
```

**Fix:** Set pointer to NULL immediately after free(). Enable AddressSanitizer in CI: -fsanitize=address.
---

### 158. [HIGH] Use-after-free pattern

**CWE-416** | `tests/api/test_ossl_x509_ext.c` line 2288

Freed pointer not immediately set to NULL. Dangling pointer reuse corrupts heap and can lead to code execution.

```
X509_free(x509);
```

**Fix:** Set pointer to NULL immediately after free(). Enable AddressSanitizer in CI: -fsanitize=address.
---

### 159. [HIGH] Use-after-free pattern

**CWE-416** | `tests/api/test_ossl_x509_ext.c` line 2372

Freed pointer not immediately set to NULL. Dangling pointer reuse corrupts heap and can lead to code execution.

```
NAME_CONSTRAINTS_free(nc);
```

**Fix:** Set pointer to NULL immediately after free(). Enable AddressSanitizer in CI: -fsanitize=address.
---

### 160. [HIGH] Use-after-free pattern

**CWE-416** | `tests/api/test_ossl_x509_ext.c` line 2373

Freed pointer not immediately set to NULL. Dangling pointer reuse corrupts heap and can lead to code execution.

```
X509_free(x509);
```

**Fix:** Set pointer to NULL immediately after free(). Enable AddressSanitizer in CI: -fsanitize=address.
---

### 161. [HIGH] Use-after-free pattern

**CWE-416** | `tests/api/test_ossl_x509_ext.c` line 2400

Freed pointer not immediately set to NULL. Dangling pointer reuse corrupts heap and can lead to code execution.

```
wolfSSL_GENERAL_SUBTREE_free(subtree);
```

**Fix:** Set pointer to NULL immediately after free(). Enable AddressSanitizer in CI: -fsanitize=address.
---

### 162. [HIGH] Use-after-free pattern

**CWE-416** | `tests/api/test_ossl_x509_ext.c` line 2439

Freed pointer not immediately set to NULL. Dangling pointer reuse corrupts heap and can lead to code execution.

```
NAME_CONSTRAINTS_free(nc);
```

**Fix:** Set pointer to NULL immediately after free(). Enable AddressSanitizer in CI: -fsanitize=address.
---

### 163. [HIGH] Use-after-free pattern

**CWE-416** | `tests/api/test_ossl_x509_ext.c` line 2483

Freed pointer not immediately set to NULL. Dangling pointer reuse corrupts heap and can lead to code execution.

```
NAME_CONSTRAINTS_free(nc);
```

**Fix:** Set pointer to NULL immediately after free(). Enable AddressSanitizer in CI: -fsanitize=address.
---

### 164. [HIGH] Use-after-free pattern

**CWE-416** | `tests/api/test_ossl_x509_ext.c` line 2484

Freed pointer not immediately set to NULL. Dangling pointer reuse corrupts heap and can lead to code execution.

```
X509_free(x509);
```

**Fix:** Set pointer to NULL immediately after free(). Enable AddressSanitizer in CI: -fsanitize=address.
---

### 165. [HIGH] Use-after-free pattern

**CWE-416** | `tests/api/test_ossl_x509_ext.c` line 2543

Freed pointer not immediately set to NULL. Dangling pointer reuse corrupts heap and can lead to code execution.

```
NAME_CONSTRAINTS_free(nc);
```

**Fix:** Set pointer to NULL immediately after free(). Enable AddressSanitizer in CI: -fsanitize=address.
---

### 166. [HIGH] Use-after-free pattern

**CWE-416** | `tests/api/test_ossl_x509_ext.c` line 2602

Freed pointer not immediately set to NULL. Dangling pointer reuse corrupts heap and can lead to code execution.

```
NAME_CONSTRAINTS_free(nc);
```

**Fix:** Set pointer to NULL immediately after free(). Enable AddressSanitizer in CI: -fsanitize=address.
---

### 167. [HIGH] Use-after-free pattern

**CWE-416** | `tests/api/test_ossl_x509_ext.c` line 2603

Freed pointer not immediately set to NULL. Dangling pointer reuse corrupts heap and can lead to code execution.

```
X509_free(x509);
```

**Fix:** Set pointer to NULL immediately after free(). Enable AddressSanitizer in CI: -fsanitize=address.
---

### 168. [HIGH] Use-after-free pattern

**CWE-416** | `tests/api/test_ossl_x509_ext.c` line 2682

Freed pointer not immediately set to NULL. Dangling pointer reuse corrupts heap and can lead to code execution.

```
NAME_CONSTRAINTS_free(nc);
```

**Fix:** Set pointer to NULL immediately after free(). Enable AddressSanitizer in CI: -fsanitize=address.
---

### 169. [HIGH] Use-after-free pattern

**CWE-416** | `tests/api/test_ossl_x509_ext.c` line 2683

Freed pointer not immediately set to NULL. Dangling pointer reuse corrupts heap and can lead to code execution.

```
X509_free(x509);
```

**Fix:** Set pointer to NULL immediately after free(). Enable AddressSanitizer in CI: -fsanitize=address.
---

### 170. [HIGH] Use-after-free pattern

**CWE-416** | `tests/api/test_ossl_x509_ext.c` line 2727

Freed pointer not immediately set to NULL. Dangling pointer reuse corrupts heap and can lead to code execution.

```
ASN1_OBJECT_free(canonical);
```

**Fix:** Set pointer to NULL immediately after free(). Enable AddressSanitizer in CI: -fsanitize=address.
---

### 171. [HIGH] Use-after-free pattern

**CWE-416** | `tests/api/test_ossl_x509_ext.c` line 2730

Freed pointer not immediately set to NULL. Dangling pointer reuse corrupts heap and can lead to code execution.

```
X509_free(x509);
```

**Fix:** Set pointer to NULL immediately after free(). Enable AddressSanitizer in CI: -fsanitize=address.
---

### 172. [HIGH] Use-after-free pattern

**CWE-416** | `tests/api/test_frodokem.c` line 1976

Freed pointer not immediately set to NULL. Dangling pointer reuse corrupts heap and can lead to code execution.

```
wc_ecc_free(caKey);
```

**Fix:** Set pointer to NULL immediately after free(). Enable AddressSanitizer in CI: -fsanitize=address.
---

### 173. [HIGH] Use-after-free pattern

**CWE-416** | `src/ocsp.c` line 932

Freed pointer not immediately set to NULL. Dangling pointer reuse corrupts heap and can lead to code execution.

```
wolfSSL_OCSP_RESPONSE_free(basicResponse);
```

**Fix:** Set pointer to NULL immediately after free(). Enable AddressSanitizer in CI: -fsanitize=address.
---

### 174. [HIGH] Use-after-free pattern

**CWE-416** | `src/ocsp.c` line 1322

Freed pointer not immediately set to NULL. Dangling pointer reuse corrupts heap and can lead to code execution.

```
wolfSSL_OCSP_RESPONSE_free(resp);
```

**Fix:** Set pointer to NULL immediately after free(). Enable AddressSanitizer in CI: -fsanitize=address.
---

### 175. [HIGH] Use-after-free pattern

**CWE-416** | `src/ocsp.c` line 1800

Freed pointer not immediately set to NULL. Dangling pointer reuse corrupts heap and can lead to code execution.

```
wolfSSL_OCSP_REQ_CTX_free(ret);
```

**Fix:** Set pointer to NULL immediately after free(). Enable AddressSanitizer in CI: -fsanitize=address.
---

### 176. [HIGH] Use-after-free pattern

**CWE-416** | `src/ocsp.c` line 1836

Freed pointer not immediately set to NULL. Dangling pointer reuse corrupts heap and can lead to code execution.

```
wolfSSL_OCSP_REQ_CTX_free(ret);
```

**Fix:** Set pointer to NULL immediately after free(). Enable AddressSanitizer in CI: -fsanitize=address.
---

### 177. [HIGH] Use-after-free pattern

**CWE-416** | `src/ocsp.c` line 2163

Freed pointer not immediately set to NULL. Dangling pointer reuse corrupts heap and can lead to code execution.

```
wolfSSL_ASN1_INTEGER_free(ser);
```

**Fix:** Set pointer to NULL immediately after free(). Enable AddressSanitizer in CI: -fsanitize=address.
---

### 178. [CRITICAL] Buffer overflow via unsafe string function

**CWE-120** | `wolfssl/wolfcrypt/types.h` line 1257

strcpy/strcat/sprintf/gets without bounds checking. Stack or heap overflow leads to code execution.

```
#define XSNPRINTF(f, len, ...) sprintf(f, __VA_ARGS__)
```

**Fix:** Use strncpy, strncat, snprintf with explicit size. Null-terminate manually. Prefer strlcpy/strlcat where available.
---

### 179. [CRITICAL] Format string vulnerability

**CWE-134** | `wolfssl/wolfcrypt/types.h` line 1282

User-controlled string passed as printf format argument. Attacker reads stack memory or overwrites return addresses via %n.

```
int xsnprintf(char *buffer, size_t bufsize,
```

**Fix:** Use a literal format string: printf("%s", user_input). Never pass user data as the format argument.
---

### 180. [HIGH] Integer overflow in size calculation

**CWE-190** | `wolfssl/wolfcrypt/types.h` line 820

Arithmetic in allocator argument can overflow to a small value, causing under-allocation and subsequent heap overflow.

```
WOLFSSL_API void *xrealloc(void *p, size_t n, void* heap, int type,
```

**Fix:** Validate sizes before arithmetic. Use calloc(n, size) for n*size. Check: if (n > SIZE_MAX / size) abort().
---

### 181. [HIGH] Use-after-free pattern

**CWE-416** | `wolfssl/wolfcrypt/types.h` line 832

Freed pointer not immediately set to NULL. Dangling pointer reuse corrupts heap and can lead to code execution.

```
#define XFREE(p, h, t)   m2mb_os_free(xp)
```

**Fix:** Set pointer to NULL immediately after free(). Enable AddressSanitizer in CI: -fsanitize=address.
---

### 182. [HIGH] Use-after-free pattern

**CWE-416** | `wolfssl/wolfcrypt/types.h` line 835

Freed pointer not immediately set to NULL. Dangling pointer reuse corrupts heap and can lead to code execution.

```
m2mb_os_free(xp); } while (0)
```

**Fix:** Set pointer to NULL immediately after free(). Enable AddressSanitizer in CI: -fsanitize=address.
---

### 183. [HIGH] Use-after-free pattern

**CWE-416** | `wolfssl/wolfcrypt/types.h` line 869

Freed pointer not immediately set to NULL. Dangling pointer reuse corrupts heap and can lead to code execution.

```
#define XFREE(p, h, t)   do { (void)(h); (void)(t); free(p); } while (0) /* native heap */
```

**Fix:** Set pointer to NULL immediately after free(). Enable AddressSanitizer in CI: -fsanitize=address.
---

### 184. [HIGH] Use-after-free pattern

**CWE-416** | `wolfssl/wolfcrypt/types.h` line 871

Freed pointer not immediately set to NULL. Dangling pointer reuse corrupts heap and can lead to code execution.

```
#define XFREE(p, h, t)   do { void* xp = (p); (void)(h); if (xp) free(xp); } while (0) /* native heap */
```

**Fix:** Set pointer to NULL immediately after free(). Enable AddressSanitizer in CI: -fsanitize=address.
---

### 185. [HIGH] Use-after-free pattern

**CWE-416** | `wolfcrypt/src/port/Espressif/esp_sdk_mem_lib.c` line 246

Freed pointer not immediately set to NULL. Dangling pointer reuse corrupts heap and can lead to code execution.

```
free(sample_heap_var);
```

**Fix:** Set pointer to NULL immediately after free(). Enable AddressSanitizer in CI: -fsanitize=address.
---

### 186. [HIGH] Missing NULL check after allocation

**CWE-476** | `wolfcrypt/src/port/Espressif/esp_sdk_mem_lib.c` line 239

Return value of malloc/realloc not checked for NULL. On allocation failure the program dereferences NULL, causing a crash or exploitable condition.

```
sample_heap_var = malloc(1);
```

**Fix:** Always check: ptr = malloc(n); if (!ptr) { handle_error(); return; }
---

### 187. [HIGH] Missing NULL check after allocation

**CWE-476** | `wolfcrypt/src/port/Espressif/esp_sdk_mem_lib.c` line 386

Return value of malloc/realloc not checked for NULL. On allocation failure the program dereferences NULL, causing a crash or exploitable condition.

```
ret = realloc(ptr, size);
```

**Fix:** Always check: ptr = malloc(n); if (!ptr) { handle_error(); return; }
---

### 188. [HIGH] Missing NULL check after allocation

**CWE-476** | `wolfcrypt/src/port/Espressif/esp_sdk_mem_lib.c` line 394

Return value of malloc/realloc not checked for NULL. On allocation failure the program dereferences NULL, causing a crash or exploitable condition.

```
ret = realloc(ptr, size);
```

**Fix:** Always check: ptr = malloc(n); if (!ptr) { handle_error(); return; }
---

### 189. [HIGH] Missing NULL check after allocation

**CWE-476** | `wolfcrypt/src/port/Espressif/esp_sdk_mem_lib.c` line 397

Return value of malloc/realloc not checked for NULL. On allocation failure the program dereferences NULL, causing a crash or exploitable condition.

```
ret = realloc(ptr, size);
```

**Fix:** Always check: ptr = malloc(n); if (!ptr) { handle_error(); return; }
---

### 190. [HIGH] Use-after-free pattern

**CWE-416** | `IDE/Espressif/ESP-IDF/examples/wolfssl_server/main/server-tls.c` line 408

Freed pointer not immediately set to NULL. Dangling pointer reuse corrupts heap and can lead to code execution.

```
wolfSSL_free(ssl);      /* Free the wolfSSL object              */
```

**Fix:** Set pointer to NULL immediately after free(). Enable AddressSanitizer in CI: -fsanitize=address.
---

### 191. [HIGH] Use-after-free pattern

**CWE-416** | `IDE/Espressif/ESP-IDF/examples/wolfssl_server/main/server-tls.c` line 417

Freed pointer not immediately set to NULL. Dangling pointer reuse corrupts heap and can lead to code execution.

```
wolfSSL_free(ssl);      /* Free the wolfSSL object                  */
```

**Fix:** Set pointer to NULL immediately after free(). Enable AddressSanitizer in CI: -fsanitize=address.
---

### 192. [HIGH] Use-after-free pattern

**CWE-416** | `IDE/Espressif/ESP-IDF/examples/wolfssl_server/main/server-tls.c` line 418

Freed pointer not immediately set to NULL. Dangling pointer reuse corrupts heap and can lead to code execution.

```
wolfSSL_CTX_free(ctx);  /* Free the wolfSSL context object          */
```

**Fix:** Set pointer to NULL immediately after free(). Enable AddressSanitizer in CI: -fsanitize=address.
---
