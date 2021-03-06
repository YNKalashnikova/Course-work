#include "functions.h"
#include "sort.h"
#include <ctest.h>

size_t check_sort_uint(uint32_t* arr, size_t n)
{
    for (size_t i = 0; i < n - 1; i++) {
        if (arr[i + 1] < arr[i]) {
            return 0;
        }
    }
    return 1;
}

size_t check_sort_double(double* arr, size_t n)
{
    for (size_t i = 0; i < n - 1; i++) {
        if (arr[i + 1] < arr[i]) {
            return 0;
        }
    }
    return 1;
}

CTEST(check_invalid_string, invalid_minus)
{
    char string[] = "--1\n";
    size_t is_uint = 1;
    size_t expect = 0;
    size_t result = check_string(string, &is_uint);
    ASSERT_EQUAL(expect, result);
}

CTEST(check_invalid_string, invalid_minus_position)
{
    char string[] = "1-5\n";
    size_t is_uint = 1;
    size_t expect = 0;
    size_t result = check_string(string, &is_uint);
    ASSERT_EQUAL(expect, result);
}

CTEST(check_invalid_string, illegal_symbol)
{
    char string[] = "5b\n";
    size_t is_uint = 1;
    size_t expect = 0;
    size_t result = check_string(string, &is_uint);
    ASSERT_EQUAL(expect, result);
}

CTEST(check_invalid_string, illegal_symbol_2)
{
    char string[] = "b\n";
    size_t is_uint = 1;
    size_t expect = 0;
    size_t result = check_string(string, &is_uint);
    ASSERT_EQUAL(expect, result);
}

CTEST(check_invalid_string, illegal_symbol_3)
{
    char string[] = "1 . 5\n";
    size_t is_uint = 1;
    size_t expect = 0;
    size_t result = check_string(string, &is_uint);
    ASSERT_EQUAL(expect, result);
}

CTEST(check_invalid_string, illegal_symbol_4)
{
    char string[] = " 1.5\n";
    size_t is_uint = 1;
    size_t expect = 0;
    size_t result = check_string(string, &is_uint);
    ASSERT_EQUAL(expect, result);
}

CTEST(check_invalid_string, invalid_double)
{
    char string[] = ".5\n";
    size_t is_uint = 1;
    size_t expect = 0;
    size_t result = check_string(string, &is_uint);
    ASSERT_EQUAL(expect, result);
}

CTEST(check_invalid_string, invalid_double_2)
{
    char string[] = "5.\n";
    size_t is_uint = 1;
    size_t expect = 0;
    size_t result = check_string(string, &is_uint);
    ASSERT_EQUAL(expect, result);
}

CTEST(check_invalid_string, invalid_double_3)
{
    char string[] = "5.0.0\n";
    size_t is_uint = 1;
    size_t expect = 0;
    size_t result = check_string(string, &is_uint);
    ASSERT_EQUAL(expect, result);
}

CTEST(check_invalid_string, invalid_double_4)
{
    char string[] = "-.5\n";
    size_t is_uint = 1;
    size_t expect = 0;
    size_t result = check_string(string, &is_uint);
    ASSERT_EQUAL(expect, result);
}

CTEST(check_invalid_string, minus_zero)
{
    char string[] = "-0\n";
    size_t is_uint = 1;
    size_t expect = 0;
    size_t result = check_string(string, &is_uint);
    ASSERT_EQUAL(expect, result);
}

CTEST(check_invalid_string, minus_zero_2)
{
    char string[] = "-0.000000\n";
    size_t is_uint = 1;
    size_t expect = 0;
    size_t result = check_string(string, &is_uint);
    ASSERT_EQUAL(expect, result);
}

CTEST(check_invalid_string, empty_string)
{
    char string[] = "\n";
    size_t is_uint = 1;
    size_t expect = 0;
    size_t result = check_string(string, &is_uint);
    ASSERT_EQUAL(expect, result);
}

CTEST(check_invalid_string, invalid_int)
{
    char string[] = "01\n";
    size_t is_uint = 1;
    size_t expect = 0;
    size_t result = check_string(string, &is_uint);
    ASSERT_EQUAL(expect, result);
}

CTEST(check_valid_string, valid_uint)
{
    char string[] = "0\n";
    size_t is_uint = 1;
    size_t expect = 1;
    size_t result = check_string(string, &is_uint);
    ASSERT_EQUAL(expect, result);
}

CTEST(check_valid_string, valid_uint_2)
{
    char string[] = "1000\n";
    size_t is_uint = 1;
    size_t expect = 1;
    size_t result = check_string(string, &is_uint);
    ASSERT_EQUAL(expect, result);
}

