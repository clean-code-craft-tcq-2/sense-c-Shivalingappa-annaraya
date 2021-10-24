#include "stats.h"

int emailAlertCallCount = 0;
int ledAlertCallCount = 0;

struct Stats compute_statistics(const float* numberset, int setlength) {
    struct Stats s;
    int i;
    float sum = 0.0;
    s.average = 0;
    s.min = 0;
    s.max = 0;
    
     for(i=0;i<setlenght;i++)
     {
       if(numberset[i]<s.min)
           s.min =numberset[i];
         
         if(numberset[i]>s.max)
             s.max = numberset[i];
         sum=+numberset[i];
     }
     s.average = sum/setlength;
    return s;
}


