#include<iostream>
#include<string>
#include<sstream>

using namespace std;

typedef struct{
    string name;
    int win;
    int lose;
    int draw;
    int rank;
    double winrate;
    int myteam;
}Team;

typedef struct{
    string teamname1;
    string teamname2;
}Match;

int Ranking(Team* teams){
    
    int myt;

    for(int i=0; i<8; i++){
        if(teams[i].win + teams[i].lose+teams[i].draw == 0)
            teams[i].winrate = 0;
        else
            teams[i]. winrate = (double)teams[i].win / ((double)teams[i].win + (double)teams[i].lose + (double)teams[i].draw);
    }
    Team temp;
    int check = 0;
    int n = 7;
    for(int i = 1; i<8; i++){
        check = 0;
        for(int j=0; j<8-i; j++){
            if(teams[j].winrate < teams[j+1].winrate){
                temp = teams[j];
                teams[j] = teams[j+1];
                teams[j+1] = temp;
                check = 1;
            }
            else if(teams[j].winrate == teams[j+1].winrate && teams[j+1].myteam == 1){
                temp = teams[j];
                teams[j] = teams[j+1];
                teams[j+1] = temp;
                check = 1;
            }
        }
    }
    for(int i=0; i<8; i++){
        teams[i].rank = i+1;
        if(teams[i].myteam == 1)
            myt = i;
    }
    return myt;
}

int main(void){

    int TestCase = 0;

    cin >> TestCase;
    
    for(int t = 0; t<TestCase; t++){
        Team* teams = new Team[8];
    
        for(int i=0; i<8; i++){
            string line;
            cin >> teams[i].name;
            cin >> teams[i].win;
            cin >> teams[i].draw;
            cin >> teams[i].lose;
        }

        string myteam;
        cin >> myteam;
        int myt;

        for(int i=0; i<8; i++){
            if(teams[i].name.compare(myteam) == 0){
                teams[i].myteam = 1;
            }
            else
                teams[i].myteam = 0;
        }

        myt = Ranking(teams);

        int remainmatch;
        cin >> remainmatch;
        Match* matchs = new Match[remainmatch];
        for(int i=0; i<remainmatch; i++){
            cin >> matchs[i].teamname1;
            cin >> matchs[i].teamname2;
        }
        int t1;
        int t2;

        for(int i=0; i<remainmatch; i++){   
            for(int j=0; j<8; j++){
                if(matchs[i].teamname1.compare(teams[j].name) == 0)
                    t1 = j;
                else if(matchs[i].teamname2.compare(teams[j].name) == 0)
                    t2 = j;
            }

            if(teams[t1].myteam == 1){
                teams[t1].win ++;
                teams[t2].lose ++;
            }
            else if(teams[t2].myteam == 1){
                teams[t2].win ++;
                teams[t1].lose ++;
            }
            
            else{
                teams[t1].draw ++;
                teams[t2].draw ++;
            }
        
            myt = Ranking(teams);

        }
        if(myt < 4)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }

    return 0;
}
