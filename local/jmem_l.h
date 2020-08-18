#ifndef __JMEM_H__
#define __JMEM_H__

//////////////////////////////////////////////////////////
// definition & macro for jmem_t
//////////////////////////////////////////////////////////
#include <stdio.h>

/** 성공 여부 */
#define MEM_SUCCESS 1
/** 실패 여부 */
#define MEM_FAIL -1
/** 메모리 비교 시 동일 */
#define MEM_EQUAL 0
/** 메모리 비교 시 큼 */
#define MEM_G 1
/** 메모리 비교 시 작음 */
#define MEM_L -1

//////////////////////////////////////////////////////////
// function for jmem_t
//////////////////////////////////////////////////////////
int jmemcmp( const void *ptr1, const void *ptr2, size_t num);
void* jmemcpy( void *destination, const void *source, size_t num);
void* jmemset( void *ptr, int value, size_t num);
void* jmemmove( void *destination, const void *source, size_t num);

#endif // #ifndef __JMEM_H__

