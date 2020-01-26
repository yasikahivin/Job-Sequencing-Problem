
#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;


//structure of job data
struct Job
{
    string id;
    int dedL;
    int profit;
};

//sorting all jobs according to profit
bool comparison(Job a, Job b){
	return (a.profit > b.profit);
}


int min(int a, int b) {
    return (a<b)?a:b;
}

void jobSchedule(Job arr[], int n){
	//Sort all jobs according to decreasing order of profit
	sort(arr, arr+n, comparison);

    int jobSeq[n]; //Sequence of jobs
	bool slot[n]; //track free time slots

	// Initialize all slots to be free
	for (int i=0; i<n; i++)
		slot[i] = false;


	for (int i=0; i<n; i++){
	    int nxt=min(n, arr[i].dedL)-1;
        for (int j=nxt; j>=0; j--){
            if (slot[j]==false){
                jobSeq[j] = i;
                slot[j] = true;
                break;
            }
        }
	}
	int totprof=0;

	for (int i=0; i<n; i++){
        if (slot[i]){
            cout << arr[jobSeq[i]].id << " ";
            cout << arr[jobSeq[i]].profit<<endl;
            totprof=totprof+arr[jobSeq[i]].profit;
        }
	}
	cout<<"total profit : "<< totprof;
}


int main(){
    string j;
    int x,y,z;
    int n;

    cout << "Enter number of jobs : ";
    cin >> n ;

    //stuct array
    Job arr[n];

    // input the data
    for(x=0;x<n;x++){
        cout<< "enter job "<< x+1<<" id : ";
        cin>> arr[x].id;
        cout<< "enter job "<< x+1<<" Deadline : ";
        cin>> arr[x].dedL;
        cout<< "enter job "<< x+1<<" Profit : ";
        cin>> arr[x].profit;
        cout<<endl;
    }

	cout << "Maximum profit sequence of jobs "<< endl;
	jobSchedule(arr, n);

}
