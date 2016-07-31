//
//  main.cpp
//  cpp11allocatorsample
//
//  Created by pebble8888 on 2016/07/30.
//  Copyright © 2016年 pebble8888. All rights reserved.
//

#include <vector>
//#include "ModernAllocator.h"
#include "LegacyAllocator.h"

int main(int argc, const char * argv[]) {
    //std::vector<int64_t, ModernAllocator<int64_t>> v;
    std::vector<int64_t, LegacyAllocator<int64_t>> v;
   
    v.reserve(4);
    
    return 0;
}
