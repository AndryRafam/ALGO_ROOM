// Find the longest common substring of multiple string

#include <bits/stdc++.h>
using namespace std;

bool compare(string &a,string &b){
    return a.size() < b.size();
}

string findStem(vector<string> &arr){
     vector<string> res;
     string s = "";
     for(auto i = 0; i < arr[0].length(); ++i){
        for(auto j = 1; j <= arr[0].length()-i; ++j){
            s = arr[0].substr(i,j);
            auto k = 1;
            while(k < arr.size()){
                if(arr[k].find(s)==string::npos)
                    break;
                k++;
            }
            if(k==arr.size()) // if s is common to every string, push it in the array
                res.emplace_back(s);
        }
     }
     return (res.size()==0 ? "KO":*max_element(res.begin(),res.end(),compare)); // if res is empty, return KO. Else, return the longest common substring
}

int main(){
	ios_base::sync_with_stdio(0);
	vector<string> test1 = {"gracefully","graceful","disgrace","disgraceful"};
	vector<string> test2 = {"grace","sd","test"};

	cout << findStem(test1); // grace
	cout << "\n";
	cout << findStem(test2); // KO
	return 0;
}
