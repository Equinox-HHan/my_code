#include<bits/stdc++.h>
using namespace std;

class Complex
{
    public:
        Complex(double real=0,double imag=0)
        {
            Real=real;
            Imag=imag;
        }
        Complex &operator --()
        {
            Real--;
            Imag--;
            return *this;
        }
        Complex operator --(int)
        {
            Complex original=*this;
            --(*this);
            return original;
        }
        double getReal()
        {
            return Real;
        }
        double getImag()
        {
            return Imag;
        }
        void show()
        {
            cout<<getReal()<<" "<<getImag()<<endl;
        }
    private:
        double Real;
        double Imag;
};

int main()
{
    Complex complex(3,4);
    complex.show();
    (complex--).show();
    (--complex).show();
    return 0;
}