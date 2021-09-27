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


};
int main(){
    vector<double> contiguousAnswer = slidingWindow::contiguousVector(vector<int> {1,5,6,3,1,4}, 3);
    cout<<"Answer for contiguous vector: "<<endl;
    for(auto i: contiguousAnswer){
        cout<<i<<endl;
    }
    return 0;

}

/*
1, 4, 5, 3 ,5, 5 k = 3
1+4+5/3
*/
