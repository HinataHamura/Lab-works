#include <iostream>
#include<string>
using namespace std;

bool isPowerOfTwo(int num) {
    if (num <= 0) {
        return false;
    }
    while (num % 2 == 0) {
        num /= 2;
    }
    if(num==1){
        return true;
    }
    else
    return false;
}

int countOnesInBinary(string binary) {
    int count = 0;
    for (int i = 0; i < binary.size(); i++) {
        count += ((binary[i] == '1') ? 1 : 0);
    }
    return count;
}



void decimalToBinaryInRange(int start, int end) {
    int total1s=0;
    cout << "Decimal\t Binary\t\tCount of 1s\n";
    for (int i = start; i <= end; ++i) {
        int num = i;
        string binary = "";
        while (num > 0) {
            binary = to_string(num % 2) + binary;
            num /= 2;
        }
        int onesCount = countOnesInBinary(binary);
        total1s=total1s+onesCount;
        cout << i << "\t  " << binary << "\t\t" << onesCount << "\n";
    }
    cout<<"Total number of 1: "<<total1s<<endl;
}

int main() {
    int startRange, endRange;
    cout << "Enter the start of the range: ";
    cin >> startRange;
    cout << "Enter the end of the range: ";
    cin >> endRange;
    if((isPowerOfTwo(startRange)==false) || isPowerOfTwo(endRange)==false){
        cout<<"Range is not power of 2"<<endl; 
        return 0;
    }

    decimalToBinaryInRange(startRange, endRange);

    return 0;
}
