#include<vector>
#include<queue>
using namespace std;
vector<int> kLargest(vector<int> input, int n, int k){
    /* Don't write main().
     * Don't read input, it is passed as function argument.
     * Return output and don't print it.
     * Taking input and printing output is handled automatically.
     */
    priority_queue<int , vector<int>, greater<int> > pq;
    
    for(int i = 0 ; i < k ; i ++){
        pq.push(input[i]);
    }
    
    for(int i = k; i < n ; i ++){
        
        int miniFromset = pq.top();
        
        if(miniFromset < input[i]){
            pq.pop();
            pq.push(input[i]);
        }
    }
    
    vector<int> v;
    
    while(!pq.empty()){
        v.push_back(pq.top());
        pq.pop();
    }
    
    return v;
}
