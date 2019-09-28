//Finding Minimum in sub-Array
#include<bits/stdc++.h>
using namespace std;
const int N = 1e5+3;
int n,root,arr[N],bucket[N],q;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    //freopen("in","r",stdin);
    cin>>n;
    root=sqrt(n);
    for(int i=0;i<n;i++)
        cin>>arr[i];
    for(int i=0;i<n;i++){
        if(i%root==0)
            bucket[i/root]=arr[i];
        else
            bucket[i/root]=min(bucket[i/root],arr[i]);
    }
    cin>>q;
    int l,r,ans;
    while(q--){
        ans=1e9+7;
        cin>>l>>r;
        for(int i=l;i<=r;i++){
            if(i%root==0 && i+root-1<=r){
                ans=min(ans,bucket[i/root]);
                i+=root-1;
            }
            else{
                ans=min(ans,arr[i]);
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}
