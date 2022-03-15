#include "pch.h"

using namespace std;

template <typename T>
T* bubbleSort(T list[], long int size);
template <typename T>
T* insertionSort(T list[], long int size);
template <typename T>
T* selectionSort(T list[], long int size);

TEST(testBubbleSort, test1)
{
	int testArray[10] = { 42, 20, 75, 84, 25, 2, 78, 5, 43, 23 };
	int expected[10] = { 2, 5, 20, 23, 25, 42, 43, 75, 78, 84 };
	int *sorted = bubbleSort(testArray, 10);
	ASSERT_LE(sorted[0], sorted[9]);
	for (int i = 0; i < 10; ++i) {
		ASSERT_EQ(sorted[i], expected[i]) << "testArray and expected differ at index " << i;
	}
}
TEST(testBubbleSort, test2)
{
	int testArray[20] = { 20, 19, 18, 17, 16, 15, 14, 13, 12, 11, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1 };
	int expected[20] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20 };
	int* sorted = bubbleSort(testArray, 20);
	ASSERT_LE(sorted[0], sorted[19]);
	for (int i = 0; i < 20; ++i) {
		ASSERT_EQ(sorted[i], expected[i]) << "testArray and expected differ at index " << i;
	}
}
TEST(testBubbleSort, test3)
{
	char testArray[5] = { 'b', 'c', 'e', 'a', 'd' };
	char expected[5] = { 'a', 'b', 'c', 'd', 'e' };
	char* sorted = bubbleSort(testArray, 5);
	ASSERT_LE(sorted[0], sorted[4]);
	for (int i = 0; i < 5; ++i) {
		ASSERT_EQ(sorted[i], expected[i]) << "testArray and expected differ at index " << i;
	}
}
TEST(testInsertionSort, test1)
{
	int testArray[10] = { 42, 20, 75, 84, 25, 2, 78, 5, 43, 23 };
	int expected[10] = { 2, 5, 20, 23, 25, 42, 43, 75, 78, 84 };
	int* sorted = insertionSort(testArray, 10);
	ASSERT_LE(sorted[0], sorted[9]);
	for (int i = 0; i < 10; ++i) {
		ASSERT_EQ(sorted[i], expected[i]) << "testArray and expected differ at index " << i;
	}
}
TEST(testInsertionSort, test2)
{
	int testArray[20] = { 20, 19, 18, 17, 16, 15, 14, 13, 12, 11, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1 };
	int expected[20] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20 };
	int* sorted = insertionSort(testArray, 20);
	ASSERT_LE(sorted[0], sorted[19]);
	for (int i = 0; i < 20; ++i) {
		ASSERT_EQ(sorted[i], expected[i]) << "testArray and expected differ at index " << i;
	}
}
TEST(testInsertionSort, test3)
{
	char testArray[5] = { 'b', 'c', 'e', 'a', 'd' };
	char expected[5] = { 'a', 'b', 'c', 'd', 'e' };
	char* sorted = insertionSort(testArray, 5);
	ASSERT_LE(sorted[0], sorted[4]);
	for (int i = 0; i < 5; ++i) {
		ASSERT_EQ(sorted[i], expected[i]) << "testArray and expected differ at index " << i;
	}
}
TEST(testSelectionSort, test1)
{
	int testArray[20] = { 20, 19, 18, 17, 16, 15, 14, 13, 12, 11, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1 };
	int expected[20] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20 };
	int* sorted = selectionSort(testArray, 20);
	ASSERT_LE(sorted[0], sorted[19]);
	for (int i = 0; i < 20; ++i) {
		ASSERT_EQ(sorted[i], expected[i]) << "testArray and expected differ at index " << i;
	}
}
TEST(testSelectionSort, test2)
{
	char testArray[5] = { 'b', 'c', 'e', 'a', 'd' };
	char expected[5] = { 'a', 'b', 'c', 'd', 'e' };
	char* sorted = selectionSort(testArray, 5);
	ASSERT_LE(sorted[0], sorted[4]);
	for (int i = 0; i < 5; ++i) {
		ASSERT_EQ(sorted[i], expected[i]) << "testArray and expected differ at index " << i;
	}
}

template <typename T>
T* bubbleSort(T list[], long int size)
{
	bool swapped = true;
	long int i;
	int tmp;
	while (swapped)
	{
		swapped = false;
		//Check all numbers except the last one
		for (i = 0; i < size - 1; i++)
		{
			//If the current number is greater than the next one, swap them
			if (list[i] > list[i + 1])
			{
				tmp = list[i];
				list[i] = list[i + 1];
				list[i + 1] = tmp;
				swapped = true;
			}
		}
	}
	return list;
}

template <typename T>
T* insertionSort(T list[], long int size)
{
	long int i, j;
	T holder;
	//Check all numbers except the first one
	for (i = 1; i < size; i++)
	{
		holder = list[i];
		j = i - 1;
		//Go back in the list until you find a number less than the holder
		while (j >= 0 && list[j] > holder)
		{
			list[j + 1] = list[j];
			j--;
		}
		//Place the holder in its place
		list[j + 1] = holder;
	}
	return list;
}

template <typename T>
T* selectionSort(T list[], long int size)
{
	return list;
}

int main(int argc, char **argv)
{
	testing::InitGoogleTest(&argc, argv);

	return RUN_ALL_TESTS();
}