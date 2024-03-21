/*
 *  Simple program to test that CMake builds with Mbed TLS as a subdirectory
 *  work correctly.
 *
 *  Copyright The Mbed TLS Contributors
 *  SPDX-License-Identifier: Apache-2.0
 */

#if !defined(MBEDTLS_CONFIG_FILE)
#include "mbedtls/config.h"
#else
#include MBEDTLS_CONFIG_FILE
#endif

#include "mbedtls/platform.h"

#include "mbedtls/version.h"

/* The main reason to build this is for testing the CMake build, so the program
 * doesn't need to do very much. It calls a single library function to ensure
 * linkage works, but that is all. */
int main()
{
    /* This version string is 18 bytes long, as advised by version.h. */
    char version[18];

    mbedtls_version_get_string_full(version);

    mbedtls_printf("Built against %s\n", version);

    return 0;
}
