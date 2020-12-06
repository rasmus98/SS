#include <iostream>

int main(){
    constexpr int n = 1000000;
    double rate = 0.01, specificity = 0.993, sensitivity = 0.998;
    int classes[4] = {0}; // [true negative, false positive, false negative, true positive]
    for (int i = 0; i < n; i++){
        bool allergic = rand() / double(RAND_MAX) < rate;
        bool positive = rand() / double(RAND_MAX) < (allergic ? sensitivity : 1-specificity);
        ++classes[positive+2*allergic];
    }
    
    std::cout << "3a:\n"
              << "P(T=1)=" << ((double)classes[1] + classes[3])/n << '\n'
              << "P(T=-1)=" << ((double)classes[0] + classes[2])/n << '\n'
              << "3b:\n" 
              << "P(A=0|T=1)=" << ((double)classes[0])/(classes[0] + classes[2]) << '\n'
              << "3c:\n" 
              << "P(A=1|T=1)=" << ((double)classes[3])/(classes[3] + classes[1]) << '\n';
}
https://git.overleaf.com/project/5fc796aed75992004fb13b53