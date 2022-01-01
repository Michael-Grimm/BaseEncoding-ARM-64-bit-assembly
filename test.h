#ifndef MSG_TEST
#define MSG_TEST
#include <stdio.h>
#include <string.h>
int passed_tests = 0; 
int failed_tests = 0;

/**
 * Prints all functions starting with 'void test' of the importing file. 
 * Can be used to update a function that calls all the test cases.
 */
#define PRINT_TEST_FUNCTIONS  \
     char command[] = "cat " __FILE__ " | grep '^void test' | sed -e 's/void//' -e 's/{/;/'"; \
     FILE *f = popen(command, "w"); \
     pclose(f); 

/**
 * Tests two strings for equality.
 */
#define TEST_STRING_EQUALS(expected, actual) \
	if(strcmp(expected, actual) != 0){ \
		printf("%s, line %d: Expected %s, but was %s\n", __FUNCTION__, __LINE__, expected, actual); \
		failed_tests += 1; \
	}else{ \
		passed_tests += 1; \
	}

/**
 * Tests two integers for equality.
 */
#define TEST_INT_EQUALS(expected, actual) \
	if(expected != actual){ \
		printf("%s, line %d: Expected %d, but was %d\n", __FUNCTION__, __LINE__, expected, actual); \
		failed_tests += 1; \
	}else{ \
		passed_tests += 1; \
	}

/**
 * Tests two long long integers for equality.
 */
#define TEST_LONGLONG_EQUALS(expected, actual) \
	if(expected != actual){ \
		printf("%s, line %d: Expected %lld, but was %lld\n", __FUNCTION__, __LINE__, expected, actual); \
		failed_tests += 1; \
	}else{ \
		passed_tests += 1; \
	}

/**
 * Last command in the function that calls the test functions.
 * Prints the results.
 */
#define PRINT_TEST_RESULTS \
	printf("\nResults of testing %s: \nPassed tests: %d\nFailed tests: %d\n", __FILE__, passed_tests, failed_tests); \
    passed_tests = 0; \
    failed_tests = 0;
    
#endif


