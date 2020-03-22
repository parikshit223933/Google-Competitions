#include<iostream>
#include<algorithm>
using namespace std;
int maximum_beauty(int **arr, int n, int k, int p)
{
    if(p<0)
    {
        return 0;
    }
    if(n<=0)
    {
        return 0;
    }
    if(k<=0)
    {
        return 0;
    }
    int *option1=new int [k];
    int *option2=new int [k];
    int *ans=new int [k];
    for(int i=0; i<k; i++)
    {
        if(p>i)
        {
            option1[i]=arr[0][i]+maximum_beauty(arr+1, n-1, k, p-i-1);
            option2[i]=maximum_beauty(arr+1, n-1, k, p);
            int another_option=maximum_beauty(arr, n, k-1, p);
            ans[i]=max(option1[i], max(option2[i], another_option));
        }
        else
        {
            option1[i]=maximum_beauty(arr, n, k-1, p);
            option2[i]=maximum_beauty(arr+1, n-1, k, p);
            ans[i]=max(option1[i], option2[i]);
        }
    }
    sort(ans, ans+k);
    int answer=ans[k-1];
    delete[]option1;
    delete[]option2;
    delete[]ans;
    return answer;
}
int main()
{
    int t;
    cin>>t;
    for(int test_case=1; test_case<=t; test_case++)
    {
        int n, k, p;
        cin>>n>>k>>p;
        int **arr=new int *[n];
        for(int i=0; i<n; i++)
        {
            arr[i]=new int [k];
            cin>>arr[i][0];
            for(int j=1; j<k; j++)
            {
                int element;
                cin>>element;
                arr[i][j]=arr[i][j-1]+element;
            }
        }

        cout<<"Case #"<<test_case<<": "<<maximum_beauty(arr, n, k, p)<<endl;
        for(int i=0; i<n; i++)
        {
            delete[]arr[i];
        }
        delete[]arr;
    }
}