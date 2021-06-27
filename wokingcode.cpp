#include<bits/stdc++.h>
using namespace std;
#define users 10

vector<int>connection[20];

int user_in=0;


 class user
 {
     int uid;
    char name[20] ;
    int Nfriends;
public :
    user( char *names)
    {user_in++;

        strcpy(name,names);
        uid =user_in;
    }
void   level_friend(int relation[])
{
    queue<int> q;
    bool visted[users+1];
    for(int i = 0; i < users+1; i++)
        visted[i] = false;
       visted[this->user::uid]=true;
    relation[this->user::uid]=0;
    q.push(this->user::uid);

    while(!q.empty())
    {
        int s=q.front();
        //cout<<s<<"==";
        q.pop();
        for (auto u :connection[s])
        {
          if (visted[u])continue;
            visted[u]=true;
            relation[u]=relation[s]+1;
            //cout<<u<<" ";
            q.push(u);
        }
    }
   return ;

}
char *  retname()
{
    return name ;
}
int retuid()
{
    return uid;
}
 };
 void printcnt()
{

    for (int i = 1; i < users+1; i++) {

        cout << "connection of uid "
             << i << ": ";


        for (auto it = connection[i].begin();
             it != connection[i].end(); it++) {

            cout << *it << ' ';
        }
        cout << endl;
    }
}
void printmatrix(int mat[][users])
{cout<<"\nABOVE RELATION WILL LOOK LIKE IN FORM OF MATRIX\n";
cout<<"   ";
for(int i=0;i<users;i++)
    cout<<i+1<<" ";
for(int i=0;i<users;i++)
{
    cout<<"\n";
    cout<<i+1<<"  ";
    for(int j=0;j<users;j++)
    cout<<mat[i][j]<<" ";;

}
}

 int main()
 {
     user *account[users];
     cout<<"the no of user in network ="<<users<<"\n";
     int connection2[users][users];
     memset(connection2, 0, sizeof(connection2));

     char names[15][10]={"pairsh","rohit","aman","nikhil","divyan","navi","aniket","shagun","sanskar","agni"};
     vector<pair<int,int>> net={{1,2},{1,3},{1,6},{2,4},{2,6},{3,5},{4,8},{5,8},{6,10},{7,10},{8,9},{10,9}};
     for(int i=0;i<users;i++)
     {
        account[i]=new user(names[i]);
     }
     int a ,b ;
     char ch='y';

        for(int i=0;i<12;i++){
                a=net[i].first; b=net[i].second;
        connection2[a-1][b-1]=connection2[b-1][a-1]=1;
        connection[a].push_back(b);
        connection[b].push_back(a);
   }
   printcnt();
   printmatrix(connection2);






ch='y';
while(ch=='y')
{
cout<<"\n Enter the user id to obtain all level for friend connection ";
cin>>a;
int rel[users];
//cout<<account[a-1]->retname()<<" "<<account[a-1]->retuid()<<"\n ";
account[a-1]->level_friend(rel);


for(int i=1; i<=users;i++)
    {
        cout<<i<<" "<<account[i-1]->retname()<<" --> "<<rel[i]<<"\n";
    }
cout<<"try again y/n ";
cin>>ch;
 }


return 0;
 }
