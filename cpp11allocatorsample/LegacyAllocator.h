//
//  LegacyAllocator.h
//
//  Created by pebble8888 on 2016/07/31.
//  Copyright © 2016年 pebble8888. All rights reserved.
//

#ifndef LegacyAllocator_h
#define LegacyAllocator_h

#include <iostream>

template <class T>
class LegacyAllocator
{
public:
    typedef T value_type;
    typedef T* pointer;
    typedef const T* const_pointer;
    typedef T& reference;
    typedef const T& const_reference;
    typedef std::size_t size_type;
    typedef std::ptrdiff_t difference_type;
    
    template <class U>
    struct rebind
    {
        typedef LegacyAllocator<U> other;
    };
    
    LegacyAllocator() throw()
    {
    }
    LegacyAllocator(const LegacyAllocator&) throw()
    {
    }
    template <class U> LegacyAllocator(const LegacyAllocator<U>&) throw()
    {
    }
    ~LegacyAllocator() throw()
    {
    }
    
    pointer allocate(size_type num, const void* hint = 0)
    {
        std::cerr << "allocate " << num << " element(s)"
        << " of size " << sizeof(T) << std::endl;
        pointer ret = (pointer)(::operator new(num * sizeof(T)));
        std::cerr << " allocated at: " << (void*)ret << std::endl;
        return ret;
    }
    void construct(pointer p, const T& value)
    {
        new( (void*)p ) T(value);
    }
    
    void deallocate(pointer p, size_type num)
    {
        std::cerr << "deallocate " << num << " element(s)"
                  << " of size " << sizeof(T)
                  << " at: " << (void*)p << std::endl;
        ::operator delete( (void*)p );
    }
    void destroy(pointer p) {
        p->~T();
    }
    
    pointer address(reference value) const {
        return &value;
    }
    const_pointer address(const_reference value) const {
        return &value;
    }
    
    size_type max_size() const throw() {
        return std::numeric_limits<size_t>::max() / sizeof(T);
    }
};

template <class T1, class T2>
bool operator==(const LegacyAllocator<T1>&, const LegacyAllocator<T2>&) throw() { return true; }

template <class T1, class T2>
bool operator!=(const LegacyAllocator<T1>&, const LegacyAllocator<T2>&) throw() { return false; }

#endif /* LegacyAllocator_h */
