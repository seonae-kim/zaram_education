#include <stdio.h>

int main() {
    int numbers[10]; // 입력 숫자를 저장할 배열
    int max, min; // 최대값과 최소값을 저장할 변수

    // 10개의 숫자를 입력 받음
    for (int i = 0; i < 10; i++) {
        scanf_s("%d", &numbers[i]);
    }


    // 초기 최대값과 최소값 설정
    max = -5;
    min = 10000;




for (int k = 0; k < 5; k++) {
    for (int i = 0; i < 10; i++) {          

        if (numbers[i] == max) {
            numbers[i] = 0;
        }
    }               //최대값인 원소 0으로하는거( number[i]= 12 를 0으로

    max = -5;

    for (int i = 0; i < 10; i++) {

        if (numbers[i] > max) {             //최댓값을 max로하는거
            max = numbers[i];
        }

        else if (numbers[i] <= max) {
            max = max;
        }

    }

    printf("%d ", max);         //가 나온거 확인
}


// min

for (int i = 0; i < 10; i++) {

    if (numbers[i] < min) {             //최소값을 1로 찾아오는거
        min = numbers[i];
    }

    else if (numbers[i] >= min) {
        min = min;
    }

}




for (int k = 0; k < 5; k++) {
    for (int i = 0; i < 10; i++) {

        if (numbers[i] == min) {            //min =1 이면 numbers[0], number[3] 과 동일 //    number[
            numbers[i] = 10000;
        }                           // 1가진 원소들이 한번에바뀜   numbers[0] , number[3]이 둘다 1이니까 둘다 바뀜 근데 number[3]은 아직 바뀌면안됨

    }               //최소값인 원소 0으로하는거( number[i]= 12 를 100000으로

    min = 10000;

    for (int i = 0; i < 10; i++) {

        if (numbers[i] <= min) {             //최소값을 min로하는거
            min = numbers[i];
        }

        else if (numbers[i] > min) {
            min = min;
        }

    }

    printf("%d ", min);         //가 나온거 확인
}













//
//

    for (int i = 0; i < 10; i++) {
        if (numbers[i] < min) {
            min = numbers[i];
        }
        else if (numbers[i] >= min) {
            min = min;
        }
    }

    //printf("%d", max);
    //printf("%d", min);


    // 최대값과 최소값을 번갈아가며 출력
    for (int i = 0; i < 10; i++) {              //num[0] num[9] 지정된 상태


            if (i % 2 == 0) {
                // 짝수 인덱스에서는 최대값 출력   (num[0] num[2] num[4]...
                if (numbers[i] > max) {
                    max = numbers[i];
                }

                //printf("%d ", max);
            }


            else {
                // 홀수 인덱스에서는 최소값 출력  (num[1] num[3] num[5]//
                if (numbers[i] < min) {
                    min = numbers[i];
                }
                //printf("%d ", min);
            }

           
            

    }

    return 0;
}






