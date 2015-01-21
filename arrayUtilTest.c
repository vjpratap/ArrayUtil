#include "expr_assert.h"
#include <stdlib.h>
#include "arrayUtil.h"

void test_that_should_give_1_when_integer_arrays_are_equal(){
	int firstArray[4] = {1,2,3,4};
	int secondArray[4] = {1,2,3,4};

	ArrayUtil array1 = {firstArray, sizeof(int), 4};
	ArrayUtil array2 = {secondArray, sizeof(int), 4};

	assertEqual(areEqual(array1, array2),1);
}

void test_that_should_give_1_when_float_arrays_are_equal(){
	float firstArray[4] = {1.4,2.32,3.14,4.43};
	float secondArray[4] = {1.4,2.32,3.14,4.43};

	ArrayUtil array1 = {firstArray, sizeof(float), 4};
	ArrayUtil array2 = {secondArray, sizeof(float), 4};

	assertEqual(areEqual(array1, array2),1);
}

void test_that_should_give_1_when_char_arrays_are_equal(){
	char *firstArray = "vijay";
	char *secondArray = "vijay";

	ArrayUtil array1 = {firstArray, sizeof(char), 5};
	ArrayUtil array2 = {secondArray, sizeof(char), 5};

	assertEqual(areEqual(array1, array2),1);
}

void test_that_should_give_0_when_integer_arrays_are_not_equal(){
	int firstArray[4] = {1,2,3,5};
	int secondArray[4] = {1,2,3,4};

	ArrayUtil array1 = {firstArray, sizeof(int), 4};
	ArrayUtil array2 = {secondArray, sizeof(int), 4};

	assertEqual(areEqual(array1, array2),0);
}

void test_that_should_give_0_when_float_arrays_are_not_equal(){
	float firstArray[4] = {1.413,2.32,3.14,4.4};
	float secondArray[4] = {1.41,2.32,3.14,4.43};

	ArrayUtil array1 = {firstArray, sizeof(float), 4};
	ArrayUtil array2 = {secondArray, sizeof(float), 4};

	assertEqual(areEqual(array1, array2),0);
}

void test_that_should_give_0_when_char_arrays_are_not_equal(){
	char *firstArray = "vijiy";
	char *secondArray = "vijay";

	ArrayUtil array1 = {firstArray, sizeof(char), 5};
	ArrayUtil array2 = {secondArray, sizeof(char), 5};
	
	assertEqual(areEqual(array1, array2),0);
}

void test_that_should_give_0_when_size_of_arrays_are_not_equal(){
	char *firstArray = "vijayp";
	char *secondArray = "vijay";

	ArrayUtil array1 = {firstArray, sizeof(char), 5};
	ArrayUtil array2 = {secondArray, sizeof(char), 6};

	assertEqual(areEqual(array1, array2),0);
}

void test_that_should_give_1_when_type_of_arrays_are_not_equal(){
	int firstArray[4] = {1,2,3,4};
	float secondArray[4] = {1,2,3,4};
	
	ArrayUtil array1 = {firstArray, sizeof(int), 4};
	ArrayUtil array2 = {secondArray, sizeof(float), 4};

	assertEqual(areEqual(array1, array2),0);
}

void test_that_function_creates_new_array_or_not(){
	ArrayUtil array = create(sizeof(int),3);
	int *createArray  = (int*)array.base;
	assertEqual(createArray[0], 0);
	assertEqual(createArray[2], 0);
	assertEqual(array.length, 3);
	assertEqual(array.typeSize, 4);
}

void test_that_function_extends_the_given_array_size(){
	ArrayUtil array = create(sizeof(int), 3);
	ArrayUtil expected = {(int[]){0,0,0,0,0}, sizeof(int), 5};
	ArrayUtil resultArray = resize(array, 5);
	assert(areEqual(expected, resultArray));
	assertEqual(resultArray.length, 5);
	assertEqual(resultArray.typeSize, 4);
}

void test_that_function_reduce_the_given_array_size(){
	ArrayUtil array = create(sizeof(int), 5);
	ArrayUtil expected = {(int[]){0,0,0}, sizeof(int), 3};
	ArrayUtil resultArray = resize(array, 3);

	assert(areEqual(expected, resultArray));
	assertEqual(resultArray.length, 3);
	assertEqual(resultArray.typeSize, 4);
}

void test_that_that_function_gives_the_index_of_the_element_of_an_array(){
	int array[] = {1,2,3,4,5}, x = 4;
	ArrayUtil util = {array, sizeof(int), 5};
	assertEqual(findIndex(util, &x), 3);
}

void test_that_function_gives_minus1_when_element_is_not_in_the_integer_array(){
	int array[] = {1,2,3,4,5}, x = 7;
	ArrayUtil util = {array, sizeof(int), 5};
	assertEqual(findIndex(util, &x), -1);
}

void test_that_that_function_gives_the_index_of_the_element_of_a_float_array(){
	float array[] = {1.23,2.21,3.43,4.432,5.223}, x = 3.43;
	ArrayUtil util = {array, sizeof(float), 5};
	assertEqual(findIndex(util, &x), 2);
}

void test_that_function_gives_minus1_when_element_is_not_in_the_float_array(){
	float array[] = {1.23,2.21,3.43,4.432,5.223}, x = 3.4344;
	ArrayUtil util = {array, sizeof(float), 5};
	assertEqual(findIndex(util, &x), -1);
}

void test_that_function_give_the_index_of_a_character_array(){
	char *name = "vijay", x = 'i';
	ArrayUtil util = {name, sizeof(char), 5};
	assertEqual(findIndex(util, &x), 1);
}

void test_that_function_give_minus1_when_element_is_not_in_the_character_array(){
	char *name = "vijay", x = 'p';
	ArrayUtil util = {name, sizeof(char), 5};
	assertEqual(findIndex(util, &x), -1);
}

void test_that_function_dispose_free_te_array(){
	ArrayUtil array = create(sizeof(int),3);
	int *createArray  = (int*)array.base;	
	assertEqual(createArray[0], 0);
	assertEqual(createArray[2], 0);
	dispose(array);
}


























