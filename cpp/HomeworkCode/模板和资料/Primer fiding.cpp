#include<iostream>
using namespace std;

int main()
{
    int num;
    bool isPrime = true;
    
    cout << "Enter a number: ";
    cin >> num;
    
    if(num <= 1) {
        isPrime = false;
    } else {
        for(int i = 2; i <= num/2; i++) {
            if(num % i == 0) {
                isPrime = false;
                break;
            }
        }
    }
    
    if(isPrime)
        cout << num << " is a prime number" << endl;
    else
        cout << num << " is not a prime number" << endl;
        
    system("pause");
    return 0;
}
//一个质数的因子只有一和它本身，而如果存在其他因子，该因子最小的理论值只能是二，
//因此试除法的第一步假设存在一个因数i，这个i就是要求的数num除以2的商，
//这时候这个商数应该就是i的最大因子（如果i不是素数的话),
//所以i的取值范围是从2到num/2。
//如果num能被i整除，那么num就不是质数，反之则是质数。