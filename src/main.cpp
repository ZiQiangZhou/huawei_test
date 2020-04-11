#include <iostream>
#include <sstream>
#include <string>
#include <stdio.h>
#include <map>
#include <vector>
using namespace std;

struct Node
{
    unsigned long id;
    vector<unsigned long> children; // 用户i向外转账的所有人
    vector<unsigned long> parents;  // 向用户i转账的所有人
};

void read_data(map<unsigned long, Node>& all_data)
{
    string data_file = "../data/test_data.txt";
    freopen(data_file.c_str(), "r", stdin);

    unsigned long a,b,c;
    while(scanf("%u,%u,%u", &a,&b,&c) != EOF)
    {
        if(all_data.count(a) > 0)
        {
            all_data[a].children.push_back(b);
        }
        else
        {
            Node n;
            n.id = a;
            n.children.push_back(b);
            all_data[a] = n;
        }
        if(all_data.count(b) > 0)
        {
            all_data[b].parents.push_back(a);
        }
        else
        {
            Node n;
            n.id = b;
            n.parents.push_back(a);
            all_data[b] = n;
        }
    }
}
int main()
{
    map<unsigned long, Node> all_data;
    read_data(all_data);    
    // cout<<all_data.size()<<endl;
    

    fclose(stdin);
    return 0;
}