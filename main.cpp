#include <iostream>

using namespace std;

void minSum(unsigned int sum, unsigned int* num, unsigned int &min){
    min = sum-num[0]-num[5]-num[7];
    string state = "BCG";
    unsigned int min_temp = sum-num[0]-num[4]-num[8];
    if (min > min_temp){min = min_temp; state="BGC";}
    min_temp = sum-num[2]-num[3]-num[7];
    if (min > min_temp){min = min_temp; state="CBG";}
    min_temp = sum-num[2]-num[4]-num[6];
    if (min > min_temp){min = min_temp; state="CGB";}
    min_temp = sum-num[1]-num[3]-num[8];
    if (min > min_temp){min = min_temp; state="GBC";}
    min_temp = sum-num[1]-num[5]-num[6];
    if (min > min_temp){min = min_temp; state="GCB";}
    cout << state << ' ';
}

void minMovements(unsigned int sum, unsigned int* num){
    unsigned int min;
    minSum(sum,num,min);
    cout << min << '\n';
}

int main() {
    unsigned int* num = new unsigned int[9];
    unsigned int sum;
    while (scanf("%u %u %u %u %u %u %u %u %u", &num[0], &num[1], &num[2], &num[3], &num[4], &num[5], &num[6],
                 &num[7], &num[8])!=EOF) {
        sum = 0;
        for (unsigned int i = 0; i < 9; i++) {
            sum += num[i];
        }
        minMovements(sum, num);
    }
    return EXIT_SUCCESS;
}
