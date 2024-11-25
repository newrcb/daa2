#include<bits/stdc++.h>
using namespace std;
struct Student{
    string name;
    int score;
};
int partition(Student arr[],int left,int right){
    int pivot = arr[right].score;
    int i = left-1;
    for(int j=left;j<right;j++){
        if(arr[j].score<=pivot){
            i++;
            swap(arr[i],arr[j]);
        }
    }
    swap(arr[i+1],arr[right]);
    return i+1;
}
void quicksort(Student arr[],int left,int right){
    if(left < right){
        int pi = partition(arr,left,right);
        quicksort(arr,left,pi-1);
        quicksort(arr,pi+1,right);
    }
}
void display(Student arr[],int n){
    for(int i=0;i<n;i++){
        cout<<arr[i].name<<" : "<<arr[i].score<<endl;
    }
}
int main(){
    int n;
    cout<<"Enter no.of students: ";
    cin>>n;
    Student arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i].name>>arr[i].score;
    }
    cout<<"Original: "<<endl;
    display(arr,n);
    quicksort(arr,0,n-1);
    cout<<"After Sorting:"<<endl;
    display(arr,n);
    return 0;
}