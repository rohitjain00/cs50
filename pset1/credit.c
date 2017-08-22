#include<stdio.h>
#include<cs50.h>
#include<math.h>


int * convertNumberIntoArray(unsigned long long number);
int getLengthOfNumber(unsigned long long number);

int main (void){

    long long number = get_long_long();

    int i;

    int arr_len = getLengthOfNumber(number);

    int* arr = convertNumberIntoArray(number);

    int step1 = 0;
    int tempStep1;
    for(i=1; i<arr_len; i+=2) {
    	tempStep1 = arr[i]*2;
    	if(tempStep1 > 9) {
    		tempStep1 = tempStep1%10 + tempStep1/10;
    	}
    	step1+=tempStep1;
    }
     int step2 = 0;
    for(i=0; i<arr_len; i+=2) {
    	step2 += arr[i];
    }

     int stepsTotal = step1 + step2;

     int validFlag=0;
     if (stepsTotal%10==0) {
         validFlag = 1;
         }

    if(validFlag == 1) {

    if (arr[arr_len-1] == 3 && (arr[arr_len-2] == 4 || arr[arr_len-2] == 7)) {
    		printf("AMEX\n");
    	}

    	// MasterCard
    	if (arr[arr_len-1] == 5 && (arr[arr_len-2] >= 1 && arr[arr_len-2] <= 5)) {
    		printf("MASTERCARD\n");
    	}

    	// Visa
    	if (arr[arr_len-1] == 4) {
    		printf("VISA\n");
    	}
    }
    else {
        printf("INVALID\n");
    }

}



int* convertNumberIntoArray(unsigned long long number) {
    int n = log10(number) + 1;
    int i;
    int *numberArray = calloc(n, sizeof(int));
    for ( i = 0; i < n; ++i, number /= 10 )
    {
        numberArray[i] = number % 10;
    }
    return numberArray;
}

int getLengthOfNumber(unsigned long long number) {
    return (int)floor(log10((float)number)) + 1;
}