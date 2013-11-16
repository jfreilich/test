#include <stdlib.h>
#include <string.h>
#include <stdio.h>

void print_subsets(int nums[], int num_nums);

int main (int argc, char** argv){
    int nums[5] = {1,2,3,4,5};
    print_subsets(nums, 5);
    return 1;
}

void print_choose_from_set(int nums[], int num_nums, int nums_to_print){
    if (nums_to_print > num_nums){
        return;
    }
    else if (nums_to_print ==1){
        printf("%d\n", nums[0]);
    }
    else{
        int i,j;
        for (i=0;i<=num_nums-nums_to_print;i++){
            for (j=i+1;j+(nums_to_print-1)<=num_nums;j++){
                printf("%d, ", nums[i]);
                print_choose_from_set(nums+j, num_nums-j, nums_to_print-1);
            }
        }
    }
}

void print_subsets(int nums[], int num_nums){
    int i;
    for (i=0; i<num_nums; i++){
        printf("%d\n", nums[i]);
    }
    for (i=2; i<num_nums;i++){
        print_choose_from_set(nums, num_nums, i);
    }
}

