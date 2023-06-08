#include "../general.h"
#include "libt.h"

uint64_t	*double_word_copy(uint64_t *dst, uint64_t *src, uint64_t size){
	for (size_t i = 0; i < size; i++)
        dst[i] = src[i];
    return dst;
}