CTEST(check_valid_string, valid_double)
{
    char string[] = "-10\n";
    size_t is_uint = 1;
    size_t expect = 1;
    size_t result = check_string(string, &is_uint);
    ASSERT_EQUAL(expect, result);
}

CTEST(check_valid_string, valid_double_2)
{
    char string[] = "1.05\n";
    size_t is_uint = 1;
    size_t expect = 1;
    size_t result = check_string(string, &is_uint);
    ASSERT_EQUAL(expect, result);
}

CTEST(check_valid_string, valid_double_3)
{
    char string[] = "-0.05\n";
    size_t is_uint = 1;
    size_t expect = 1;
    size_t result = check_string(string, &is_uint);
    ASSERT_EQUAL(expect, result);
}

CTEST(check_string, number_type_identify)
{
    char string[] = "-0.05\n";
    size_t result = 1;
    size_t expect = 0;
    check_string(string, &result);
    ASSERT_EQUAL(expect, result);
}

CTEST(check_string, number_type_identify_2)
{
    char string[] = "0.05\n";
    size_t result = 1;
    size_t expect = 0;
    check_string(string, &result);
    ASSERT_EQUAL(expect, result);
}

CTEST(check_string, number_type_identify_3)
{
    char string[] = "-50\n";
    size_t result = 1;
    size_t expect = 0;
    check_string(string, &result);
    ASSERT_EQUAL(expect, result);
}

CTEST(check_string, number_type_identify_4)
{
    char string[] = "50\n";
    size_t result = 1;
    size_t expect = 1;
    check_string(string, &result);
    ASSERT_EQUAL(expect, result);
}

CTEST(counting_sort, decreasing_array)
{
    uint32_t mass[10] = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
    counting_sort(mass, 10);
    size_t result = check_sort_uint(mass, 10);
    size_t expect = 1;
    ASSERT_EQUAL(expect, result);
}

CTEST(counting_sort, flat_array)
{
    uint32_t mass[10] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1};
    counting_sort(mass, 10);
    size_t result = check_sort_uint(mass, 10);
    size_t expect = 1;
    ASSERT_EQUAL(expect, result);
}

CTEST(counting_sort, sorted_array)
{
    uint32_t mass[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    counting_sort(mass, 10);
    size_t result = check_sort_uint(mass, 10);
    size_t expect = 1;
    ASSERT_EQUAL(expect, result);
}

CTEST(insertion_sort, decreasing_array)
{
    double mass[10] = {10.1, 9.24, 8, 7, 6, 5, 4, 3, 2, 1};
    insertion_sort(mass, 10);
    size_t result = check_sort_double(mass, 10);
    size_t expect = 1;
    ASSERT_EQUAL(expect, result);
}

CTEST(insertion_sort, flat_array)
{
    double mass[10] = {1.1, 1.1, 1.1, 1.1, 1.1, 1.1, 1.1, 1.1, 1.1, 1.1};
    insertion_sort(mass, 10);
    size_t result = check_sort_double(mass, 10);
    size_t expect = 1;
    ASSERT_EQUAL(expect, result);
}

CTEST(insertion_sort, sorted_array)
{
    double mass[10] = {-1, 2.2, 3, 4, 5, 6, 7, 8, 9, 10};
    insertion_sort(mass, 10);
    size_t result = check_sort_double(mass, 10);
    size_t expect = 1;
    ASSERT_EQUAL(expect, result);
}

CTEST(merge_sort, decreasing_array)
{
    double mass[1100];
    double j = 1100;
    for (size_t i = 0; i < 1100; i++) {
        mass[i] = j;
        j--;
    }
    merge_sort(mass, 0, 1100);
    size_t result = check_sort_double(mass, 1100);
    size_t expect = 1;
    ASSERT_EQUAL(expect, result);
}

CTEST(merge_sort, flat_array)
{
    double mass[1100];
    for (size_t i = 0; i < 1100; i++) {
        mass[i] = -1.1;
    }
    merge_sort(mass, 0, 1100);
    size_t result = check_sort_double(mass, 1100);
    size_t expect = 1;
    ASSERT_EQUAL(expect, result);
}

CTEST(merge_sort, sorted_array)
{
    double mass[1100];
    for (size_t i = 0; i < 1100; i++) {
        mass[i] = i;
    }
    merge_sort(mass, 0, 1100);
    size_t result = check_sort_double(mass, 1100);
    size_t expect = 1;
    ASSERT_EQUAL(expect, result);
}
