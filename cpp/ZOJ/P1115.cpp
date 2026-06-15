#include<bits/stdc++.h>
using namespace std;
//最大子段和问题：DP
int main()
{
    int n;//数组总长度这个由题目决定是否输入
    cin>>n;
    int arr[1000];
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    int final_sum=arr[0];
    int current_sum=arr[0];
    int temp_start=0;
    int start=0;
    int end=0;
    for(int i=1;i<n;i++)
    {
        if(current_sum>0)//这个地方特别注意
        //不是数组元素大于0
        //而是以当前元素为结尾的sum和大于0；
        {
            current_sum+=arr[i];
        }
        else
        {
            current_sum=arr[i];
            temp_start=i;
        }
        if(current_sum>final_sum)
        {
            final_sum=current_sum;
            start=temp_start;
            end=i;
        }
    }   
    cout<<final_sum<<endl;
    return 0; 
}   
/*递归写法*/
/*int solve(int left,int right)
{
    if(left==right)
    {
        return arr[left]; 
    }
    int mid=left+(right-left)/2;
    int leftmax=solve(left,mid-1);
    int leftmax=solve(mid+1,right);

    int leftCross=INT_MIN;
    int currentsum=0;
    for(int i=mid-1;i>left;i--)
    {
        currentsum+=arr[i];
        if(currentsum>leftCross)
        {
            leftCross=currentsum;
        }
    }
    int rightCross=INT_MIN;
    currentsum=0;
    for(int i=mid;i<right>;i++)
    {
        currentsum+=arr[i];
        if(currentsum>rightCross)
        {
            rightCross=currentsum;
        }
    }
    int middlesum=rightCross+leftCross;
    return(max{middlesum,leftmax,rightmax})
}*/


//线段树维护区间
/*
struct Node {
    long long lSum, rSum, mSum//某段区间和, iSum//区间总和;
};

// 合并两个节点的信息
Node pushUp(Node L, Node R) {
    Node res;
    res.iSum = L.iSum + R.iSum;
    res.lSum = max(L.lSum, L.iSum + R.lSum);
    res.rSum = max(R.rSum, R.iSum + L.rSum);
    res.mSum = max({L.mSum, R.mSum, L.rSum + R.lSum});
    return res;
}

// 建立/查询函数
int a[200005];
Node solve(int L, int R) {
    if (L==R)
    {
        // 叶子节点：四个值都是该元素本身
        return {(long long)a[L],(long long)a[L],(long long)a[L],(long long)a[L]};
    }
    int mid = (L+R)/2;
    Node left = solve(L,mid);
    Node right = solve(mid+1,R);
    return pushUp(left,right);
}

int main()
{
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) scanf("%d", &a[i]);

    Node ans = solve(1, n);
    printf("%lld\n", ans.mSum);

    return 0;
}*/