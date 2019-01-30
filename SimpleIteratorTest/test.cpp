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