
#include<bits/stdc++.h>
using namespace std;
 int users;

 vector<int>connection[15];

int user_in=0;


 class user
 {
     int uid;
    string name ;
    int Nfriends;
public :
    user()
    {user_in++;
        cout<<"enter user name for user id "<<user_in<<" ";
        cin>>name;
        uid =user_in;
    }
int* level_friend()
{
    queue<int> q;
    bool visted[users+1];
    int *relation=new int[users+1];
    //cout<<"arr dec";
    visted[this->user::uid]=true;
    //cout<<"first true";
    relation[this->user::uid]=0;
    //cout<<"first dec";
    q.push(this->user::uid);
   // cout<<"while";
    while(!q.empty())
    {
        int s=q.front();
        q.pop();
        for (auto u :connection[s])
        {
          if (visted[u])continue;
            visted[u]=true;
            relation[u]=relation[s]+1;
            q.push(u);
        }
    }
    /*for(int i=1; i<=users;i++)
    {
        cout<<i<<"  "<<relation[i]<<"\n";
    }*///cout<<"work done";
   return relation;

}
string retname()
{
    return name ;
}
 };
 //vector<pair<int,int>>connection2;



 int main()
 {
     user *account[users];
     cout<<"Enter the no of user in network \n";
     cin>>users;
     int connection2[users][users];
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
        //connection.push_back({a,b});
        //connection.push_back({b,a});
        connection[a].push_back(b);
        connection[b].push_back(a);
        //cout<<"add more Y/N ";
        //cin>>ch;
    }



    /*for(auto x:connection[1])
    {
        cout<<x<<"\n";
    }*/
/*for(int i=0;i<users;i++)
{
    connection2[i][i]=0;
}*/
cout<<"\nABOVE RELATION WILL LOOK LIKE IN FORM OF MATRIX\n";
cout<<"  ";
for(int i=0;i<users;i++)
    cout<<i+1<<" ";
for(int i=0;i<users;i++)
{
    cout<<"\n";
    cout<<i+1<<" ";
    for(int j=0;j<users;j++)
    cout<<connection2[i][j]<<" ";;

}
//cout<<account[1]->retname();

ch='y';
while(ch=='y')
{
cout<<"\n Enter the user id to obtain all level for friend connection ";
cin>>a;
int* rel;
rel=account[a-1]->level_friend();
//cout<<"fun works";

for(int i=1; i<=users;i++)
    {//cout<<"in loop";
        cout<<account[i-1]->retname()<<" --> "<<rel[i]<<"\n";
    }
cout<<"try again y/n ";
cin>>ch;
 }


return 0;
 }
