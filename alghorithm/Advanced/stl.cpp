#include "bits/stdc++.h"
using namespace std;
class tag{
    public :
    map<string, tag*> nes;
    map<string,bool> pre;
    map<string, string> attr;

    void extract_attr(stringstream &ss){
        string aux1,key="",val="";
        char ch;
        while(ss>>aux1){
            //cout<< aux1<<" ";
           // ss>>val;
            if(aux1 == "="){
                ss.ignore();
                continue;
            
            }
            if(key=="")
                key = aux1;
            else
                val = aux1;
            //ss>>val;
            if(val=="")
            {
                ss.ignore();
                continue;
            }    
            if(val[val.length()-1]=='>'){
                attr[key] = val.substr(1,val.length()-3);
//                cout<<key<<" "<<attr[key]<<endl;
                
                break;
            }
            else{
                attr[key] = val.substr(1,val.length()-2);
            
  //              cout<<key<<" "<<attr[key]<<endl;
                key=val="";
            }
            ss.ignore();
        }
    }
};

int main(){
    int n, q;
    cin>>n>>q;
    cin.ignore();
    string tagwa, aux;
    map<string, tag*> root;
    map<string,bool> pre;
    tag *obj;
    stack< pair<string,tag*> > name;
    int isObj=0;
    char ch;
    for(int i = 0; i < n; i++){
        getline(cin,tagwa);
        stringstream key(tagwa);
        key>>aux;
//        cout<<aux<<" ";
        
        if(aux[1]=='/'){
            aux = aux.substr(2,aux.length()-3);
//            cout<<aux<<" ";
            name.pop();
        }else{
            key.ignore();
            if(aux[aux.length()-1]=='>')
                aux = aux.substr(1,aux.length()-2);
            else
                aux = aux.substr(1);
//            cout<<aux<<" ";
            if(name.empty()){
                pre[aux] = true;
                obj = new tag();
                root[aux] = obj;
                name.push(make_pair(aux, obj));
                obj->extract_attr(key);
            }else{
//                cout<<aux<<" "<<name.top().first<<"\n";
                obj = name.top().second;
                obj->nes[aux] = new tag();
                name.push(make_pair(aux, obj->nes[aux]));
                obj->pre[aux] = true;
                obj->nes[aux]->extract_attr(key);
            }

        }
    }
    while(q--){
        cin>>tagwa;
        aux="";
        int flag=0,i;
        for( i=0;i<tagwa.length();i++){
            if(tagwa[i]=='.'|| tagwa[i]=='~'){ 
//               cout<<pre[aux]<<" ";
                ch = tagwa[i];
                if(flag || pre[aux]){
                    if(flag){
//                        cout<<obj->pre[aux]<<" ";
                        if(obj->pre[aux]){
                            obj = obj->nes[aux];
                        }else
                            break;
                    }else{
                        flag=1;
                        obj = root[aux];
                    }
                }else
                    break;
                aux="";
            }else
                aux+=tagwa[i];
        }
        if(aux!="" && i == tagwa.length()){
            if( ch =='.' || obj->attr[aux]== "")
                puts("Not Found!");
            else
                cout<<obj->attr[aux]<<endl;
        }else
            puts("Not Found!");
    }

    return 0;
}
