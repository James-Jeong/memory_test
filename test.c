#include "local/test_l.h"

//////////////////////////////////////////////////////////
// Local Functions for jmem_t
//////////////////////////////////////////////////////////

test_t* test_create(){
    int return_value = FAIL;

    test_t *test = (test_t*)calloc( sizeof( test_t), 0);
    if( test == NULL){
        printf("\t| ! 객체 메모리 생성 오류. in test_create function\n");
        return NULL;
    }

    return_value = test_init( test);
    if( return_value == FAIL){
        printf("\t| ! 객체 초기화 오류. in test_create function\n");
        return NULL;
    }

    printf("\t| @ 할당 성공\n");
    return test;
}

int test_init( test_t *test){
    if( test == NULL){
        printf("\t| ! 객체 참조 오류. in test_init function\n");
        return FAIL;
    }

    test->node->index = 0;
    return SUCCESS;
}

void test_final( test_t *test){
    if( test == NULL){
        printf("\t| ! 객체 참조 오류. in test_final function\n");
        return ;
    }

    test->node->index = 0;
    test->node->place[0] = '\0';
    test->name[0] = '\0';
}

void test_destroy( test_t **test){
    if( test == NULL){
        printf("\t| ! 객체 참조 오류. in test_destroy function\n");
        return ;
    }

    test_final( *test);
    free( *test);
    *test = NULL;

    printf("\t| @ 해제 성공\n");
}

char* test_set_node( test_t *test, const int index, const char *place){
    if( test == NULL){
        printf("\t| ! 객체 참조 오류. in test_set_node function\n");
        return FAIL;
    }

    if( index == 0){
        printf("\t| ! 0 은 허용되지 않음. in test_set_node function\n");
        return FAIL;
    }

    if(( place == NULL) || ( strlen( place) == 0)){
        printf("\t| ! 잘못된 장소 이름(길이:0). in test_set_node function\n");
        return NULL;
    }

    test->node->index = index;
    return strncpy( test->node->place, place, MAX_LEN);
}

char* test_set_name( test_t *test, const char *name){
    if( test == NULL){
        printf("\t| ! 객체 메모리 생성 오류. in test_set_name function\n");
        return NULL;
    }

    if(( name == NULL) || ( strlen( name) == 0)){
        printf("\t| ! 잘못된 이름(길이:0). in test_set_node function\n");
        return NULL;
    }

    return strncpy( test->name, name, MAX_LEN);
}

node_t* test_get_node( test_t *test){
    if( test == NULL){
        printf("\t| ! 객체 참조 오류. in test_get_node function\n");
        return NULL;
    }

    return test->node;
}

char* test_get_name( test_t *test){
    if( test == NULL){
        printf("\t| ! 객체 참조 오류. in test_get_name function\n");
        return NULL;
    }

    return test->name;
}
