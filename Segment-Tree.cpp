#include<bits/stdc++.h>
using namespace std;
const int N = 1e5+3;
int n,arr[N],seg[4*N];

void build(int p,int l,int r){
    if(l==r){
        seg[p]=arr[l];
        return;
    }
    int mid=(l+r)/2;
    build(2*p,l,mid);
    build(2*p+1,mid+1,r);
    seg[p]=seg[2*p]+seg[2*p+1];
}

int get(int p,int l,int r,int a,int b){
    if(a<=l && r<=b){
        return seg[p];
    }
    if(r<a || b<l)
        return 0;
    int mid=(l+r)/2;
    return get(2*p,l,mid,a,b)+get(2*p+1,mid+1,r,a,b);
}

void update(int p,int pos,int value,int l,int r){
    if(l==r){
        arr[pos]=value;
        seg[p]=value;
        return;
    }
    int mid=(l+r)/2;
    if(pos<=mid)
        update(2*p,pos,value,l,mid);
    else
        update(2*p+1,pos,value,mid+1,r);

    seg[p]=seg[2*p]+seg[2*p+1];
}


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    //freopen("in","r",stdin);
    cin>>n;
    for(int i=0;i<n;i++)
        cin>>arr[i];
    build(1,0,n-1);

    int q;cin>>q;
    for(int t,a,b,i=0;i<q;i++){
        cin>>t>>a>>b;
        if(t==0){
            a--;b--;
            cout<<get(1,0,n-1,a,b)<<endl;
        }
        else{
            a--;
            update(1,a,b,0,n-1);
        }
    }

    return 0;
}
