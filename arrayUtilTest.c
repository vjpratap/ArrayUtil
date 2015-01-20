#include "expr_assert.h"
#include <stdlib.h>
#include "arrayUtil.h"

void test_that_should_give_1_when_integer_arrays_are_equal(){
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

void test_that_should_give_1_when_float_arrays_are_equal(){
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

void test_that_should_give_1_when_char_arrays_are_equal(){
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

void test_that_should_give_0_when_integer_arrays_are_not_equal(){
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

void test_that_should_give_0_when_float_arrays_are_not_equal(){
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

void test_that_should_give_0_when_char_arrays_are_not_equal(){
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

void test_that_should_give_0_when_size_of_arrays_are_not_equal(){
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

void test_that_should_give_1_when_type_of_arrays_are_not_equal(){
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

void test_that_function_creates_new_array_or_not(){
	arrayUtil array = create(4,3);
	int *createArray  = (int*)array.base;
	assertEqual(createArray[0], 0);
	assertEqual(createArray[2], 0);
	assertEqual(array.length, 3);
	assertEqual(array.typeSize, 4);
}

void test_that_function_extends_the_given_array_size(){
	int array[] = {1,2,3,4,5};
	arrayUtil util,resultArray;
	int *resizeArray;
	util.base = array;
	util.typeSize = 4;
	util.length = 5;

	resultArray = resize(&util, 7);
	resizeArray = resultArray.base;
	assertEqual(resizeArray[0], 1);
	assertEqual(resizeArray[4], 5);
	assertEqual(resizeArray[5], 0);
	assertEqual(resizeArray[6], 0);
	assertEqual(resultArray.length, 7);
	assertEqual(resultArray.typeSize, 4);
}

void test_that_function_reduce_the_given_array_size(){
	int array[] = {1,2,3,4,5};
	arrayUtil util,resultArray;
	int *resizeArray;
	util.base = array;
	util.typeSize = 4;
	util.length = 5;

	resultArray = resize(&util, 3);
	resizeArray = resultArray.base;
	assertEqual(resizeArray[0], 1);
	assertEqual(resizeArray[2], 3);
	assertEqual(resultArray.length, 3);
	assertEqual(resultArray.typeSize, 4);
}

void test_that_that_function_gives_the_index_of_the_element_of_an_array(){
	int array[] = {1,2,3,4,5};
	int x = 3;
	arrayUtil util;
	util.base = array;
	util.typeSize = 4;
	util.length = 5;
	assertEqual(findIndex(&util, &x), 2);
}

void test_that_that_function_gives_the_index_of_the_element_of_a_float_array(){
	float name[] = {1,2,3,4,5};
	float x = 4;
	arrayUtil util;
	util.base = name;
	util.typeSize = 4;
	util.length = 5;
	assertEqual(findIndex(&util, &x), 3);
}






























