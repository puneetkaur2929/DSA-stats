class Node{
    public:
    char data;
    unordered_map<char,Node*>m;
   
    bool isterminal;
    Node(char d){
        data=d;
        isterminal=false;
    }
};
class Trie{
    Node* root;
     unordered_set<string>s;
    public:
    Trie(){
        root=new Node('/');
    }
    void ins(string word){
        Node* temp=root;
        for(int i=1;i<word.length();i++){
            if(temp->m.count(word[i])==0){
                Node*n=new Node(word[i]);
                temp->m[word[i]]=n;
                 temp=temp->m[word[i]];
            }
            else{
                
                if(temp->m[word[i]]->isterminal==true && word[i+1]=='/'){
                    temp=temp->m[word[i]];
                    i=word.length();
                    
                }
                else{
                    temp=temp->m[word[i]];
                }
                
                
            }
           
        }
        if(temp->isterminal==false){
            temp->isterminal=true;
            // cout<<word<<endl;
            s.insert(word);
        }
        
    }
    void res(vector<string>&ans){
        Node*temp2=root;
       
       auto it=s.begin();
        while(it!=s.end()){
            ans.push_back(*it);
            it++;
        }
    }
    
};
class Solution {
public:
    vector<string> removeSubfolders(vector<string>& folder) {
        sort(folder.begin(),folder.end());
        vector<string>ans;
          Trie obj;
        for(int i=0;i<folder.size();i++){
          obj.ins(folder[i]);
            
        }
    obj.res(ans);
        return ans;
        
    }
};