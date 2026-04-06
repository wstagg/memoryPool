#include <print>
#include "MemoryPool.h"

struct Vector_3f
{
    double x;
    double y;
    double z;
};

int main()
{
    MemoryPool<Vector_3f, 5> allocater;
    auto a = allocater.allocate({1, 2, 3});
    auto b = allocater.allocate({2, 2, 3});
    auto c = allocater.allocate({3, 2, 3});
    auto d = allocater.allocate({4, 2, 3});
    auto e = allocater.allocate({5, 2, 3});


    std::println("data {} addr {}", a->x, static_cast<void*>(a));
    std::println("data {} addr {}", b->x, static_cast<void*>(b));
    std::println("data {} addr {}", c->x, static_cast<void*>(c));
    std::println("data {} addr {}", d->x, static_cast<void*>(d));
    std::println("data {} addr {}", e->x, static_cast<void*>(e));

    std::println("deallocating a");
    allocater.deallocate(a);
    auto f = allocater.allocate({6, 2, 3});
    std::println("data {} addr {}", f->x, static_cast<void*>(f));

    std::println("deallocating b");
    allocater.deallocate(b);
    auto g = allocater.allocate({7, 2, 3});
    std::println("data {} addr {}", g->x, static_cast<void*>(g));

}