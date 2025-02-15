#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n=0, maxe=0;
    cin >> n;
    
    vector<int> v;
    
    for(int i=0; i<n; i++)
    {
        int a = 0;
        cin >> a;
        v.push_back(a);
    }
    
    for(int i=0; i<n-1; i++)
    {
        for(int j = i+1; j<n; j++)
        {
            int klk = (j-i)*(min(v[i],v[j]));
            
            if(klk>maxe)
            maxe=klk;
        }
    }
    
    cout << maxe;

    return 0;
}