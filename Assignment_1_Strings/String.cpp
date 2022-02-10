#include <iostream>
#include <vector>
#include <map>
#include <sstream>

using namespace std;

void line_handles (string line , map<string,int>&m);
void printOutput  (map<string,int>&m);

int main() {
    
    //freopen("/Desktop/assignement_1_Strings/input.txt", "r", stdin);
    
    string line;
    stringstream ss;
    int testCases ;
    getline(cin,line);
    ss.str(line);
    
    ss >> testCases ;
    
    vector<int>sizes(testCases);

    map <string ,int > m ;
    
    
    int i = 0 ;
    
    while(ss >> sizes[i]){
        
    
        for (int j = 0 ; j < sizes[i] ; j ++){
            getline(cin,line);
            line_handles(line,m);
        }
        
   
        for(auto it = m.begin(); it != m.end() ; it++ ){
            string ext = it->first;
            if(ext == "mp3"|| ext == "aac" || ext == "flac" ){
                m["music"] += m[ext];
            }
            else if(ext == "jpg"|| ext == "bmp" || ext == "gif" ){
                m["images"] += m[ext];
            }
            else if (ext == "mp4"|| ext == "mkv" || ext == "avi" ){
                m["movies"] += m[ext];
            }
            else if(ext !="music" && ext !="images" && ext !="movies" && ext !="other"){
                m["other"] += m[ext];
            }
        }
        printOutput(m);
        m.clear();
        
        i++;
    }
}


void line_handles (string input, map<string,int> &m){
    
    stringstream ss(input);
    string line ,string_size ;
    int int_size ;
    getline(ss, line);

    size_t idx = line.find(".") , lastDotidx= idx ;

    while(idx !=string::npos){
        idx = line.find(".", idx+1);
        if(idx!=-1) lastDotidx = idx;
    }

    line = line.substr(lastDotidx);
    string extension {};
    
    int i = 1;
    while(line[i]!=' '){
        extension += line[i];
        i++;
    }
    
    
    while(line[i] != 'b' && i < line.size()){
        string_size += line[i];
        i++;
    }
    int_size = stoi(string_size);
    m[extension] += int_size ;
    
}

void printOutput(map<string,int>&m){
    cout<<"music "<< m["music"] << "b "<< "images " << m["images"]<<"b "<<"movies "<<m["movies"]<< "b "<<"other "<<m["other"]<<"b"<<endl;
}