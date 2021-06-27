#include<bits/stdc++.h>
using namespace std;
 int users=10;
 #define m 10

vector<int>connection[20];

int user_in=0;


 class user
 {
     int uid;
    char name[20] ;
    int Nfriends;
public :
    user()
    {user_in++;
        cout<<"enter user name for user id "<<user_in<<" ";
        cin>>name;
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
void printmatrix(int mat[][m])
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
     cout<<"Enter the no of user in network \n";
     cin>>users;
     int connection2[m][m];
     memset(connection2, 0, sizeof(connection2));


     for(int i=0;i<users;i++)
     {
        account[i]=new user;
     }
     int a ,b ;
     char ch='y';
    cout<<"enter the connection list ,as  user id A  user id B  and Y/n for add more\n";
    while(ch=='y'||ch=='Y')
    {
        cout<<"ADD connection  ";
        cin>>a>>b>>ch;
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
