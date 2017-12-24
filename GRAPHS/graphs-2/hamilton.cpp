#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;
vector<int> procedure_1(vector< vector<int> > graph, vector<int> path);
vector<int> procedure_2(vector< vector<int> > graph, vector<int> path);
vector<int> procedure_2b(vector< vector<int> > graph, vector<int> path);
vector<int> procedure_2c(vector< vector<int> > graph, vector<int> path);
vector<int> procedure_3(vector< vector<int> > graph, vector<int> path);
vector<int> sort(vector<vector<int> > graph);
vector<vector<int> >
            reindex(vector<vector<int> > graph, vector<int> index);
ifstream infile ("graph.txt");     //Input file
ofstream outfile("paths.txt");     //Output file
int main()
{
 int i, j, k, n, vertex, edge;
 infile>>n;                        //Read number of vertices
 vector< vector<int> > graph;       //Read adjacency matrix of graph
 for(i=0; i<n; i++)
 {
  vector<int> row;
  for(j=0; j<n; j++)
  {
   infile>>edge;
   row.push_back(edge);
  }
  graph.push_back(row);
 }

 vector<int> index=sort(graph);
 graph=reindex(graph,index);

 for(vertex=0; vertex<n; vertex++)  //Loop through all vertices
 {
  vector<int> path;
  path.push_back(vertex);           //Select initial vertex
  path=procedure_1(graph,path);     //Part I
  path=procedure_2(graph,path);     //Part II
  k=path.size();
  if(k<n)   {path=procedure_2b(graph,path); k=path.size();}
  if(k<n)   {path=procedure_2c(graph,path); k=path.size();}
  if(k<n) outfile<<"Path("<<k<<"): ";
  else outfile<<"Hamiltonian Tour: ";//Part III
  for(i=0; i<path.size(); i++) outfile<<index[path[i]]+1<<" ";
  outfile<<endl;
  if(k==n)
  {
   vector<int> circuit_maker=procedure_3(graph,path);
   if(!circuit_maker.empty())
   {
    for(j=0; j<circuit_maker.size(); j++)
    {
     outfile<<"Hamiltonian Circuit:\t";
     for(k=0; k<=circuit_maker[j]; k++)
      outfile<<index[path[k]]+1<<" ";
     for(k=n-1; k>circuit_maker[j]; k--)
      outfile<<index[path[k]]+1<<" ";
     outfile<<endl;
    }
   }
   outfile<<endl;
  }
 }
 cout<<"See paths.txt for results."<<endl;
  system("PAUSE");
  return 0;
}

vector<int> procedure_1(vector< vector<int> > graph, vector<int> path)
{
 int i, j, k, n=graph.size();
 vector<int> extended_path;
 vector<int> visited;
 for(i=0; i<n; i++)
  visited.push_back(0);
 int present;
 for(i=0; i<path.size(); i++)
 {
  present=path[i];
  visited[present]=1;
  extended_path.push_back(present);
 }
 for(k=0; k<n; k++)
 {
  vector<int> neighbor;
  for(i=0; i<n; i++)
   if(graph[present][i]==1 && visited[i]==0)
    neighbor.push_back(i);
   if(!neighbor.empty())
   {
    int choice=neighbor[0];
    int minimum=n;
    for(i=0; i<neighbor.size(); i++)
    {
     vector<int> next_neighbor;
     for(j=0; j<n; j++)
      if(graph[neighbor[i]][j]==1 && visited[j]==0)
       next_neighbor.push_back(j);
      int eta=next_neighbor.size();
      if(eta<minimum)
      {
       choice=neighbor[i];
       minimum=eta;
      }
    }
    present=choice;
    visited[present]=1;
    extended_path.push_back(present);
   }
   else break;
 }
 return extended_path;
}

vector<int> procedure_2(vector< vector<int> > graph, vector<int> path)
{
 int i, j, k, n=graph.size();
 bool quit=false;
 while(quit!=true)
 {
 int m=path.size(), inlet=-1, outlet=-1;
  vector<int> neighbor;
  for(i=0; i<path.size(); i++)
   if(graph[path[m-1]][path[i]]==1) neighbor.push_back(i);
   vector<int> unvisited;
   for(i=0; i<n; i++)
   {
    bool outside=true;
    for(j=0; j<path.size(); j++)
     if(i==path[j]) outside=false;
     if(outside==true) unvisited.push_back(i);
   }
   if((!unvisited.empty()) && (!neighbor.empty()))
   {
    int maximum=0;
    for(i=0; i<neighbor.size(); i++)
     for(j=0; j<unvisited.size(); j++)
      if(graph[path[neighbor[i]+1]][unvisited[j]]==1)
      {
       vector<int> next_neighbor;
       for(k=0; k<unvisited.size(); k++)
       if(graph[unvisited[j]][unvisited[k]]==1)
         next_neighbor.push_back(unvisited[k]);
       int eta=next_neighbor.size();
       if(eta>=maximum)
        {
         inlet=neighbor[i];
         outlet=unvisited[j];
         maximum=eta;
        }
      }
   }
   vector<int> extended_path;
   if(inlet!=-1 && outlet!=-1)
   {
    for(i=0; i<=inlet; i++)
     extended_path.push_back(path[i]);
    for(i=path.size()-1; i>inlet; i--)
     extended_path.push_back(path[i]);
    extended_path.push_back(outlet);
   }
   if(!extended_path.empty()) path=extended_path;
   if(m<path.size()) path=procedure_1(graph,path);
   else quit=true;
 }
 return path;
}

