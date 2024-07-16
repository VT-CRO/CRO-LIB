#include "unity.h"
#include "util/PID.hpp"

void setUp(void) {
    // set stuff up here
}

void tearDown(void) {
    // clean stuff up here
}

void test_pid1(void) {
    PID pid = pidInit(10, 0, 0, 0, 0, 0, 0);

    float signal = pidCalculate(pid, 0, 0, 0.1);

    TEST_ASSERT_EQUAL(0, signal);
}

int main(void) {
    UNITY_BEGIN();
    RUN_TEST(test_pid1);
    return UNITY_END();
}