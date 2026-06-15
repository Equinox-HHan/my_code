#include<bits/stdc++.h>
using namespace std;

class Matrix
{
    public:
        Matrix(int r=0,int c=0)
        {
            row=r;
            col=c;
            Room();
            for(int i=0;i<row;i++)
            {
                for(int j=0;j<col;j++)
                {
                    matrix[i][j]=0;
                }
            }
        }
        ~Matrix()
        {
            DRoom();
        }
        void setNumber(int x,int y,int number)
        {
            if(x>row||x<1||y>col||y<row)
            {
                cout<<"Error"<<endl;
                return;
            }
            else
            {
                matrix[x][y]=number;
                return;
            }
        }
        Matrix operator+ (const Matrix &p) const
        {
            Matrix temp(row,col);
            for(int i=0;i<row;i++)
            {
                for(int j=0;j<col;j++)
                {
                    temp.matrix[i][j]=matrix[i][j]+p.matrix[i][j];
                }
            }
            return temp;
        }
        int getLine()
        {
            return row;
        }
        int getCol()
        {
            return col;
        }
         friend ostream& operator<< (ostream &cout,const Matrix &p);
    private:
        int row;
        int col;
        double **matrix;
        void Room()
        {
            matrix=new double*[row];
            {
                for(int i=0;i<row;i++)
                {
                    matrix[i]=new double[col];
                }
            }
        }
        void DRoom()
        {
            for(int i=0;i<col;i++)
            {
                delete[] matrix[i];
            }
            delete[] matrix;
        }
};
ostream& operator<<(ostream& os, const Matrix& matrix)
{
    os << fixed << setprecision(2);
    for (int i=0;i<matrix.row;i++)
    {
        for (int j=0;j<matrix.col;j++)
        {
            os<<" "<<matrix.matrix[i][j]<<" ";
        }
        os<<endl;
    }
    return os;
}
int main()
{
    Matrix arr1(3,3);
    Matrix arr2(3,3);
    Matrix arr3=arr1+arr2;
    cout<<arr3<<endl;
}