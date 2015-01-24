#include <stdlib.h>
#include "expr_assert.h"
#include "arrayUtil.h"

int areEqual(ArrayUtil array1, ArrayUtil array2){
	int i,biggerLength;
	basePtr array1Ptr = (basePtr)array1.base;
	basePtr array2Ptr = (basePtr)array2.base;
	if(array1.length != array2.length || array1.typeSize != array2.typeSize)
		return 0;
	for (i = 0; i < array1.length*array1.typeSize; i++){
		if(array1Ptr[i] != array2Ptr[i])
			return 0;
	}
	return 1;
}

ArrayUtil create(int typeSize, int length){
	ArrayUtil array = {calloc(length, typeSize), typeSize, length};
	return array;
}

ArrayUtil resize(ArrayUtil array,int length){
	void *base;
	int shortLength = length <= array.length?length:array.length;
	int longLength = length>=array.length?length:array.length;
	base = calloc(longLength,array.typeSize);
	memcpy(base,array.base,shortLength * array.typeSize);
	array.base=base;
	array.length = length;
	return array;
};

int findIndex(ArrayUtil array, void * element){
	int i = 0,j = 0,totalBytes = array.length*array.typeSize;
	basePtr arrayPtr = (basePtr)array.base;
	basePtr elePtr = (basePtr)element;
	for (i = 0; i < totalBytes; i++){
		if(arrayPtr[i] != elePtr[j])
			j = 0;
		if(arrayPtr[i] == elePtr[j])
			j = j + 1;
		if(j == array.typeSize)
			return i/array.typeSize;
	}
	return -1;
}

void dispose(ArrayUtil array){
	free(array.base);
	array.length = 0;
	array.typeSize = 0;
}

void* findFirst(ArrayUtil util, MatchFunc* match, void* hint){
	int i;
	basePtr array = (basePtr)util.base;
	void* element;
	for(i=0;i<util.length;i++){
		element = &(array[i*util.typeSize]);;
		if(match(hint, element))
			return element;
	}
	return NULL;
}

