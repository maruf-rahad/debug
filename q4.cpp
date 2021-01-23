#include<bits/stdc++.h>
using namespace std;

vector<int>ans;

void printss(string s)
{
    stack<int>stk;
    stack<int>stksign;

    int sum = 0,flag = 0,res = 0;

    for(int i = 0;i<=s.size();i++)
    {
        if(s[i]>='0'&&s[i]<='9')
        {
            sum = sum*10+s[i]-'0';
            flag = 1;
        }
        else if(flag==1)
        {
            stk.push(sum);
            sum = 0;
            flag = 0;
        }

        if(s[i]=='+'||s[i]=='-'||s[i]=='*')
        {
            stksign.push(s[i]);
        }

        if(s[i]==')')
        {
            int num1 = stk.top();
            stk.pop();
            int num2 = stk.top();
            stk.pop();
            char sign = stksign.top();
            stksign.pop();

            if(sign=='+')res = num2+num1;
            else if(sign=='-')res = num2-num1;
            else if(sign=='*')res = num2*num1;
            stk.push(res);
        }
    }
    printf("result = %d\n\n",res);
    ans.push_back(res);

    return;
}

void recur(int i,int l,int r,vector<int>v,string s)
{

    if(i>=s.size())
    {
        if(l==0&&r==0)
        {
           cout<<s<<endl;
           printss(s);
        }
        return;
    }
    if(s[i]>='0'&&s[i]<='9')
    {
        int _l=l; //for backtrack save elements
        int _r=r;
        vector<int>_v=v;
        string _s=s;

        for(int j=1; j<=l; j++)
        {
            s.insert(i,j,'(');
            int tt=j;
            while(tt--) v.push_back(i);
            recur(i+1+j,l-j,r,v,s);

            l=_l;   //tracking previous elements
            r=_r;
            v=_v;
            s=_s;
        }

        if(r>0)
        {
            map<int,int>mp;

            int vsz = v.size();
            int mn=min(r,vsz);
            int mn1=mn;
            int t2=0;
            while(mn1--)
            {
                int num=v.back();
                if(mp[num]==1)
                {
                    mn=t2;
                    break;
                }
                mp[num]=1;
                s.insert(i+1,1,')');
                t2++;
                v.pop_back();
            }

            recur(i+mn+1,l,r-mn,v,s);
            l=_l;
            r=_r;
            v=_v;
            s=_s;
        }
    }
    else recur(i+1,l,r,v,s);
}


int main()
{
    string s="2*3-4*5";
    //string s = "2-1-1";
    int n=s.size();
    vector<int>v;
    v.clear();
    ans.clear();

    recur(0,n/2,n/2,v,s);

    for(int i=0;i<ans.size();i++)
    {
        printf("%d ",ans[i]);
    }
    printf("\n");

    return 0;
}
