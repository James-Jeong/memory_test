#ifndef __TEST_H__
#define __TEST_H__

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//////////////////////////////////////////////////////////
// Definitions & Macros for test_t
//////////////////////////////////////////////////////////

/** 이름 최대 길이 */
#define MAX_LEN     10
/** 성공 */
#define SUCCESS     1
/** 실패 */
#define FAIL        0

typedef struct node_s node_t;
struct node_s{
    int index;
    char place[MAX_LEN];
};

typedef struct test_s test_t;
struct test_s{
    node_t node[1];
    char name[MAX_LEN];
};

//////////////////////////////////////////////////////////
// Functions for jmem_t
//////////////////////////////////////////////////////////

test_t* test_create();
int test_init( test_t *test);
void test_final( test_t *test);
void test_destroy( test_t **test);

char* test_set_node( test_t *test, const int index, const char *place);
char* test_set_name( test_t *test, const char *name);
node_t* test_get_node( test_t *test);
char* test_get_name( test_t *test);

#endif // #ifndef __JMEM_H__

