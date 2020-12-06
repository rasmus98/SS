#include <stdio.h>
#include <stdlib.h>

int main(){
    int n = 1000000;
    double rate = 0.01, specificity = 0.993, sensitivity = 0.998;
    int classes[4] = {0}; // [true negative, false positive, false negative, true positive]
    for (int i = 0; i < n; i++){
        char allergic = rand() / (double)RAND_MAX < rate;
        char positive = rand() / (double)RAND_MAX < (allergic ? sensitivity : 1-specificity);
        ++classes[positive+2*allergic];
    }
    
    printf("3a:\nP(T=1)=%f\nP(T=-1)=%f\n3b:\nP(A=0|T=1)=%f\n3c:\nP(A=1|T=1)=%f",
        ((double)classes[1] + classes[3])/n,
        ((double)classes[0] + classes[2])/n,
        ((double)classes[0])/(classes[0] + classes[2]),
        ((double)classes[3])/(classes[3] + classes[1])
    );
}
