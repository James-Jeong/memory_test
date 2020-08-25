#include "local/jmem_l.h"

//////////////////////////////////////////////////////////
// function for jmem_t
//////////////////////////////////////////////////////////
int jmemcmp( const void *ptr1, const void *ptr2, size_t num){
	if( ptr1 == NULL || ptr2 == NULL || num <= 0) return MEM_FAIL;
	const char *cmp1 = ptr1, *cmp2 = ptr2;
	while( num--){
		if( *cmp1++ != *cmp2++){
			if( *cmp1 > *cmp2) return MEM_G;
			else return MEM_L;
		}
	}
	return MEM_EQUAL;
}

void* jmemcpy( void *destination, const void *source, size_t num){
	if( destination == NULL || source == NULL || num <= 0) return NULL;
	char *dest = destination;
	const char *src = source;
	while(( num--) && ( dest != NULL) && ( src != NULL)) *dest++ = *src++;
	return dest;
}

void* jmemset( void *ptr, int value, size_t num){
	if( ptr == NULL || num <= 0) return NULL;
	size_t i;
	char *dest = ptr;
	for( i = 0; i < num; i++) *( dest + i) = value;
	return dest;
}

void* jmemmove( void *destination, const void *source, size_t num){
	if( destination == NULL || source == NULL || num <= 0) return NULL;
	char *dest = destination;
	const char *src = source;
	if( dest <= src) while( num--) *dest++ = *src++;
	else{
		dest += num;
		src += num;
		while(( num--) && ( dest != NULL) && ( src != NULL)) *--dest = *--src;
	}
	return dest;
}

