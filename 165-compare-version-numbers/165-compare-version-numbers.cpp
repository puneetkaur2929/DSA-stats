class Solution {
public:
    int compareVersion(string version1, string version2) {
        stringstream s1(version1);
        stringstream s2(version2);
        string tok1,tok2;
        if(version1.length()>=version2.length()){
            vector<int>v1;

             while(getline(s1,tok1,'.')){
            v1.push_back(stoi(tok1));
        }
            int i=0;
            while(getline(s2,tok2,'.') && i<v1.size()){
                if(v1[i]<stoi(tok2)){
                    return -1;
                }
                if(v1[i]>stoi(tok2)){
                    return 1;
                }
                i++;
                
            }
            if(i!=v1.size()){
            while(i<v1.size()){
               if( v1[i]>0 ){
                  return 1;
               }
            i++;
            }
          
        }
        }
       else{
           vector<int>v2;
            while(getline(s2,tok2,'.')){
            v2.push_back(stoi(tok2));
        }
           
            int i=0;
            while(getline(s1,tok1,'.') && i<v2.size()){
                if(v2[i]<stoi(tok1)){
                    return 1;
                }
                if(v2[i]>stoi(tok1)){
                    return -1;
                }
                i++;
                
            }
              if(i!=v2.size()){
            while(i<v2.size()){
               if( v2[i]>0 ){
                  return -1;
               }
            i++;
            }
          
        }
       }
       
        return 0;
       
    }
};