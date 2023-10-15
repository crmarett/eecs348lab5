#include <stdio.h>



//Globals
const int scores[] = {8,7,6,3,2};

void make_limits(int score, int *limits){
	for (int i = 0; i<5; i++){
		limits[i] = score/scores[i]+1;
	}	
}
int main(int argc, char* argv[]){
    
    int score;
    while (1){
	printf("Enter the NFL score: ");
	scanf("%d", &score);
	if (score <= 1) break;
	int limits[5];
	make_limits(score, limits);
	int i = 0, j= 0, k = 0, l = 0, m = 0, temp = 0;
	for (i=0;i <limits[0];i++){
		temp = scores[0]*i;
		if (temp>score) {
			break;
		}
		if (temp == score){
		    printf("%d TD + 2pt, %d TD + FG, %d TD, %d 3pt FG, %d Safety\n", i, 0, 0, 0, 0);
		    break;
		}
		for (j=0; j<limits[1]; j++ ){
			temp += scores[1]*j;
		        if (temp>score) {
				break;
			}
		        if (temp == score){ 
			    printf("%d TD + 2pt, %d TD + FG, %d TD, %d 3pt FG, %d Safety\n", i, j, 0, 0, 0);
			    break;
		        }

			for (k=0;k<limits[2]; k++){
				temp += scores[2]*k;
		        	if (temp>score) {
					temp -= scores[2]*k+scores[1]*j;
					break;
				}
		        	if (temp == score){
		            	    printf("%d TD + 2pt, %d TD + FG, %d TD, %d 3pt FG, %d Safety\n", i, j, k, 0, 0);
			    	    temp -= scores[2]*k+scores[1]*j;
				    break;
		          	}
				for (l=0;l<limits[3];l++){
					temp += scores[3]*l;
		        		if (temp>score) {
						temp -= scores[3]*l+scores[2]*k;
						break;
					}
		        		if (temp == score){
		            		    printf("%d TD + 2pt, %d TD + FG, %d TD, %d 3pt FG, %d Safety\n", i, j, k, l, 0);
					    temp -= scores[3]*l+scores[2]*k;
			    		    break;
		        		}
					for(m=0;m<limits[4];m++){
						temp += scores[4];
		        			if (temp>score) {
							temp -= scores[4]*(m+1)+scores[3]*l;
							break;
						}
		        			if (temp == score){
						    printf("%d TD + 2pt, %d TD + FG, %d TD, %d 3pt FG, %d Safety\n", i, j, k, l, (m+1));
			    			    temp -= scores[4]*(m+1)+scores[3]*l;
						    break;
		        			}
					}
				}
			}
		}	
	} 
    }
    }
