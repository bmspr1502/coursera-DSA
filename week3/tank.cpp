#include <iostream>
#include <vector>

using namespace std;

int compute_min_refills(int dist, int tank, vector<int> & stops) {
    // write your code here
    int n = stops.size();
    stops.push_back(dist);
    int numRefill = 0, currRefill =0;
    while(currRefill<=n){
        
        //cout<<"\nnumrefill = "<<numRefill;
        int lastRefill = currRefill;
        //cout<<"\nlastrefill = "<<lastRefill;
        //cout<<" stops[lastreffill] = "<<stops[lastRefill];
        while(currRefill<= n && (stops[currRefill + 1] - stops[lastRefill])<=tank){
            //cout<<"\ncurrRefill = "<<currRefill<<", stops[currRefill+1] = "<<stops[currRefill + 1];
            currRefill++;
        }
        if(currRefill == lastRefill)
            return -1;
        //cout<<"\ncurrRefill = "<<currRefill<<endl;
        if(currRefill<=n)
            numRefill++;
        
    }
    return numRefill;
}


int main() {
    int d = 0;
    cin >> d;
    int m = 0;
    cin >> m;
    int n = 0;
    cin >> n;

    vector<int> stops(n);
    for (size_t i = 0; i < n; ++i)
        cin >> stops.at(i);
    
    cout << compute_min_refills(d, m, stops) << "\n";

    return 0;
}
