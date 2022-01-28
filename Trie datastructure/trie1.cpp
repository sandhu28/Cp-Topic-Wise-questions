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
    node* links[26];
    bool flag = false;
    bool containsKey(char ch){
        return (links[ch-'a']!=NULL);
    }
    void put(char ch, node* n){
        links[ch-'a'] = n;
    }
    node* get(char ch){
        return links[ch-'a'];
    }
    void setEnd(){
        flag= true;
    }
    bool isEnd(){
        return flag;
    }
};

class Trie {
private: 
    node * root;
public:

    /** Initialize your data structure here. */
    Trie() {
		root= new node();
    }

    /** Inserts a word into the trie. */
    void insert(string word) {
		node* temp= root;
        for(int i=0;i<word.size();i++){
            if(!temp->containsKey(word[i]) ){
                temp->put(word[i],new node()); 
            }
            temp=temp->get(word[i]); 
        }
        temp->setEnd();
    }

    /** Returns if the word is in the trie. */
    bool search(string word) {
        node* temp = root;
        for(int i=0;i<word.size();i++){
            if(!temp->containsKey(word[i])){
                return false;
            }
            temp= temp->get(word[i]);
        }
        return temp->isEnd();
    }

    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        node* temp= root;
        for(int i=0;i<prefix.size();i++){
            if(!temp->containsKey(prefix[i])){
                return false;
            }
            temp= temp->get(prefix[i]);
        }
        return true;
    }
};

int main(){
    
    return 0;
}