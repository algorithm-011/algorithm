//
//  main.cpp
//  playground
//
//  Created by yebonkim on 2018. 3. 14..
//  Copyright © 2018년 yebonkim. All rights reserved.
//

#include <iostream>

int main(int argc, const char * argv[]) {
    int k, n;
    double result = 1;
    
    std::cin >> n;
    std::cin >> k;
    
    if(k<0 || k>n)
        result = 0;
    else {
        for(int i=n-k+1; i<=n; i++)
            result*=i;
        for(int i=k; i>0; i--)
            result/=i;
    }
    
    std::cout << result << std::endl;
    
    return 0;
}

