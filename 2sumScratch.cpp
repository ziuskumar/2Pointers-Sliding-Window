#include<bits/stdc++.h>
using namespace std;

pair<int,int> Twosum_brute(int arr[], int n, int K){

    for(int i=0; i<n; i++){

        int sum=0;

        for(int j=i+1; j<n; j++){
            sum = arr[i] + arr[j];

            if(sum == K){
            return{i,j};
        }
        }
    }
    return{};
}

    pair<int,int> Twosum_better(int arr[], int n, int K){

        sort(arr, arr+n);

        cout<<"Elements of sorted array ";
        for(int i=0; i<n; i++){
            cout<<arr[i]<<endl;;
        }
        
        int st = 0 , end = n-1;

        while(st < end){
            int sum = arr[st] + arr[end];   

            if(sum == K){
                return {st,end};
            }

            if(sum > K){
                end--;
            }
            else{
                st++;
            }
        }
        return{-1,-1};
        
    }

    pair<int,int> Twosum_optimized(int arr[], int n, int K){

        map<int,int> mpp;

        for(int i=0; i<n; i++){
            int first = arr[i];

            int sec = K - first;

            if(mpp.find(sec) != mpp.end()){
                return{mpp[sec], i};
            }

            mpp[first] = i;
        }
        return{-1,-1};
    }

int main(){
    int n;
    cout<<"Enter length of array";
    cin>>n;

    cout<<"Enter array elements";
    int arr[n];
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }

    int K;
    cout<<"Enter Target value";
    cin>>K;

    pair<int,int> ans = Twosum_optimized(arr,n,K);

    if(ans.first == -1){
        cout<<"No pair found";
    } else {
        cout<<"Indices: "<<ans.first<<" "<<ans.second;
    }

    return 0;


}
