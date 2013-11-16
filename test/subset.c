
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
void print_subsets(int nums[], int num_nums);

int main(int argc, char** argv){
	int nums[5] = {1,2,3,4,5};
	print_subsets(nums, 5);
}

void print_subsets(int nums[], int num_nums){
	int factorials[num_nums+1];
	factorials[0]=1;
	int i,j,k,p,current_num, previous_combinations;
	for (i=1;i<=num_nums;i++){
		factorials[i] = factorials[i-1]*i;
	}
	int divisor1 = num_nums/2;
	int divisor2 = num_nums-divisor1;
	int max_subsets = factorials[num_nums] / (factorials[divisor2]*factorials[divisor1]);
	int subsets[num_nums+1][max_subsets*divisor2*20];
	for (i=0;i<num_nums;i++){
		subsets[1][i] = nums[i];
	}
	for(i=2;i<=num_nums;i++){
		p = i-1;
		previous_combinations = factorials[num_nums] / (factorials[p]*factorials[num_nums-p]);
		int current_subset_index = 0;
		for(j=0;j<num_nums;j++){
			current_num = nums[j];
			for (k=0;k<previous_combinations;k++){
				int c;
				for (c=p*k;c<p*k+p;c++){
					if (subsets[p][c] == current_num){
						//do not use subset if it contains current num
						break;
					}
				}
				if (c==(p*k+p)){
					subsets[i][current_subset_index] = current_num;
					current_subset_index++;
					for (c=p*k;c<p*k+p;c++){
						subsets[i][current_subset_index] = subsets[p][c];
						current_subset_index++;
					}
				}
			}
		}
	}
	for (i=1;i<=num_nums;i++){
		int current_subset_index = 0;
		int combinations = factorials[num_nums] / (factorials[i]*factorials[num_nums-i]);
		for (j=0;j<combinations;j++){
			for (k=0;k<i;k++){
				printf("%d, ",subsets[i][j*i+k]);
			}
			printf("\n");
		}
	}
}