#include "stats.h"
#include "math.h"
#include "alerters.h"

int emailAlertCallCount = 0;
int ledAlertCallCount = 0;

/*function to calulate min,max,avg*/
struct Stats compute_statistics(const float* numberset, int setlength) {
    struct Stats s;
    int i;
    float sum = 0.0;
    s.average = 0.0;
    s.min = 0.0;
    s.max = 0.0;
    
     for(i=0;i<setlength;i++)
     {
       if(numberset[i]<s.min)
           s.min =numberset[i];
         
         if(numberset[i]>s.max)
             s.max = numberset[i];
         sum=+numberset[i];
     }
     s.average = sum/(float)setlength;
    return s;
}

/*function to alert if value is above threshold*/
void check_and_alert(float maxThreshold, alerter_funcptr alerters[], struct Stats computedStats)
{
	if(computedStats.max > maxThreshold)
	{
		alerters[0]();
		alerters[1]();
	}
}


