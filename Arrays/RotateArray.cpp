#include <iostream>
#include<vector>
using namespace std;

void reverse1(vector<int>&arr , int i , int j)
{
    while(i < j)
    {
        int t = arr[i];
        arr[i] = arr[j];
        arr[j] = t;
        i++;
        j--;
    }
}
void rotate1(vector<int>&arr , int n , int d)
{
    reverse1(arr , 0 , n - d - 1);
    reverse1(arr , n - d , n - 1);
    reverse1(arr , 0 , n - 1);
}
int main() {

	int t;
	vector<vector<int>> v;
	cin >> t;
	while(t--){
	    int n , d;
	    cin >> n >> d;
	    vector<int>arr;
	    for(int i = 0 ; i < n ; i ++)
	    {
	        int p;
	        cin >> p;
	        arr.push_back(p);
	    }
	    rotate1(arr , n , d);
        v.push_back(arr);
	}

	for(int i = 0 ; i < v.size() ; i ++)
	{
	    for(int j = 0 ; j < v[i].size(); j++ )
	    {
	        cout << v[i].at(j);
	    }
	    cout << endl;
	}
	return 0;
}
