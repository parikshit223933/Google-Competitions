#include<iostream>
#include<algorithm>
using namespace std;
int minimum_hours(int*skill, int n, int p)
{
    sort(skill, skill+n);
    int sum_of_p_elements=0;
    for(int i=0; i<p; i++)
    {
        sum_of_p_elements+=skill[i];
    }
    int i=0;
    int j=p-1;
    int best_i=0;
    int best_j=p-1;
    
}
int main()
{
    int t;
    cin>>t;
    for(int test_case=1; test_case<=t; test_case++)
    {
        int n, p;
        cin>>n>>p;
        //n==number of students
        //p==number of students i have to pick
        int *skill=new int [n];
        for(int i=0; i<n; i++)
        {
            cin>>skill[i];
        }
        cout<<"Case #"<<test_case<<": "<<minimum_hours(skill, n, p)<<endl;
    }
}