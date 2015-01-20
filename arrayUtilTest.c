#include "expr_assert.h"
#include <stdlib.h>
#include "arrayUtil.h"

test_that_should_give_1_when_integer_arrays_are_equal(){
	int firstArray[4] = {1,2,3,4};
	int secondArray[4] = {1,2,3,4};

	arrayUtil array1;
	arrayUtil array2;

	array1.base = firstArray;
	array1.typeSize = 4;
	array1.length = 4;

	array2.base = secondArray;
	array2.typeSize = 4;
	array2.length = 4;

	assertEqual(areEqual(&array1, &array2),1);
}

test_that_should_give_1_when_float_arrays_are_equal(){
	float firstArray[4] = {1.4,2.32,3.14,4.43};
	float secondArray[4] = {1.4,2.32,3.14,4.43};

	arrayUtil array1;
	arrayUtil array2;

	array1.base = firstArray;
	array1.typeSize = 4;
	array1.length = 4;

	array2.base = secondArray;
	array2.typeSize = 4;
	array2.length = 4;

	assertEqual(areEqual(&array1, &array2),1);
}

test_that_should_give_1_when_char_arrays_are_equal(){
	char *firstArray = "vijay";
	char *secondArray = "vijay";

	arrayUtil array1;
	arrayUtil array2;

	array1.base = firstArray;
	array1.typeSize = 1;
	array1.length = 5;

	array2.base = secondArray;
	array2.typeSize = 1;
	array2.length = 5;

	assertEqual(areEqual(&array1, &array2),1);
}

test_that_should_give_0_when_integer_arrays_are_not_equal(){
	int firstArray[4] = {1,2,3,5};
	int secondArray[4] = {1,2,3,4};

	arrayUtil array1;
	arrayUtil array2;

	array1.base = firstArray;
	array1.typeSize = 4;
	array1.length = 4;

	array2.base = secondArray;
	array2.typeSize = 4;
	array2.length = 4;

	assertEqual(areEqual(&array1, &array2),0);
}

test_that_should_give_0_when_float_arrays_are_not_equal(){
	float firstArray[4] = {1.413,2.32,3.14,4.4};
	float secondArray[4] = {1.41,2.32,3.14,4.43};

	arrayUtil array1;
	arrayUtil array2;

	array1.base = firstArray;
	array1.typeSize = 4;
	array1.length = 4;

	array2.base = secondArray;
	array2.typeSize = 4;
	array2.length = 4;

	assertEqual(areEqual(&array1, &array2),0);
}

test_that_should_give_0_when_char_arrays_are_not_equal(){
	char *firstArray = "vijiy";
	char *secondArray = "vijay";

	arrayUtil array1;
	arrayUtil array2;

	array1.base = firstArray;
	array1.typeSize = 1;
	array1.length = 5;

	array2.base = secondArray;
	array2.typeSize = 1;
	array2.length = 5;

	assertEqual(areEqual(&array1, &array2),0);
}

test_that_should_give_0_when_size_of_arrays_are_not_equal(){
	char *firstArray = "vijayp";
	char *secondArray = "vijay";

	arrayUtil array1;
	arrayUtil array2;

	array1.base = firstArray;
	array1.typeSize = 1;
	array1.length = 6;

	array2.base = secondArray;
	array2.typeSize = 1;
	array2.length = 5;

	assertEqual(areEqual(&array1, &array2),0);
}

test_that_should_give_1_when_type_of_arrays_are_not_equal(){
	int firstArray[4] = {1,2,3,4};
	float secondArray[4] = {1,2,3,4};

	arrayUtil array1;
	arrayUtil array2;

	array1.base = firstArray;
	array1.typeSize = 1;
	array1.length = 5;

	array2.base = secondArray;
	array2.typeSize = 1;
	array2.length = 5;

	assertEqual(areEqual(&array1, &array2),0);
}

// test_that_function_creates_new_array_or_not(){
// 	arrayUtil array = create()

// }




























