#include<iostream>
#include<vector>
#include<unordered_map>
#include<string>
#include<limits>
using namespace std;
class slidingWindow
{
public:
    static vector<double> contiguousVector(vector<int> v, int k)
    {
        vector<double> ans(v.size() - k + 1);
        int c(0),windowstart(0);
        double sum(0);
        double avg(0);
        for(int windowend = 0; windowend< v.size(); windowend++)
        {
            sum += v[windowend];
            c++;
            if(c == k )
            {
                avg = sum/k;
                ans[windowstart] = avg;
                sum  -= v[windowstart];
                windowstart++;
                c = c-1;
            }
        }
        return ans;
    }
    static int sum(const vector<int>& v, int k)
    {
        int c(0),windowstart(0),maxsum(0),sum(0);
        for(int windowend = 0; windowend<v.size(); windowend++)
        {
            sum += v[windowend];
            c++;
            if(c == k)
            {
                maxsum = max(maxsum, sum);
                sum -= v[windowstart];
                windowstart++;
                c -= 1;
            }
        }
        return maxsum;
    }
    static int smallestSubarray(const vector<int>& v, int k)
    {
        int windowstart(0),sum(0),ans(0);
        int minim = numeric_limits<int>::max();
        for(int windowend = 0; windowend<v.size(); windowend++)
        {
            sum += v[windowend];
            while(sum >= k)
            {
                minim = min(minim, windowend - windowstart + 1);
                sum -= v[windowstart];
                windowstart++;
            }
        }
        return minim;
    }
    static int longestsubstring(const string& s, int k)
    {
        unordered_map<char,int> M;
        int windowstart(0),count(0);
        for(int windowend = 0;windowend<s.length(); windowend++)
        {
            M[s[windowend]]++;
            count++;
            while(M.size()>k){
                M[s[windowstart]]--;
                if(M[s[windowstart]]==0)
                {
                    M.erase(s[windowstart]);
                }
                count--;
                windowstart++;

            }


        }
        return count;

    }
    static int fruitbasket(const vector<char>& v)
    {
        int windowstart(0);
        unordered_map<char,int> M;
        int maxans(0);
        for(int windowend = 0;windowend< v.size();windowend++)
        {
            M[v[windowend]]++;

            while(M.size()> 2)
            {
                M[v[windowstart]]--;
                if(M[v[windowstart]]==0)
                {
                    M.erase(v[windowstart]);
                }
                windowstart++;
            }
            maxans = max(maxans, windowend - windowstart +1);
        }
        return maxans;

    }
};
int main()
{
    vector<double> contiguousAnswer = slidingWindow::contiguousVector(vector<int> {1,5,6,3,1,4}, 3);
    cout<<"Answer for contiguous vector: "<<endl;
    for(auto i: contiguousAnswer)
    {
        cout<<i<<endl;
    }
    int ans = slidingWindow::sum(vector<int> {1,4,2,5,2,3},3);
    cout<<"Answer for maximum subarray: "<<ans<<endl;
    int minAns = slidingWindow::smallestSubarray(vector<int> {1,3,2,4,3},10);
    cout<<"Answer of smallest subarray: "<<minAns<<endl;
    int longestsub = slidingWindow::longestsubstring("cbbebi",3);
    cout<<"Answer of long substring: "<<longestsub<<endl;
    int fruitbask = slidingWindow::fruitbasket(vector<char>{'A','B','A','A','C'});
    cout<<"Answer of fruitbasket: "<<fruitbask<<endl;

    return 0;

}

/*
1, 4, 5, 3 ,5, 5 k = 3
1+4+5/3
*/
