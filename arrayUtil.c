#include <stdlib.h>
#include "expr_assert.h"
#include "arrayUtil.h"

int areEqual(ArrayUtil array1, ArrayUtil array2){
	int i,biggerLength;
	char *array1Ptr = (char *)(array1.base);
	char *array2Ptr = (char *)(array2.base);
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
	int i,totalBytes=array.length*array.typeSize;
	int newIndex = (length-array.length)*array.typeSize;
	array.base = realloc(array.base,length*array.typeSize);
	for(i = 0;i < totalBytes; i++)
		((char *)array.base)[i+newIndex] = 0;
	array.length = length;
	return array;
};

int findIndex(ArrayUtil array, void * element){
	int i = 0,totalBytes = array.length*array.typeSize;
	char *arrayPtr = (char *)array.base;
	char *elePtr = (char *)element;
	while(i < totalBytes){
		if(arrayPtr[i] == *elePtr)
			return i/array.typeSize;
		i = i + array.typeSize;
	}
	return -1;
}

void dispose(ArrayUtil array){
	free(array.base);
	array.length = 0;
	array.typeSize = 0;
}


	// int i, *resultBase, lengthDiff,typeSize;
	// char *arrayPtr = (char *)(array.base);
	// lengthDiff = length - array.length;
	// typeSize = array.typeSize;
	// resultBase = realloc(array.base,typeSize*lengthDiff);
	// for (i = 0; i < lengthDiff; ++i){
	// 	if(i < array.length)
	// 		resultBase[i+array.length] = 0;
	// }
	// array.base = resultBase;
	// array.length = length;
	// array.typeSize = typeSize;
	// return array;


	// int i, typeSize, *resultBase;
	// int *arrayPtr = (int *)(array.base);
	// typeSize = sizeof(arrayPtr[0]);
	// resultBase = calloc(length,typeSize);
	// for (i = 0; i < length; ++i){
	// 	if(i < array.length)
	// 		resultBase[i] = arrayPtr[i];
	// }
	// array.base = resultBase;
	// array.length = length;
	// array.typeSize = typeSize;
	// return array;