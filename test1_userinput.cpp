#include <bits/stdc++.h>
using namespace std;
int users = 10;
#define m 10

vector<int> connection[20];

int user_in = 0;

class user
{
    int uid;
    char name[20];
    int Nfriends;

public:
    user()
    {
        user_in++;
        cout << "enter user name for user id " << user_in << " ";
        cin >> name;
        uid = user_in;
    }
    void level_friend(int relation[])
    {
        queue<int> q;
        bool visted[users + 1];
        for (int i = 0; i < users + 1; i++)
            visted[i] = false;
        visted[this->user::uid] = true;
        relation[this->user::uid] = 0;
        q.push(this->user::uid);

        while (!q.empty())
        {
            int s = q.front();
            //cout<<s<<"==";
            q.pop();
            for (auto u : connection[s])
            {
                if (visted[u])
                    continue;
                visted[u] = true;
                relation[u] = relation[s] + 1;
                //cout<<u<<" ";
                q.push(u);
            }
        }
        return;
    }
    void level_one(int relation[])
    {
        int s = this->user::uid;
        for (auto u : connection[s])
        {
            relation[u] = relation[s] + 1;
            //cout<<relation[u]<<" ";
        }

        return;
    }
    char *retname()
    {
        return name;
    }
    int retuid()
    {
        return uid;
    }
};
void printcnt()
{

    for (int i = 1; i < users + 1; i++)
    {

        cout << "connection of uid "
             << i << ": ";

        for (auto it = connection[i].begin();
             it != connection[i].end(); it++)
        {

            cout << *it << ' ';
        }
        cout << endl;
    }
}

void minimumrelation(int mat[][m])
{
    int rell[users][users];
    for (int i = 0; i < users; i++)
    {
        for (int j = 0; j < users; j++)
        {
            if (i == j)
            {
                rell[i][j] = 0;
            }
            else if (mat[i][j] == 1)
            {
                rell[i][j] = mat[i][j];
            }
            else
                rell[i][j] = 10000;
        }
    }
    for (int k = 0; k < users; k++)
    {
        for (int i = 0; i < users; i++)
        {
            for (int j = 0; j < users; j++)
            {
                rell[i][j] = min(rell[i][j], rell[i][k] + rell[k][j]);
            }
        }
    }
    cout << "\nABOVE RELATION WILL LOOK LIKE IN FORM OF MATRIX\n";
    cout << "   ";
    for (int i = 0; i < users; i++)
        cout << i + 1 << " ";
    for (int i = 0; i < users; i++)
    {
        cout << "\n";
        cout << i + 1 << "  ";
        for (int j = 0; j < users; j++)
            cout << rell[i][j] << " ";
        ;
    }
}

void printAllPathsUtil(int u, int d, bool visited[],
                       int path[], int &path_index)
{
    visited[u] = true;
    path[path_index] = u;
    path_index++;

    if (u == d)
    {
        for (int i = 0; i < path_index; i++)
            cout << path[i] << " ";
        cout << endl;
    }
    else
    {

        //list<int>::iterator i;
        for (auto i = connection[u].begin(); i != connection[u].end(); ++i)
            if (!visited[*i])
                printAllPathsUtil(*i, d, visited, path, path_index);
    }
    path_index--;
    visited[u] = false;
}
void printAllPaths(int s, int d)
{
    bool *visited = new bool[users + 1];
    int *path = new int[users + 1];
    int path_index = 0;
    for (int i = 0; i < users + 1; i++)
        visited[i] = false;
    printAllPathsUtil(s, d, visited, path, path_index);
}
void commonfriend(int s, int d, int relation[])
{
    for (auto it = connection[s].begin(); it != connection[s].end(); it++)
    {
        for (auto ti = connection[d].begin(); ti != connection[d].end(); ti++)
        {
            if (*it == *ti)
            {
                // cout<<*ti;
                relation[*it] = 1;
            }
        }
    }
}

int main()
{
    user *account[users];
    cout << "Enter the no of user in network \n";
    cin >> users;
    int connection2[m][m];
    memset(connection2, 0, sizeof(connection2));

    for (int i = 0; i < users; i++)
    {
        account[i] = new user;
    }
    int a, b;
    char ch = 'y';
    cout << "enter the connection list ,as  user id A  user id B  and Y/n for add more\n";
    while (ch == 'y' || ch == 'Y')
    {
        cout << "ADD connection  ";
        cin >> a >> b >> ch;
        connection2[a - 1][b - 1] = connection2[b - 1][a - 1] = 1;
        connection[a].push_back(b);
        connection[b].push_back(a);
    }

    printcnt();
    cout << "\nABOVE RELATION WILL LOOK LIKE IN FORM OF MATRIX\n";
    cout << "   ";
    for (int i = 0; i < users; i++)
        cout << i + 1 << " ";
    for (int i = 0; i < users; i++)
    {
        cout << "\n";
        cout << i + 1 << "  ";
        for (int j = 0; j < users; j++)
            cout << connection2[i][j] << " ";
        ;
    }

    int c;
    while (1)
    {
        cout << "\nenter your choice\n";
        cout << "1.To obtain all level for friend connection\n";
        cout << "2.To Find all the mutual friends between two people in the network\n";
        cout << "3.To Find the connection links between two people in the network\n";
        cout << "4.To Find the friends of a person in the network\n";
        cout << "5.To Find minimum relation matrix\n";
        cout << "6.EXIT\n";
        cin >> c;

        switch (c)
        {

        case 1:
        {
            cout << "\n Enter the user id to obtain all level for friend connection ";
            cin >> a;
            int rel[users];
            account[a - 1]->level_friend(rel);
            for (int i = 1; i <= users; i++)
            {
                cout << i << " " << account[i - 1]->retname() << " --> " << rel[i] << "\n";
            }
            break;
        }
        case 2:
        {
            cout << "enter the uid of users \n";
            cin >> a >> b;
            int rel[users];
            memset(rel, 0, sizeof(rel));
            commonfriend(a, b, rel);
            for (int i = 1; i <= users - 1; i++)
            {
                if (rel[i])
                    cout << i << " " << account[i - 1]->retname() << "\n";
            }

            break;
        }
        case 3:
        {
            cout << "enter the uid of users \n";
            cin >> a >> b;
            printAllPaths(a, b);
            break;
        }
        case 4:
        {
            cout << "\n Enter the user id ";
            cin >> a;
            int rel[users];
            memset(rel, 0, sizeof(rel));
            account[a - 1]->level_one(rel);
            for (int i = 1; i <= users - 1; i++)
            {
                if (rel[i])
                    cout << i << " " << account[i - 1]->retname() << "\n";
            }
            break;
        }
        case 5:
        {
            minimumrelation(connection2);
            break;
        }
        case 6:
        {
            exit(1);
        }
        default:
            cout << "\nInvalid type! \n";
        }
    }

    return 0;
}
