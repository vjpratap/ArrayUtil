#include "expr_assert.h"
#include <stdlib.h>
#include "arrayUtil.h"


void test_findIndex_returns_1_if_the_search_char_is_found_on_1st_location (){
	int x = 'a';
	char array[] = "car";
	ArrayUtil util = create(sizeof(char),3);
	util.base = (void*)array;
	assertEqual(findIndex(util,&x),1);
}

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

void test_resize_add_0_to_the_new_places_created_in_integer_array(){
	int array[] = {1,2,3}, arr[] = {1,2,3,0,0};
	ArrayUtil array2, util1 = {array, sizeof(int), 3};
	ArrayUtil expected = {arr, sizeof(int) ,5};
	array2 =  resize(util1,5);
	assert(areEqual(array2 , expected));
}

void test_resize_add_0_to_the_new_places_created_in_float_array(){
	float array[] = {1.1,2.2,3.2}, arr[] = {1.1,2.2,3.2,0.0,0.0};
	ArrayUtil array2, util1 = {array, sizeof(float), 3};
	ArrayUtil expected = {arr, sizeof(float) ,5};
	array2 =  resize(util1,5);
	assert(areEqual(array2 , expected));
}
void test_resize_add_0_to_the_new_places_created_in_char_array(){
	char *array= "abc";
	char arr[] = {'a','b','c',0,0};
	ArrayUtil array2, util1 = {array, sizeof(char), 3};
	ArrayUtil expected = {arr, sizeof(char) ,5};
	array2 =  resize(util1,5);
	assert(areEqual(array2 , expected));
}
void test_resize_add_0_to_the_new_places_created_in_double_array(){
	double array[] = {1,2,3}, arr[] = {1,2,3,0.0,0.0};
	ArrayUtil array2, util1 = {array, sizeof(double), 3};
	ArrayUtil expected = {arr, sizeof(double) ,5};
	array2 =  resize(util1,5);
	assert(areEqual(array2 , expected));
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

int isDivisible(void* hint, void* item){
	int* _hint = (int*)hint;
	int* _item = (int*)item;
	return (*_item % *_hint) == 0 ? 1 : 0;
}

void test_to_get_first_element_from_the_array_which_is_divisible_by_3(){
	int array[6] = {10,2,3,4,5,6};
	int x = 5;
	int *result;
	ArrayUtil util = create(sizeof(int),6);
	util.base = array;
	result = (int*)findFirst(util,&isDivisible,&x);
	assertEqual(*result,10);
}

int isCapital(void *hint, void *item) {
    return((*(char *)item >=65) && (*(char *)item <= 91));
}

int isEven(void *hint, void *item) {
    return(*(int *)item%2==0);
}

int isGreaterThan5(void *hint, void *item) {
    return(*(float *)item > 5);
}

void test_areEqual_returns_0_if_typeSize_of_two_arrays_are_not_equal(){
    int array1[] = {1,2,3,4};
    char array2[] = {'m','a','h','e'};
    ArrayUtil util1 = {array1,sizeof(int),4};
    ArrayUtil util2 = {array2,sizeof(char),4};
    assertEqual(areEqual(util1, util2), 0);
}

void test_findFirst_returns_the_address_of_the_first_element_in_the_array_that_is_capital(){
    char array1[] = {'k','M','k'};
    ArrayUtil util1 = {array1,sizeof(char),3};
    assertEqual(*(char *)(findFirst(util1,&isCapital,0)), 'M');
}

void test_findFirst_returns_the_address_of_the_first_element_in_the_array_that_is_even(){
    int array1[] = {1,2,3,4,5};
    ArrayUtil util1 = {array1,sizeof(int),5};
    assertEqual(*(int *)(findFirst(util1,&isEven, 0)), 2);
}

void test_findFirst_returns_the_adsdress_of_first_element_in_the_array_greater_than_5() {
    float array1[] = {1.1,6.6,5.5,8.8,2.2};
    ArrayUtil util1 ={array1, sizeof(float),5};
    assertEqual(*(float *)(findFirst(util1,&isGreaterThan5,0)), (float)6.6);
}

void test_findIndex_returns_index_of_the_String_element_where_it_presents(){
    basePtr array1[] = {"Mahesh","Kumar","Kolla"};
    basePtr element = "Kumar";
    ArrayUtil util1 = {array1,sizeof(basePtr),3};
    assertEqual(findIndex(util1,&element), 1);
}

void test_findIndex_returns_index_of_the_char_element_where_it_presents(){
    char array1[] = {'m','a','h','e','s','h'};
    char element = 's';
    ArrayUtil util1 = {array1,sizeof(char),6};
    assertEqual(findIndex(util1,&element), 4);
}

void test_findIndex_returns_index_of_the_float_element_where_it_presents(){
    float array1[] = {1.1,2.2,3.3,4.75};
    float element = 4.75;
    ArrayUtil util1 = {array1,sizeof(float),4};
    assertEqual(findIndex(util1,&element), 3);
}

void test_findIndex_returns_index_of_the_integer_element_where_it_presents(){
    int array1[] = {1,2,3,4,5};
    int element = 2;
    ArrayUtil util1 = {array1,sizeof(int),5};
    assertEqual(findIndex(util1,&element), 1);
}

void test_resize_returns_new_Array_util_with_String_array_of_new_length_by_putting_0s_in_new_created_spaces(){
    basePtr array1[] = {"Mahesh","Kumar"}, array2[] = {"Mahesh","Kumar",0,0,0};
    ArrayUtil util1 = {array1,sizeof(char *),2};
    ArrayUtil util2 = {array2,sizeof(char *),5};
    assertEqual(areEqual(resize(util1, 5), util2), 1);    
}
void test_resize_returns_new_Array_util_with_String_array_of_new_length_by_removing_extra_values(){
    basePtr array1[] = {"Mahesh","Kumar","Kolla"}, array2[] = {"Mahesh","Kumar"};
    ArrayUtil util1 = {array1,sizeof(char *),3};
    ArrayUtil util2 = {array2,sizeof(char *),2};
    assertEqual(areEqual(resize(util1, 2), util2), 1);    
}

// #define basePtr char*        use it

//*********parmatma plz fix all filter testl
void test_ArrayUtil_a_and_ArrayUtil_b_are_will_be_equal_by_each_element_typeof_double(){
	double a [] = {2.34};
	double b [] = {2.34};
	ArrayUtil array1 = {a, sizeof(double), 1};
	ArrayUtil array2 = {b, sizeof(double), 1};

	assert(areEqual(array1,array2));
};

void test_ArrayUtil_a_and_ArrayUtil_b_are_will_be_equal_by_each_element_typeof_string(){
	basePtr a [] = {"hello"};
	basePtr b [] = {"hello"};
	ArrayUtil array1 = {a, sizeof(basePtr), 1};
	ArrayUtil array2 = {b, sizeof(basePtr), 1};

	assert(areEqual(array1,array2));
};

void test_ArrayUtil_a_and_ArrayUtil_b_are_will_not_be_equal_String(){
	basePtr a [] = {"hallo"};
	basePtr b [] = {"hello"};
	ArrayUtil array1 = {a, sizeof(basePtr), 1};
	ArrayUtil array2 = {b, sizeof(basePtr), 1};

	assertEqual(areEqual(array1,array2),0);
};

void increment(void* hint, void* sourceItem, void* destinationItem){
	int *hintPtr = (int*)hint;
	int *numberPtr = (int*)sourceItem;
	int *resultPtr = (int*)destinationItem;
	*resultPtr = *numberPtr + *hintPtr;
}

void toChar(void* hint, void* sourceItem, void* destinationItem){
	int *numberPtr = (int*)sourceItem;
	int *charPtr = (int*)destinationItem;
	*charPtr = *numberPtr;
}


void test_create_should_set_the_length_and_typeSize_fields_of_array_to_the_values_passed_to_create_function(){
	ArrayUtil a = create(1,3);
	assert(a.length == 3);
	assert(a.typeSize == 1);
	dispose(a);
}

test_resize_should_grow_length_of_array_and_set_them_to_zero_when_new_size_is_more(){
	ArrayUtil a = create(4,2);
	int i;
	a = resize(a,5);
	assert(a.length == 5);
	for (i = 0; i < 20; ++i)
	{
		assert(((char*)a.base)[i] == 0);
	}
	dispose(a);
}

void test_resize_should_not_change_length_of_array_when_new_size_is_same_as_old_size(){
	ArrayUtil a = create(1,5);
	int i;
	a = resize(a,5);
	assert(a.length == 5);
	dispose(a);
}

// Start of JP

ArrayUtil util,expectedUtil;

void test_array_util_areEqual_returns_0_if_both_array_are_not_equal_in_length_and_elements(){
	int a[]={0,3,8,5,2,3,4,5}, b[]={1,5,2,3,7};
	ArrayUtil a_array = {a,sizeof(int),8};
	ArrayUtil b_array = {b,sizeof(int),5};
	assertEqual(areEqual(a_array, b_array),0);
}
void test_create_allocates_space_for_DOUBLE_array_and_assigns_zero_to_all_bytes(){
	double doubleArray[] = {0,0,0,0};
	expectedUtil = (ArrayUtil){doubleArray,sizeof(double),4};
	util = create(sizeof(double),4);
	assertEqual(areEqual(expectedUtil,util),1);
	dispose(util);
}
void test_create_allocates_space_for_INT_array_and_assigns_zero_to_all_bytes(){
	int intArray[] = {0,0,0,0};
	expectedUtil = (ArrayUtil){intArray,sizeof(int),4};
	util = create(sizeof(int),4);
	assertEqual(areEqual(expectedUtil,util),1);
	dispose(util);
}

void test_resize_returns_CHAR_array_within_structure_with_new_allocated_space(){
	ArrayUtil resizedArray;
	util = (ArrayUtil){(char []){'a','e','i','o'},sizeof(char),4};
	resizedArray = resize(util,6);
	expectedUtil = (ArrayUtil){(char []){'a','e','i','o',0,0},sizeof(char),6};
	assertEqual(areEqual(expectedUtil, resizedArray),1);
	dispose(resizedArray);
}
void test_resize_returns_CHAR_array_within_structure_with_new_allocated_space_less_than_previous(){
	ArrayUtil resizedArray;
	util = (ArrayUtil){(char []){'a','e','i','o','u'},sizeof(char),5};
	resizedArray = resize(util,2);
	expectedUtil = (ArrayUtil){(char []){'a','e'},sizeof(char),2};
	assertEqual(areEqual(expectedUtil, resizedArray),1);
	dispose(resizedArray);
}
void test_resize_returns_DOUBLE_array_within_structure_with_new_allocated_space(){
	ArrayUtil resizedArray;
	util = (ArrayUtil){(double []){1.0,2.11111,3.123,4.89},sizeof(double),4};
	resizedArray = resize(util,6);
	expectedUtil = (ArrayUtil){(double []){1.0,2.11111,3.123,4.89,0,0},sizeof(double),6};
	assertEqual(areEqual(expectedUtil, resizedArray),1);
	dispose(resizedArray);
}
void test_resize_returns_DOUBLE_array_within_structure_with_new_allocated_space_less_than_previous(){
	ArrayUtil resizedArray;
	util = (ArrayUtil){(double []){1.0,2.11111,3.123,4.89},sizeof(double),4};
	resizedArray = resize(util,2);
	expectedUtil = (ArrayUtil){(double []){1.0,2.11111},sizeof(double),2};
	assertEqual(areEqual(expectedUtil, resizedArray),1);
	dispose(resizedArray);
}
void test_resize_returns_FLOAT_array_within_structure_with_new_allocated_space(){
	ArrayUtil resizedArray;
	util = (ArrayUtil){(float []){1.0,2.11111,3.123,4.89},sizeof(float),4};
	resizedArray = resize(util,6);
	expectedUtil = (ArrayUtil){(float []){1.0,2.11111,3.123,4.89,0,0},sizeof(float),6};
	assertEqual(areEqual(expectedUtil, resizedArray),1);
	dispose(resizedArray);
}

void test_resize_returns_INT_array_within_structure_with_new_allocated_space(){
	ArrayUtil resizedArray;
	util = (ArrayUtil){(int []){1,2,3,4},sizeof(int),4};
	resizedArray = resize(util,6);
	expectedUtil = (ArrayUtil){(int []){1,2,3,4,0,0},sizeof(int),6}; 
	assertEqual(areEqual(expectedUtil, resizedArray),1);
	dispose(resizedArray);
}

// End of JP

// Start of Vikas Pal

int isLessThanTheHints(void* hint,void* element){
    return (*(float*)element) < (*(float*)hint);

}
void test_findIndex_retruns_the_index_of_an_element_in_an_string_array(){
    char array[]= {"heloo"};
    char element ='o';
    ArrayUtil util = {array,sizeof(char),4};
    assertEqual(findIndex(util,&element),3);
};
void test_for_the_ArrayUtil_for_charecter_and_int_are_not_equal(){
    char first_array[]={'c','d','e','f'};
    int second_array[]={2,5,8,4};
    ArrayUtil array1 = {first_array,sizeof(char),4};
    ArrayUtil array2 = {second_array,sizeof(int),4};
	assertEqual(areEqual(array1, array2),0);
};
void test_resize_an_existing_array_to_resize_decrease_its_length(){
    int *resArray;
    ArrayUtil array,resizeArray;
    array = create(sizeof(int),5);
    ((int*)array.base)[0]=90;
    ((int*)array.base)[1]=40;
    ((int*)array.base)[2]=550;
    ((int*)array.base)[3]=550;
    ((int*)array.base)[4]=40;
    resizeArray=resize(array,4);
    resArray = resizeArray.base;
    assertEqual(resArray[2],550);
    assertEqual(areEqual(resizeArray,array),0);
};


void test_resize_an_existing_array_to_resize_increase_its_length(){
    ArrayUtil array = create(sizeof(int),3),resultArray;
    ((int*)array.base)[0]=90;
    ((int*)array.base)[1]=40;
    ((int*)array.base)[2]=550;
    resultArray = resize(array,5);
    assertEqual(((int *)resultArray.base)[0],90);
    assertEqual(((int *)resultArray.base)[1],40);
    assertEqual(((int *)resultArray.base)[2],550);
    assertEqual(((int *)resultArray.base)[3],0);
    assertEqual(((int *)resultArray.base)[4],0);
};

void test_for_findLast_gives_the_last_element_of_less_than_float_value_an_array(){
    float hint = 6.3;
    float *result;
    MatchFunc *match = &isLessThanTheHints;
    ArrayUtil util = {(float[]){2.5,4.5,6.3,4.5,6.0},sizeof(float),5};
    result = findFirst(util,match,&hint);
    assert(*result == 2.5);
};

// End of Vikas Pal

// Start of Krati Jain

#define INT_SIZE sizeof(int)
#define CHAR_SIZE sizeof(char)
#define FLOAT_SIZE sizeof(float)
#define DOUBLE_SIZE sizeof(double)

int isGreaterThanHint (void* hint, void* element) {
	return (*((float*)element) > *((float*)hint)) ? 1 : 0;
}


void test_Create_creates_new_array_of_float_containing_all_elements_0 (){
	ArrayUtil expectedUtil = {(float[]){0,0},FLOAT_SIZE,2};
	ArrayUtil newUtil = create(FLOAT_SIZE, 2);
	assertEqual(areEqual(expectedUtil,newUtil ), 1);
	dispose(newUtil);
}
void test_Create_creates_new_charArray_containing_all_elements_0_and_gives_0_for_different_lengths (){
	ArrayUtil expectedUtil = {(char[]){0,0,0},CHAR_SIZE,3};
	ArrayUtil newUtil =create(CHAR_SIZE, 2);
	assertEqual(areEqual(expectedUtil, newUtil), 0);
	dispose(newUtil);
}
void test_Create_creates_new_doubleArray_containing_all_elements_0_and_gives_0_for_different_lengths (){
	ArrayUtil expectedUtil = {(double[]){0,0},DOUBLE_SIZE,2};
	ArrayUtil newUtil =create(DOUBLE_SIZE, 3);
	assertEqual(areEqual(expectedUtil, newUtil), 0);
	dispose(newUtil);
}
void test_Create_creates_new_intArray_containing_all_elements_0_and_gives_0_for_different_lengths (){
	ArrayUtil expectedUtil = {(int[]){0,0,0},INT_SIZE,3};
	ArrayUtil newUtil =create(INT_SIZE, 2);
	assertEqual(areEqual(expectedUtil, newUtil), 0);
	dispose(newUtil);
}

void test_Create_creates_new_floatArray_containing_all_elements_0_and_gives_0_for_different_lengths (){
	ArrayUtil util = {(float[]){0,0},FLOAT_SIZE,2};
	ArrayUtil newUtil =create(FLOAT_SIZE, 3);
	assertEqual(areEqual(util, newUtil), 0);
	dispose(newUtil);
}

void test_findFirst_gives_occurence_of_first_element_in_floatArray_greaterThan5 (){
	float hint = 5.1;
	float *result;
	MatchFunc *match = &isGreaterThanHint;
	ArrayUtil util = {(float[]){3.1,2.4,1.6,3.7,8.3,0.1},FLOAT_SIZE,6};
	result = (float*)findFirst(util,match,(void*)&hint);
	assertEqual(*result,(float)8.3);
}
void test_findIndex_returns_4_for_float_array_if_search_element_is_at_4th_location (){
	float element = 7.8;
	ArrayUtil util = {(float[]){4.2,2.9,1.4,3.1,7.8,8.7},FLOAT_SIZE,6};
	assertEqual(findIndex(util, &element),4);
}

//________________________________________________Vishnu Mishra(Start)__________________________________

void test_findIndex_will_return_the_minus_1_if_array_element_is_not_present(){
	int array[]={1,2,3,4,5};
	int x=7;
	ArrayUtil arr={array,sizeof(int),5};
	assertEqual(findIndex(arr,&x),-1);
}

void test_resize_should_contain_the_initial_array_element(){
	int src[]={5,3},i;
	ArrayUtil util={src,sizeof(int),4},array;
	int* base;
	array = resize(util,15);
	base = (int *)(array.base);
	assertEqual(base[0], 5);
	assertEqual(base[1], 3);
	assertEqual(base[14], 0);

	free(array.base);
};
//___________________________________________VishnuMishra(end)_________________________________________











