class Node{
    public:
    char data;
    unordered_map<char,Node*>m;
    bool isterminal ;
    Node(char d){
        data=d;
        isterminal=false;
    }
    
};
class WordDictionary {
public:
    Node* root;
    WordDictionary() {
        root=new Node('\0');
        
    }
    void addWord(string word){
        Node* temp=root;
        
        for(int i=0;i<word.size();i++){
            char c=word[i];
            if(temp->m[c]){
               temp=temp->m[c];
            }
            else{
                Node* n= new Node(c);
                temp->m[c]=n;
                temp=n;
            }
             
            
        }
        temp->isterminal=true;
    }
        bool helper(string word, Node* curr){
        int n= word.size();
        
        for(int i=0; i<n; i++){
            char ch= word[i];
            
            if(ch=='.'){
                for(char ch='a'; ch<='z'; ch++){
                    if(curr->m[ch]){
                        if(helper(word.substr(i+1), curr->m[ch]))
                            return true;
                    }
                }
                return false;
            }
            else{
                if(curr->m[ch]==NULL)
                    return false;
                curr= curr->m[ch];
            }
        }

            return curr && curr->isterminal==true?true:false;
        }
     
    
    bool search(string word) {
      return  helper(word,root);
       
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */