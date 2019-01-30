#include "pch.h"

TEST(SimpleContainer, MemoryAllocatorEmpty) {
	TSimpleContainer<int> container;
	EXPECT_EQ(0, container.GetCapacity());
	EXPECT_EQ(0, container.GetSize());
}

TEST(SimpleContainer, MemoryAllocatorSingleElement) {
	TSimpleContainer<int> container;
	container.Insert(1);
	EXPECT_EQ(4, container.GetCapacity());
	EXPECT_EQ(1, container.GetSize());
}

TEST(SimpleContainer, MemoryAllocatorMultipleElements) {
	TSimpleContainer<int> container;
	container.Insert({ 1, 8, 9, 75, 14, 85, 26, 84, 963, 14 });
	EXPECT_EQ(16, container.GetCapacity());
	EXPECT_EQ(10, container.GetSize());
}

TEST(SimpleContainer, ContainerContents) {
	TSimpleContainer<int> container;
	int arr[] = { 1, 8, 9, 75, 14, 85 };
	container.Insert({ 1, 8, 9, 75, 14, 85 });
	
	int cnt = 0;
	for (auto& value : container)
	{
		EXPECT_EQ(arr[cnt++], value);
	}
}