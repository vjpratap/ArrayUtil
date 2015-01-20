#include <stdlib.h>
#include "expr_assert.h"
#include "arrayUtil.h"

int areEqual(arrayUtil *array1, arrayUtil *array2){
	int i,biggerLength;
	int *array1Ptr = (int *)(array1->base);
	int *array2Ptr = (int *)(array2->base);
	if(array1->length != array2->length || array1->typeSize != array2->typeSize)
		return 0;
	biggerLength = array1->length > array2->length ? array1->length : array2->length;
	for (i = 0; i < biggerLength; i++){
		if(array1Ptr[i] != array2Ptr[i])
			return 0;
	}
	return 1;
}

arrayUtil create(int typeSize, int length){
	arrayUtil array;
	void *base = calloc(length, typeSize);
	array.base = base;
	array.typeSize = typeSize;
	array.length = length;
	return array;
}

arrayUtil resize(arrayUtil *array, int length){
	int i, typeSize, *resultBase;
	int *arrayPtr = (int *)(array->base);
	typeSize = sizeof(arrayPtr[0]);
	resultBase = calloc(length,typeSize);
	for (i = 0; i < length; ++i){
		if(i < array->length)
			resultBase[i] = arrayPtr[i];
	}
	array->base = resultBase;
	array->length = length;
	array->typeSize = typeSize;
	return *array;
}

int findIndex(arrayUtil *array, void * element){
	int i;
	int *arrayPtr = (int *)(array->base);
	int *elementPtr = (int *)(element);
	for (i = 0; i < array->length; ++i){
		if(arrayPtr[i] == *elementPtr)
			return i;
	}
	return -1;
}