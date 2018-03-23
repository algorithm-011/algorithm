//
//  main.cpp
//  playground
//
//  Created by yebonkim on 2018. 3. 14..
//  Copyright © 2018년 yebonkim. All rights reserved.
//

#include <iostream>

int main(int argc, const char * argv[]) {
    int n;
    int result = 1;     //1은 항상 포함
    
    std::cin >> n;
    
    for(int i=2; i<n; i++) {
        for(int j=2; j<=i; j++) {
            if(n%j==0 && i%j==0)
                break;
            
            if(j==i)
                result++;
        }
    }
    
    std::cout << result << std::endl;
    
    return 0;
}

