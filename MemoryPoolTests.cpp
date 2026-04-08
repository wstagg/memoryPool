#include "MemoryPool.h"
#include <gtest/gtest.h>

struct Vector_3f
{
    double x;
    double y;
    double z;
};

TEST(MemoryPoolTests, TestAllocation)
{
    MemoryPool<int, 5> memoryPool;

    auto a = memoryPool.allocate(1);
    EXPECT_NE(a, nullptr);
    EXPECT_EQ(*a, 1);
    
    auto b = memoryPool.allocate(2);
    EXPECT_NE(b, nullptr);
    EXPECT_EQ(*b, 2);

    auto c = memoryPool.allocate(3);
    EXPECT_NE(c, nullptr);
    EXPECT_EQ(*c, 3);
    
    auto d = memoryPool.allocate(4);
    EXPECT_NE(d, nullptr);
    EXPECT_EQ(*d, 4);
    
    auto e = memoryPool.allocate(5);
    EXPECT_NE(e, nullptr);
    EXPECT_EQ(*e, 5);
}

TEST(MemoryPoolTests, TestAllocatingOverCapicity)
{
    MemoryPool<Vector_3f, 1> memoryPool;

    auto a = memoryPool.allocate({1.0, 2.0, 3.0});
    EXPECT_EQ(a->x, 1.0);
    EXPECT_EQ(a->y, 2.0);
    EXPECT_EQ(a->z, 3.0);
    EXPECT_NE(a, nullptr);

    auto b = memoryPool.allocate({1.0, 2.0, 3.0});
    EXPECT_EQ(b, nullptr);
}

TEST(MemoryPoolTests, TestDeallocating)
{
    MemoryPool<Vector_3f, 1> memoryPool;

    auto a = memoryPool.allocate({1.0, 2.0, 3.0});
    EXPECT_EQ(a->x, 1.0);
    EXPECT_EQ(a->y, 2.0);
    EXPECT_EQ(a->z, 3.0);
    
    memoryPool.deallocate(a);
    
    auto b = memoryPool.allocate({4.0, 5.0, 6.0});

    // pointers should match as now using same memory address as deallocated
    EXPECT_EQ(a, b);

    EXPECT_EQ(b->x, 4.0);
    EXPECT_EQ(b->y, 5.0);
    EXPECT_EQ(b->z, 6.0);   
}
