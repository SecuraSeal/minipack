#include "minunit.h"
#include <minipack.h>

#include "memdump.h"

//==============================================================================
//
// Test Cases
//
//==============================================================================

int test_array32_read_count() {
    mu_assert(minipack_array32_read_count("\xDD\x00\x00\x00\x00") == 0);
    mu_assert(minipack_array32_read_count("\xDD\x00\x00\x00\x05") == 5);
    mu_assert(minipack_array32_read_count("\xDD\x00\x00\x01\x00") == 256);
    return 0;
}

int test_array32_write_header() {
    uint8_t data[] = {0x00, 0x00, 0x00, 0x00, 0x00};

    minipack_array32_write_header(data, 0);
    mu_assert_mem(data, 5, "\xDD\x00\x00\x00\x00");

    minipack_array32_write_header(data, 5);
    mu_assert_mem(data, 5, "\xDD\x00\x00\x00\x05");

    return 0;
}


//==============================================================================
//
// Setup
//
//==============================================================================

int all_tests() {
    mu_run_test(test_array32_read_count);
    mu_run_test(test_array32_write_header);
    return 0;
}

RUN_TESTS()