#pragma once

#include <memory>

template<class T>
class alloc_vec
{
private:
    int maxn=100,sizenow=0;
    std::allocator<T> alloc;
    T * a = alloc.allocate(maxn);
    void update()
    {
        maxn *= 2;
        T * b = alloc.allocate(maxn);
        for (int i=0;i<sizenow;i++)
        {
            alloc.construct(b+i,*(a+i));
        }
        a = b;
    }
public:
    void push_back(const T & item0)
    {
        if (sizenow==maxn-1)  update();
        alloc.construct(a+sizenow,item0);
        ++ sizenow;
    }
    T operator [] (const int & n)
    {
        return *(a+n);
    }
};