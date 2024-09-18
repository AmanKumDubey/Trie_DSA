#include<iostream>
#include<bits/stdc++.h>
using namespace std;


// Isertion , Searching and Removal in trie

class TrieNode{

    public:
    char data;
    TrieNode* children[26];
    bool isTerminal;

    TrieNode(char ch){
        data=ch;

        for(int i=0;i<26;i++){
            children[i]=NULL;
        }
        isTerminal=false;
    }
};

class Trie{
    public:
    TrieNode* root=new TrieNode('\0');

    void insertUtill(TrieNode * root,string word){

        //base case
        if(word.length()==0){
            root->isTerminal=true;
            return;
        }
        // assumption, word will be in CAPS
        int index=word[0]-'A';
        TrieNode* child;

        //present
        if(root->children[index]!=NULL){
            child=root->children[index];
        }
        else{
            //absent
            child=new TrieNode(word[0]);
            root->children[index]=child;
        }

        //recursion
        insertUtill(child,word.substr(1));
    }
    void insertWord(string word){
        insertUtill(root,word);
    }

    bool SearchUtill(TrieNode* root, string word){
    //base case
    if(word.length()==0){
        return root->isTerminal;
    }
    int index=word[0]-'A';
    TrieNode* child;

    //present
    if(root->children[index]!=NULL){
        child=root->children[index];
    }
    else{
        return false;
    }
    //recursion
    return SearchUtill(child,word.substr(1));
}
bool SearchWord(string word){
    return SearchUtill(root,word);
}
};


int main(){

    Trie * t=new Trie();
    t->insertWord("ARM");
    t->insertWord("AMAN");
    t->insertWord("DUBEY");

    cout<<"Present or not "<<t->SearchWord("AMA")<<endl;

    return 0;
}