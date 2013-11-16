
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <math.h>
int f(int x);
int g(int x);

void tcp_rtt_calc(double goal_interval, double alpha, double beta, double rtt_init, double rtt_sample, double devrtt_init){
  double rtt_est = rtt_init;
  double dev_rtt = devrtt_init;
  double time_interval = rtt_est + 4.0f*dev_rtt;
  int steps = 0;
  while(time_interval>=goal_interval){
    printf("%d:\t%f:\t%f:\t%f\n", steps,rtt_est,dev_rtt, time_interval);
    rtt_est = (1.0f-alpha)*rtt_est + alpha*rtt_sample;
    dev_rtt = (1.0f-beta)*dev_rtt + beta*(fabs(rtt_est-rtt_sample));
    time_interval = rtt_est + 4.0f*dev_rtt;
    steps++;
  }
    printf("%d:\t%f:\t%f:\t%f\n", steps,dev_rtt,rtt_est, time_interval);
}

int main(int argc, char** argv){
//	printf("%d\t%d\t%d\t%d\t\n",f(2), f(4), f(8), f(16) );
  tcp_rtt_calc(5.0f, 0.125, 0.25, 5.0f, 2.0f, 10.0f);
}


int f(int x){
	if (x<1){
		return 	1;
	}
	else{
	return f(x-1) + g(x);
	}
}

int g(int x){
	if (x<2){
	return 1;
	}
	else{
	return f(x-1)+ g(x/2);
	}
}
