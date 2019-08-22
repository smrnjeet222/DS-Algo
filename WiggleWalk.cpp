/* https://codingcompetitions.withgoogle.com/kickstart/round/0000000000050ff2/0000000000150aac */
#include <iostream>
#include <cstring>

using namespace std;


int main(){
    int T;
    cin>>T;
    for (int q=1 ; q<=T ; q++){
        int n;
        cin>>n;
        
        int R,C;
     
        cin>>R>>C;

        int Sr,Sc;
        cin>>Sr>>Sc;

        int grid[R][C] ;
        for (int i=0 ;i<R ;i++){
            for(int j=0; j<C ;j++){
                grid[i][j]=0;
            }
        }


        char inst[n];     
        cin>>inst;

        int posr=Sr-1;
        int posc=Sc-1;
        grid[posr][posc]=1;
        
        for (int j=0;j<n;j++){
            if (inst[j]=='N'||inst[j]=='n'){
                posr--;
                while(true){
                    if (grid[posr][posc]==1)
                        posr--;
                    else{
                        grid[posr][posc]=1;
                        break;
                    }  
                }
               
            }

            if (inst[j]=='S'||inst[j]=='s'){
                posr++;
                while(true){
                    if (grid[posr][posc]==1)
                        posr++;
                    else{
                        grid[posr][posc]=1;
                        break;
                    }  
                    
                }
            }

            if (inst[j]=='W'||inst[j]=='w'){
                posc--;
                while(true){
                    if (grid[posr][posc]==1)
                        posc--;
                        else{
                        grid[posr][posc]=1;
                        break;
                    }  
                }
            }

            if (inst[j]=='E'||inst[j]=='e'){
                posc++;
                while(true){
                    if (grid[posr][posc]==1)
                        posc++;
                    else{
                        grid[posr][posc]=1;
                        break;
                    }  
                }
            }
        }

    cout<<"CASE #"<<q<<": "<<posr+1<<" "<<posc+1<<endl;

    }


return 0;
}