vector<int> procedure_2b(vector< vector<int> > graph, vector<int> path)
{
 int i, j, k, l, p, n=graph.size();
 bool quit=false;
 while(quit!=true)
 {
  vector<int> extended_path;
  int m=path.size();
  vector<int> unvisited;
  for(i=0; i<n; i++)
  {
    bool outside=true;
    for(j=0; j<path.size(); j++)
     if(i==path[j]) outside=false;
    if(outside==true) unvisited.push_back(i);
  }
  bool big_check=false;
  for(i=0; i<path.size(); i++)
  {
    for(j=0; j<unvisited.size(); j++)
    {
     if(graph[unvisited[j]][path[i]]==1)
     {
       vector<int> temp_path;
       temp_path.push_back(unvisited[j]);
       vector<int> temp_extended_path;
       vector<int> temp_visited;
       for(l=0; l<n; l++)
       temp_visited.push_back(0);
       int present;
       for(l=0; l<temp_path.size(); l++)
       {
       present=temp_path[l];
        temp_visited[present]=1;
        temp_extended_path.push_back(present);
       }
       for(l=0; l<n; l++)
       {
       bool unfound=true;
       for(k=0; k<unvisited.size(); k++)
        if(l==unvisited[k]) unfound=false;
       if(unfound==true) temp_visited[l]=1;
       }
       for(l=0; l<n; l++)
       {
        vector<int> neighbor;
       for(l=0; l<n; l++)
       if(graph[present][l]==1 && temp_visited[l]==0)
        neighbor.push_back(l);
       if(!neighbor.empty())
        {
         int choice=neighbor[0];
         int minimum=n;
         for(l=0; l<neighbor.size(); l++)
          {
           vector<int> next_neighbor;
          for(k=0; k<n; k++)
           if(graph[neighbor[l]][k]==1 && temp_visited[k]==0)
            next_neighbor.push_back(k);
           int eta=next_neighbor.size();
           if(eta<minimum)
            {
             choice=neighbor[l];
             minimum=eta;
            }
          }
          present=choice;
          temp_visited[present]=1;
         temp_extended_path.push_back(present);
        }
       else break;
     }
     int last_vertex=temp_extended_path[temp_extended_path.size()-1];
     int vj;
     bool check=false;
     while(check==false && !temp_extended_path.empty())
     {
     for(p=path.size()-2; p>i; p--)
     {
      if(graph[path[p]][last_vertex]==1
         && graph[path[i+1]][path[p+1]]==1)
      {
       check=true;
       vj=p;
       break;
      }
     }
     if(check==false)
     {
      temp_extended_path.pop_back();
      last_vertex=temp_extended_path[temp_extended_path.size()-1];
     }
     }
     if(check==true)
     {
      vector<int> temp;
      for(p=0; p<=i; p++)
      temp.push_back(path[p]);
      for(p=0; p<temp_extended_path.size(); p++)
      temp.push_back(temp_extended_path[p]);
      for(p=vj; p>i; p--)
      temp.push_back(path[p]);
      for(p=vj+1; p<path.size(); p++)
      temp.push_back(path[p]);
      temp_extended_path=temp;
      big_check=true;
      extended_path=temp_extended_path;
     }
     }
    }
     if(big_check==true)
     {
      break;
     }
  }
   if(!extended_path.empty()) path=extended_path;
   if(m<path.size())
   {
    path=procedure_1(graph,path);
    path=procedure_2(graph,path);
   }
   else quit=true;
 }
 return path;
}

vector<int> procedure_2c(vector< vector<int> > graph, vector<int> path)
{
  vector<int> reversed_path;
  for(int i=path.size()-1; i>=0; i--) reversed_path.push_back(path[i]);
  reversed_path=procedure_2b(graph,reversed_path);
  return reversed_path;
}

vector<int> procedure_3(vector< vector<int> > graph, vector<int> path)
{

 int i, n=path.size();

 vector<int> circuit_maker;
 for(i=0; i<n-1; i++)
  if((graph[path[0]][path[i+1]]==1) && (graph[path[i]][path[n-1]]==1))
   circuit_maker.push_back(i);
 return circuit_maker;
}

vector<int> sort(vector<vector<int> > graph)
{
 int i, j;
 vector<int> degree;
 for(i=0; i<graph.size(); i++)
 {
  int sum=0;
  for(j=0; j<graph[i].size(); j++)
  if(graph[i][j]==1) sum++;
  degree.push_back(sum);
 }
 vector<int> index;
 for(i=0; i<degree.size(); i++) index.push_back(i);
 for(i=0; i<degree.size(); i++)
 for(j=i+1; j<degree.size(); j++)
 if(degree[i]<degree[j]) swap(index[i],index[j]);
 return index;
}

vector<vector<int> >
      reindex(vector<vector<int> > graph, vector<int> index)
{
  int i, j;
  vector<vector<int> > temp=graph;
  for(i=0; i<temp.size(); i++)
  for(j=0; j<temp[i].size(); j++)
  temp[i][j]=graph[index[i]][index[j]];
  return temp;
}
