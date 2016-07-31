//
//  ModernAllocator.h
//
//  Created by pebble8888 on 2016/07/31.
//  Copyright © 2016年 pebble8888. All rights reserved.
//

#ifndef ModernAllocator_h
#define ModernAllocator_h

#include <iostream>

template <class T>
struct ModernAllocator {
    using value_type = T;
    
    ModernAllocator() {}
    
    template <class U>
    ModernAllocator(const ModernAllocator<U>&) {}
    
    T* allocate(std::size_t n)
    {
        void* p = std::malloc(sizeof(T) * n);
        
        std::cerr << "allocate " << n << " element(s)"
        << " of size " << sizeof(T) << std::endl;
        std::cerr << " allocated at: " <<  p << std::endl;
        
        return reinterpret_cast<T*>(p);
    }
    
    void deallocate(T* p, std::size_t n)
    {
        static_cast<void>(n);
        
        std::cerr << "deallocate " << n << " element(s)"
                  << " of size " << sizeof(T)
                  << " at: " << (void*)p << std::endl;
        
        std::free(p);
    }
};

template <class T, class U>
bool operator==(const ModernAllocator<T>&, const ModernAllocator<U>&)
{ return true; }

template <class T, class U>
bool operator!=(const ModernAllocator<T>&, const ModernAllocator<U>&)
{ return false; }


#endif /* ModernAllocator_h */
