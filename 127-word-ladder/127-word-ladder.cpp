class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
           unordered_set<string>s;
        for(auto st: wordList){
            s.insert(st);
        }
        if(s.find(endWord)==s.end()){
            return 0;
        }
        queue<pair<string,int>>q;
        q.push({beginWord,1});
        while(!q.empty()){
            string fs=q.front().first;
            int count=q.front().second;
            q.pop();
            if(fs==endWord){
                return count;
            }
            s.erase(fs);
            for(int i=0;i<fs.size();i++){
                char rep=fs[i];
                for(int k=0;k<26;k++){
                    fs[i]='a'+k;
                    if(s.find(fs)!=s.end()){
                        q.push({fs,count+1});
                    }
                }
                fs[i]=rep;
            }
        }
        return 0;
    }
};