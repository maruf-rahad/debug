#include<bits/stdc++.h>
using namespace std;
void combinations(int candidates[],int n,int i,int target,int sum,vector<int>v,int flag)
{

    if(sum== target)
    {
        if(flag==0)
        {
            flag = 1; // for handling coma
        }
        else
        {
            printf(",");
        }

        printf("[%d",v[0]);
        for(int j=1;j<v.size();j++)
        {
            printf(",%d",v[j]);
        }
        printf("]");

        return;
    }
    if(i>n||sum>target)return;

    v.push_back(candidates[i]);

    combinations(candidates,n,i,target,sum+candidates[i],v,flag);

    v.pop_back();
    combinations(candidates,n,i+1,target,sum,v,flag);

    return;
}


int main()
{
    int n,a,target;

    printf("Number of candidates: ");
    scanf("%d",&n);

    vector<int>v;
    int candidates[n+5];

    printf("Enter candidates :");
    for(int i = 1; i<=n ;i++)
    {
        scanf("%d",&candidates[i]);
    }

    printf("Enter target :");
    scanf("%d",&target);
    v.clear();

    printf("[");
    combinations(candidates,n,1,target,0,v,0);

    printf("]\n");

return 0;
}
