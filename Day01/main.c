#include <stdio.h>
#include <inttypes.h>
#include <ctype.h>

int sumOfCalibrationValues(char* in, size_t size){
    char firstNum = '\0';
    char secondNum = '\0';
    int sum=0;

    for(size_t i = 0; i < size; i++){
        if (in[i] == '\n' || in[i] == '\0') {
            char addedString[] = {firstNum,secondNum}; 
            sum += strtoumax(addedString,NULL,10);

            firstNum='\0';
            secondNum='\0';
        }
        else if(isdigit(in[i]) != 0){
            
            if (firstNum != '\0'){
                secondNum = in[i];
            }
            else {
                firstNum = in[i];
                secondNum = in[i];
            }

        }
        else {
            continue;
        }
    }
    return sum;
}


int main () {
    char input[] = "1abc2\npqr3stu8vwx\na1b2c3d4e5f\ntreb7uchet";
    size_t size = sizeof(input)/sizeof(input[0]);
    
    printf("The calibration size is: %d!\n", sumOfCalibrationValues(input,size));
}
