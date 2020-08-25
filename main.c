#include "local/jmem_l.h"
#include "local/test_l.h"

int main( int argc, char **argv){
    int return_value_int = MEM_FAIL;
    void* return_value_ptr = NULL;

    test_t *test1 = test_create();
    if( test1 == NULL){
        printf("\t| ! test1 할당 실패.\n");
        return FAIL;
    }

    test_t *test2 = test_create(); 
    if( test2 == NULL){
        printf("\t| ! test2 할당 실패.\n");
        return FAIL;
    }

    test_t *test3 = NULL;

    return_value_ptr = test_set_node( test1, 1, "home");
    if( return_value_ptr == NULL){
        printf("\t| ! test1 node 초기화 실패.\n");
        return FAIL;
    }

    return_value_ptr = test_set_name( test1, "jamesj");
    if( return_value_ptr == NULL){
        printf("\t| ! test1 name 초기화 실패.\n");
        return FAIL;
    }

    test_set_node( test2, 2, "market");
    if( return_value_ptr == NULL){
        printf("\t| ! test2 node 초기화 실패.\n");
        return FAIL;
    }

    test_set_name( test2, "durazno");
    if( return_value_ptr == NULL){
        printf("\t| ! test2 name 초기화 실패.\n");
        return FAIL;
    }

    printf("\t| @ test1's node index(%d), place(%s) | name : %s\n", test_get_node( test1)->index, test_get_node( test1)->place, test_get_name( test1));
    printf("\t| @ test2's node index(%d), place(%s) | name : %s\n", test_get_node( test2)->index, test_get_node( test2)->place, test_get_name( test2));

    /** TEST START */

    /** Memory Compare */
    printf("\n\t| # Memory Compare Test\n");
    return_value_int = jmemcmp( test_get_name( test1), test_get_name( test2), MAX_LEN);
    if( return_value_int == MEM_EQUAL){
        printf("\t| @ test1's name is EQUAL to test2's name.\n");
    }
    else{
        printf("\t| @ test1's name is not EQUAL to test2's name.\n");
    }

    return_value_int = jmemcmp( test_get_node( test1), test_get_node( test2), sizeof( node_t));
    if( return_value_int == MEM_EQUAL){
        printf("\t| @ test1's node is EQUAL to test2's node.\n");
    }
    else{
        printf("\t| @ test1's node is not EQUAL to test2's node.\n");
    }

    return_value_int = jmemcmp( test_get_node( test1), test_get_node( test3), sizeof( node_t));
    if( return_value_int == MEM_EQUAL){
        printf("\t| @ test1's node is EQUAL to test3's node.\n");
    }
    else{
        printf("\t| @ test1's node is not EQUAL to test3's node.\n");
    }

    /** Memory Copy */
    printf("\n\t| # Memory Copy Test\n");
    return_value_ptr = jmemcpy( test_get_name( test1), test_get_name( test2), MAX_LEN);
    if( return_value_ptr == NULL){
        printf("\t| ! Fail to copy.\n");
    }
    else{
        printf("\t| @ test1's name : %s\n", test_get_name( test1));
        printf("\t| @ test2's name : %s\n", test_get_name( test2));
    }

    return_value_ptr = jmemcpy( test_get_node( test1), test_get_node( test2), sizeof( node_t));
    if( return_value_ptr == NULL){
        printf("\t| ! Fail to copy.\n");
    }
    else{
        printf("\t| @ test1's node index(%d), place(%s)\n", test_get_node( test1)->index, test_get_node( test1)->place);
        printf("\t| @ test2's node index(%d), place(%s)\n", test_get_node( test2)->index, test_get_node( test2)->place);
    }

    return_value_ptr = jmemcpy( test_get_node( test1), test_get_node( test3), sizeof( node_t));
    if( return_value_ptr == NULL){
        printf("\t| ! Fail to copy.\n");
    }
    else{
        printf("\t| @ test1's node index(%d), place(%s)\n", test_get_node( test1)->index, test_get_node( test1)->place);
        printf("\t| @ test3's node index(%d), place(%s)\n", test_get_node( test3)->index, test_get_node( test3)->place);
    }

    return_value_ptr = jmemcpy( test_get_node( test3), test_get_node( test1), sizeof( node_t));
    if( return_value_ptr == NULL){
        printf("\t| ! Fail to copy.\n");
    }
    else{
        printf("\t| @ test1's node index(%d), place(%s)\n", test_get_node( test1)->index, test_get_node( test1)->place);
        printf("\t| @ test3's node index(%d), place(%s)\n", test_get_node( test3)->index, test_get_node( test3)->place);
    }

    /** Memory Set */
    printf("\n\t| # Memory Set Test\n");
    return_value_ptr = jmemset( test_get_name( test1), 0, MAX_LEN);
    if( return_value_ptr == NULL){
        printf("\t| ! Fail to set.\n");
    }
    else{
        printf("\t| @ test1's name : %s\n", test_get_name( test1));
    }

    return_value_ptr = jmemset( test_get_node( test1), 0, sizeof( node_t));
    if( return_value_ptr == NULL){
        printf("\t| ! Fail to set.\n");
    }
    else{
        printf("\t| @ test1's node index(%d), place(%s)\n", test_get_node( test1)->index, test_get_node( test1)->place);
    }

    return_value_ptr = jmemset( test_get_node( test3), 0, sizeof( node_t));
    if( return_value_ptr == NULL){
        printf("\t| ! Fail to set.\n");
    }
    else{
        printf("\t| @ test3's node index(%d), place(%s)\n", test_get_node( test3)->index, test_get_node( test3)->place);
    }

    /** Memory Move */
    printf("\n\t| # Memory Move Test\n");
    test_set_node( test2, 3, "hospital");
    test_set_name( test2, "jamesj");
    return_value_ptr = jmemmove( test_get_name( test1), test_get_name( test2), MAX_LEN);
    if( return_value_ptr == NULL){
        printf("\t| ! Fail to move.\n");
    }
    else{
        printf("\t| @ test1's name : %s\n", test_get_name( test1));
        printf("\t| @ test2's name : %s\n", test_get_name( test2));
    }

    return_value_ptr = jmemmove( test_get_node( test1), test_get_node( test2), sizeof( node_t));
    if( return_value_ptr == NULL){
        printf("\t| ! Fail to move.\n");
    }
    else{
        printf("\t| @ test1's node index(%d), place(%s)\n", test_get_node( test1)->index, test_get_node( test1)->place);
        printf("\t| @ test2's node index(%d), place(%s)\n", test_get_node( test2)->index, test_get_node( test2)->place);
    }

    return_value_ptr = jmemmove( test_get_node( test1), test_get_node( test3), sizeof( node_t));
    if( return_value_ptr == NULL){
        printf("\t| ! Fail to move.\n");
    }
    else{
        printf("\t| @ test1's node index(%d), place(%s)\n", test_get_node( test1)->index, test_get_node( test1)->place);
        printf("\t| @ test2's node index(%d), place(%s)\n", test_get_node( test3)->index, test_get_node( test3)->place);
    }

    return_value_ptr = jmemmove( test_get_node( test3), test_get_node( test1), sizeof( node_t));
    if( return_value_ptr == NULL){
        printf("\t| ! Fail to move.\n");
    }
    else{
        printf("\t| @ test1's node index(%d), place(%s)\n", test_get_node( test1)->index, test_get_node( test1)->place);
        printf("\t| @ test2's node index(%d), place(%s)\n", test_get_node( test3)->index, test_get_node( test3)->place);
    }

    /** TEST END */

    test_destroy( &test1);
    test_destroy( &test2);
}
