#include <CUnit/CUnit.h>
#include <CUnit/Basic.h>
#include <stdio.h>

void test_example() {
    CU_ASSERT(2 + 2 == 4);
}

int main() {
    CU_initialize_registry();
    CU_pSuite suite = CU_add_suite("Example Suite", 0, 0);
    CU_add_test(suite, "Test Example", test_example);
    CU_basic_run_tests();
    CU_cleanup_registry();
    return 0;
}
