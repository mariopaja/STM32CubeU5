/** \file fake_external_rng_for_test.c
 *
 * \brief Helper functions to test PSA crypto functionality.
 */

/*
 *  Copyright The Mbed TLS Contributors
 *  SPDX-License-Identifier: Apache-2.0
 */

#include <test/fake_external_rng_for_test.h>

#if defined(MBEDTLS_PSA_CRYPTO_EXTERNAL_RNG)
#include <test/random.h>
#include <psa/crypto.h>

static int test_insecure_external_rng_enabled = 0;

void mbedtls_test_enable_insecure_external_rng(void)
{
    test_insecure_external_rng_enabled = 1;
}

void mbedtls_test_disable_insecure_external_rng(void)
{
    test_insecure_external_rng_enabled = 0;
}

psa_status_t mbedtls_psa_external_get_random(
    mbedtls_psa_external_random_context_t *context,
    uint8_t *output, size_t output_size, size_t *output_length)
{
    (void) context;

    if (!test_insecure_external_rng_enabled) {
        return PSA_ERROR_INSUFFICIENT_ENTROPY;
    }

    /* This implementation is for test purposes only!
     * Use the libc non-cryptographic random generator. */
    mbedtls_test_rnd_std_rand(NULL, output, output_size);
    *output_length = output_size;
    return PSA_SUCCESS;
}
#endif /* MBEDTLS_PSA_CRYPTO_EXTERNAL_RNG */
