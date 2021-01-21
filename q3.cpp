#include<bits/stdc++.h>
using namespace std;
#define F first
#define S second

void print(vector<string>S,vector<pair<string,int> > S2)
{


    cout<<"\n[[";
    if(S.size()>0)
        cout<<"\""<<S[S2[0].S]<<"\"";

    for(int i = 1;i<S.size();i++)
    {
        if(S2[i].F==S2[i-1].F)
        {
            cout<<" ,"<<"\""<<S[S2[i].S]<<"\"";
        }
        else{
            cout<<"],["<<"\""<<S[S2[i].S]<<"\"";
        }
    }

    cout<<"]]"<<endl;

}

int main()
{
    vector<string>S;
    vector<pair<string,int> > S2;
    string ss;
    int n;

    printf("Number of Strings :");

    scanf("%d",&n);

    printf("Enter all strings: ");

    for(int i=0;i<n;i++)
    {
        cin>>ss;
        S.push_back(ss);
        S2.push_back({ss,i});
        sort(S2[i].F.begin(),S2[i].F.end());
    }

    sort(S2.begin(),S2.end());

    print(S,S2);


return 0;
}
