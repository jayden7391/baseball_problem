#include<iostream>
#include<string>

using namespace std;

typedef struct{
    string name;
    int win;
    int lose;
    int draw;
    double winrat;
}Team;

typedef struct{
    string teamname1;
    string teamname2;
}Match;

int main(void){

    int TestCase = 0;

    cin >> TestCase;
    
    Team teams = new Team[8];
    
    for(int i=0; i<8; i++){
        string line;
        cin >> line;
        string token;
        string delimiter = " ";
        size_t pos = 0;
        int j = 0;
        while ((pos = line.find(delimiter)) != std::string::npos) {
            token = line.substr(0, pos);
            line.erase(0, pos + delimiter.length());
            switch(j){
                case 0:
                    teams[i].name = token;
                    break;
                case 1:
                    istringstream(token) >> teams[i].win;
                    break;
                case 2:
                    istringstream(token) >> teams[i].draw;
                    break;
                default:
                    break;
            }
            j ++;
        }
        istringstream(line) >> teams[i].lose;
    }
    
    string mytime;
    cin >> mytime;
    
    int remainmatch;
    cin >> remainmatch;
    Match matchs = new Match[remainmatch];
    for(int i=0; i<remainmatch; i++){
        string line;
        cin >> line;
        string token;
        string delimiter = " ";
        size_t pos = 0;
        int j = 0;
        while((pos = line.fine(delimiter)) != std::string::npos){
            token line.substr(0,pos);
            line.erase(0, pos + delimiter.length());
            matchs[i].teamname1 = token;
        }
        matchs[i].teamname2 = line;
    }

    for(int i=0; i<remainmatch; i++){

        
        
        /*
        if(matchs[i].teamname1.compare(mytime) == 0){
            for(int j=0; j<8; j++){
                if(teams[j].name.compare(matchs[i].teamname1) == 0 ){
                    teams[j].win ++;
                }
                else if(teams[j].name.compare(matchs[i].teamname2) == 0){
                        teams[j].lose ++;
                }
            }
        }
        else if(match[i].teamname2.compare(mytime) == 0){
             for(int j=0; j<8; j++){
                if(teams[j].name.compare(matchs[i].teamname1) == 0 ){
                    teams[j].lose ++;
                }
                else if(teams[j].name.compare(matchs[i].teamname2) == 0){
                        teams[j].win ++;
                }
            }
        }
        
        else{
            
        }
        */
    }
}
