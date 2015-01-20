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
		printf("%d                 %d\n", array1Ptr[i] ,array2Ptr[i]);
	}
	return 1;
}
