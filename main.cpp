#include<iostream>
#include<vector>
#include<unordered_map>
#include<string>
using namespace std;
class slidingWindow{
public:
    static vector<double> contiguousVector(vector<int> v, int k){
        vector<double> ans(v.size() - k + 1);
        int c(0),windowstart(0);
        double sum(0);
        double avg(0);
        for(int windowend = 0; windowend< v.size();windowend++){
            sum += v[windowend];
            c++;
            if(c == k ){
                avg = sum/k;
                ans[windowstart] = avg;
                sum  -= v[windowstart];
                windowstart++;
                c = c-1;
            }
        }
        return ans;
    }
    static int sum(const vector<int>& v, int k){
        int c(0),windowstart(0),maxsum(0),sum(0);
        for(int windowend = 0;windowend<v.size();windowend++){
            sum += v[windowend];
            c++;
            if(c == k){
                maxsum = max(maxsum, sum);
                sum -= v[windowstart];
                windowstart++;
                c -= 1;

            }
        }
        return maxsum;


    }


};
int main(){
    vector<double> contiguousAnswer = slidingWindow::contiguousVector(vector<int> {1,5,6,3,1,4}, 3);
    cout<<"Answer for contiguous vector: "<<endl;
    for(auto i: contiguousAnswer){
        cout<<i<<endl;
    }
    int ans = slidingWindow::sum(vector<int> {1,4,2,5,2,3},3);
    cout<<"Answer for maximum subarray: "<<ans<<endl;
    return 0;

}

/*
1, 4, 5, 3 ,5, 5 k = 3
1+4+5/3
*/
