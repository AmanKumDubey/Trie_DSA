#include<iostream>
using namespace std;

// This program's Searching Word in Trie

class TrieNode{

    public:
    char data;
    TrieNode* childern[26];
    bool isTerminal;

    TrieNode(char ch){
        this->data=ch;
        this->isTerminal=false;
        for(int i=0;i<26;i++){
            childern[i]=NULL;
        }
    }
};
class Trie{
    public:
    TrieNode * root=new TrieNode('\0');
    void insertWordUtill(TrieNode* root, string word){
        //base case
        if(word.length()==0){
            root->isTerminal=true;
            return;
        }
        int index=word[0]-'A';
        TrieNode* child;

        if(root->childern[index]!=NULL){
            child=root->childern[index];
        }
        else{
            child=new TrieNode(word[0]);
            root->childern[index]=child;
        }
        insertWordUtill(child,word.substr(1));
    }
    void insertWord(string word){
        insertWordUtill(root,word);
    }

    bool SerchUtill(TrieNode* root, string word){

        if(word.length()==0){
            return root->isTerminal;
        }
        int index=word[0]-'A';
        TrieNode* child;

        if(root->childern[index]!=NULL){
            child=root->childern[index];
        }
        else{
            return false;
        }
       return  SerchUtill(child,word.substr(1));
    }
    bool SearchWord(string word){
       return  SerchUtill(root,word);
    }
};
int main(){

    Trie * t=new Trie();
    t->insertWord("AMAN");
    t->insertWord("DUBEY");

    cout<<"The word is persent or not :: "<<t->SearchWord("AMA")<<endl;

    return 0;
}