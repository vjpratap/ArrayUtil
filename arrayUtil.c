#include <stdlib.h>
#include "expr_assert.h"
#include "arrayUtil.h"

int areEqual(ArrayUtil array1, ArrayUtil array2){
	int i,biggerLength;
	char *array1Ptr = (char *)(array1.base);
	char *array2Ptr = (char *)(array2.base);
	if(array1.length != array2.length || array1.typeSize != array2.typeSize)
		return 0;
	// biggerLength = array1.length > array2.length ? array1.length : array2.length;
	for (i = 0; i < array1.length*array1.typeSize; i++){
		if(array1Ptr[i] != array2Ptr[i])
			return 0;
	}
	return 1;
}

ArrayUtil create(int typeSize, int length){
	ArrayUtil array;
	void *base = calloc(length, typeSize);
	array.base = base;
	array.typeSize = typeSize;
	array.length = length;
	return array;
}

ArrayUtil resize(ArrayUtil array, int length){
	int i, typeSize, *resultBase;
	int *arrayPtr = (int *)(array.base);
	typeSize = sizeof(arrayPtr[0]);
	resultBase = calloc(length,typeSize);
	for (i = 0; i < length; ++i){
		if(i < array.length)
			resultBase[i] = arrayPtr[i];
	}
	array.base = resultBase;
	array.length = length;
	array.typeSize = typeSize;
	return array;
}

int findIndex(ArrayUtil array, void * element){
	int i;
	int *arrayPtr = (int *)(array.base);
	int *elementPtr = (int *)(element);
	for (i = 0; i < array.length; ++i){
		if(arrayPtr[i] == *elementPtr)
			return i;
	}
	return -1;
}
