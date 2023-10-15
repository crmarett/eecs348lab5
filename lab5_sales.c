#include <stdio.h>
#include <stdlib.h>
#include <string.h>

float arr_avg(int i, float c[]){
    float sum=0;
    for (int j = 0;j<6;j++) sum+=c[i+j];
    return sum/6;
}


void report(float c[], char *nums[]){
    char *months[13] = {"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};
    
    printf("Monthly Sales Report for 2022:\n\n");
    printf("%-15s Sales\n\n", "Month");
    for (int i = 0;i<12;i++){
        printf("%-15s $%.2f\n", months[i], c[i]); 
    }

    int  min_index = 0, max_index = 0;
    float sum = 0, max = 0, min = 1000000;
    for (int j = 0;j<12;j++){
        if (c[j]< min){
	min_index = j;
	min = c[j];
	}
	if (c[j]> max) {
	max = c[j];
	max_index = j;
	}
	sum += c[j];
	}
    printf("\n\n");
    printf("Sales Summary:\n\n");
    printf("Minimum Sales:\t$%.2f\t(%s)\n", c[min_index],months[min_index]);
    printf("Maximum Sales:\t$%.2f\t(%s)\n",c[max_index],months[max_index]);
    printf("Average Sales:\t$%.2f\n\n\n",sum/12);

    printf("Six-Month Moving Average Report:\n");
    for (int k = 0;k<7;k++){
        printf("%-15s-  %-12s$%.2f\n\n\n",months[k], months[k+5],arr_avg(k, c));
    }

    printf("Sales Report (Highest to Lowest):\n");
    printf("\n  Month      Sales\n");
    float last_max = max, track = 0;
    int order[12];
    order[0] = max_index;
    for (int l = 0; l<11;l++){
        for (int x = 0;x<12; x++){
	    if ((c[x]<last_max) && (c[x]>track)){
		track= c[x];
	    	max_index = x;
	    }
	    }
	last_max = track;
	track = 0;
	order[l+1] = max_index;
    }
    for (int i = 0;i<12;i++) printf("%-12s$%.2f\n",months[order[i]],c[order[i]]);
}


int main(int argc, char* argv[]){
    FILE *fp;
    char buf[255];
    fp = fopen("sales.txt", "r");
    float c[12];
    int i = 0;
    char *nums[12];

    for (i = 0;i<12;i++){
	fgets(buf, 255, (FILE*) fp);
	nums[i] = buf;
	c[i] = atof(buf);
	}
    fclose(fp);
    report(c, nums); 
    return 0;
}
