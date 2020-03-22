#include<iostream>
#include<algorithm>
using namespace std;
int original_k;
int maximum_beauty(int **arr, int n, int k, int p)
{
    if(k<=0||n<=0||p<=0)
    {
        return 0;
    }
    int *option1=new int [k];
    int maximum_element_in_option_1=0;
    for(int i=0; i<k; i++)
    {
        option1[i]=arr[0][i]+maximum_beauty(arr+1, n-1, k, p-i);
        maximum_element_in_option_1=max(maximum_element_in_option_1, option1[i]);
    }
    int option2=maximum_beauty(arr+1, n-1, k, p);
    int option3=maximum_beauty(arr, n, k-1, p);
    return max(maximum_element_in_option_1, max(option2, option3));
}
int main()
{
    int t;
    cin>>t;
    for(int test_case=1; test_case<=t; test_case++)
    {
        int n, k, p;
        cin>>n>>k>>p;
        original_k=k;
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
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<k; j++)
            {
                cout<<arr[i][j]<<" ";
            }
            cout<<endl;
        }

        cout<<"Case #"<<test_case<<": "<<maximum_beauty(arr, n, k, p)<<endl;
    }
}