class Solution {
public:
    int compareVersion(string version1, string version2) {
        stringstream s1(version1);
        stringstream s2(version2);
        string tok1,tok2;
        vector<int>v1;
        vector<int>v2;
        while(getline(s1,tok1,'.')){
            v1.push_back(stoi(tok1));
        }
        while(getline(s2,tok2,'.')){
            v2.push_back(stoi(tok2));
        }
       int i=0;
        int j=0;
        int c1=0;
        int c2=0;
        while(i<v1.size() && j<v2.size()) {
           if(v1[i]<v2[j]){
               return -1;
           }
            else if(v1[i]>v2[j]){
                return 1;
            }
            i++;
            j++;
        }
       
        if(i!=v1.size()){
            while(i<v1.size()){
               if( v1[i]>0 ){
                  return 1;
               }
            i++;
            }
          
        }
         if(j!=v2.size()){
           while(j<v2.size()){
                if( v2[j]>0 ){
                 return -1;
               }
            j++;
           }
              
        }
        return 0;
       
    }
};