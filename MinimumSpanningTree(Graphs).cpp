#include <iostream>
#include <algorithm>
#include <bits/stdc++.h>
using namespace std;

class Edge{
    public:
    int source;
    int destination;
    int weight;
};
bool myEdge(const Edge a, const Edge b)
{
    return a.weight < b.weight;
}
int findparent(int e,int *parent)
{
    if(e==parent[e])
        return e;
    else return findparent(parent[e],parent);
}
int main()
{
  int V, E;
  cin >> V >> E;
    Edge *input = new Edge[E];
    Edge *output = new Edge[V-1];
    for(int i = 0 ; i < E ; i++)
    {
        int s,d,w;
        cin >> s;
        cin >> d;
        cin >> w;
        input[i].source = s;
        input[i].destination = d;
        input[i].weight = w;
    }
    /*
    PERFORM SORTING HERE AFTER UNDERSTANDING COMPARATOR
    */
    sort(input,input+E,myEdge);
   /*
   for(int i = 0 ; i < V ; i++)
    {
        cout << input[i].source<<" ";
        cout << input[i].destination<<" ";
        cout << input[i].weight<<endl;
        
    }
    */
    int *parent_value = new int[V];
    for(int i = 0 ; i < V ; i++)
    {
        parent_value[i] = i;
    }
    int count_output = 0 ;
    int k = 0;
    while(count_output < V-1)
    {
        int source = input[k].source;
        int destination = input[k].destination;
        int weight = input[k].weight;
        int source_parent = findparent(source,parent_value);
        int destination_parent = findparent(destination,parent_value);
        if(destination_parent != source_parent)
        {
            output[count_output].source = (source<destination)?source:destination;
            output[count_output].destination = (source>destination)?source:destination;
            output[count_output].weight = weight;
            count_output++;
            parent_value[source_parent] = parent_value[destination_parent];
        }
        k++;
    }
    for(int i = 0 ; i < V-1 ; i++)
    {
        cout << output[i].source<<" ";
        cout << output[i].destination<<" ";
        cout << output[i].weight<<endl;
    }
  return 0;
}
