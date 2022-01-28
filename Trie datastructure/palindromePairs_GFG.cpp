#include<iostream>
#include<bits/stdc++.h>
#define ppi pair<int,int>
#define lli long long int
#define li long int
#define vi vector<int>
#define vlli vector<lli>
#define vli vector<li>
#define vvi vector<vector<int>>
#define vppi vector<pair<int,int>>
#define rep(i,k,n) for (i = k; i < n; ++i)
#define Repr(i,k,n) for (i = k; i >= n; --i)
#define c(n) cout<<n<<endl
#define z(n) cout<<n<<" "
#define nl cout<<endl;
#define INF INT_MAX
using namespace std;

struct node{
    node* arr[26];
    bool flag=false;
  
    bool check(char ch){
        return (arr[ch-'a']!=NULL);
    }
    node* get(char ch){
        return arr[ch-'a'];
    }
    void put(char ch){
        arr[ch-'a']= new node();
    }
    void set(){
        flag= true;
    }

};

class Trie{
    private: 
    node* root;
    public:
    Trie(){
        root= new node();
    }
    void insert(string word){
        node* temp= root;
        for(int i=0;i<word.size();i++){
            if(temp->check(word[i])==0){
                temp->put(word[i]);
            }
            temp= temp->get(word[i]);
        }
        temp->set();
    }
    bool search(string word){
        node* temp= root;
        for(int i=0;i<word.size();i++){
            if(!temp->check(word[i])){
                return 0;
            }
            temp= temp->get(word[i]);
        }
        return temp->flag;
    }

    bool startsWith(string word){
        node* temp= root;
        for(int i=0;i<word.size();i++){
            if(!temp->check(word[i])){
                return 0;
            }
            temp= temp->get(word[i]);
        }
        return 1;
    }
};

// class Solution{   
//   public:
//     // Function to check if a palindrome pair exists
//     bool palindromepair(int n, string arr[]) {
//         Trie trie;
//         for(int i=0;i<n;i++){
//             trie.insert(arr[i]);
//         }
//         for(int i=0;i<n;i++){
//             // string temp= reverse(arr[i].begin(),arr[i].end());
//             string temp2= "";string temp="";
//             string s= arr[i];int sz= s.size();
//             for(int j=sz-1;j>=0;j--){temp+= s[j];}
//             for(int j=sz-2;j>=0;j--){temp2+= s[j];}
//             if(trie.search(temp)){return 1;}
//             if(trie.search(temp2)){return 1;}
//         }
//         return 0;
//     }

// };

bool isPalindrome(string s){
    int i=0;int j= s.size()-1;
    while(i<=j){
        if(s[i]!=s[j]){return 0;}
        i++;j--;
    }
    return 1;
}
class Solution {
public:
    bool palindromepair(int n, string arr[]) {
        // int n= arr.size();
        Trie trie;
        for(int i=0;i<n;i++){
            string temp="";
            int sz= arr[i].size();
            for(int j=sz-1;j>=0;j--){temp+= arr[i][j];}
            trie.insert(temp);
        }
        for(int i=0;i<n;i++){
            if(trie.search(arr[i])){return 1;}
            for(int j=0;j<arr[i].size();j++){
                string left= arr[i].substr(0,j+1);
                string right= arr[i].substr(j+1);
                if(isPalindrome(left)){
                    if(trie.search(right)){
                        return 1;
                    }
                }
                if(isPalindrome(right)){
                    if(trie.search(left)){
                        return 1;
                    }
                }
            }
        }
        return 0;
    }
};


int main(){
    
    return 0;
}