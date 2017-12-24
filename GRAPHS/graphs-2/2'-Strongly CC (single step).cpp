#include <fstream>
#include <iostream>
#include <cmath>
using namespace std;
int **adj, size;

struct vert
{
    int ind, pred, num;

    vert()
    {
        num = 0;
    }
};
vert **a;

class stack
{
public:
    int size;
    vert **elements;
    int top;
    void push(vert*);
    vert* pop();
    stack();
};

stack::stack()
{
    size = 50;
    top = -1;
    elements = new vert*[size];
}

void stack::push(vert* k)
{
    if (top == size - 1)
        cout << "stack full";
    else
        elements[++top] = k;
}

vert* stack::pop()
{
    if (top == -1)
    {
        cout << "the stack is empty";
    }
    else
        return (elements[top--]);
}

bool search(int x, int a[], int size)
{
    for (int i = 0; i < size; i++)
    {
        if (a[i] == x)
            return true;
    }
    return false;
}
stack s;
int x=1, *comp, compsize = 0;

void strongc(vert* v)
{
    v->pred = v->num = x++;
    s.push(v);
    for (int i=0; i<size; i++)
    {
        if (adj[v->ind][i] > 0)
        {
            int is = 0;
            for (int j = 0; j <= s.top; j++)
            {
                if (s.elements[j]->ind == i)
                {
                    is = 1;
                    break;
                }
            }
            if (a[i]->num == 0)
            {
                strongc(a[i]);
                v->pred = min(v->pred, a[i]->pred);
            }
            else if (v->num > a[i]->num && is == 1)
                v->pred = min(v->pred, a[i]->num);
        }
    }
    if (v->pred==v->num)
    {
        vert* w;
        w = s.pop();
        while (v->ind != w->ind)
        {
            cout<<w->ind<<" "<<flush;
            comp[compsize++]=w->ind;
            w=s.pop();
        }
        cout<<w->ind<<flush<<endl;
        comp[compsize++]=w->ind;
    }
}

int main()
{
    cout << "enter the number of vertices : ";
    cin >> size;
    comp = new int[size];
    adj = new int* [size];
    a = new vert* [size];
//    ifstream fin;
//    fin.open("jk");
    for (int i = 0; i < size; i++)
    {
        a[i] = new vert;
        a[i]->ind = i;
        adj[i] = new int[size];
        for (int j = 0; j < size; j++)
        {
            adj[i][j] = 0;
        }
    }
    for (int i = 0; i < size; i++)
    {
        cout<<"enter the adjecent vertices of vertex "<<i<<" followed by -1 : ";
        int k;
        cin>>k;
//        fin >> k;
        while (k != -1 && k < size)
        {
            adj[i][k] = 1;
            cin>>k;
//            fin >> k;
        }
    }
    cout<<"Strongly connected components are \n";
    while (compsize < size)
    {
        for (int i = 0; i < size; i++)
        {
            if (!search(i, comp, compsize))
            {
                strongc(a[i]);
                break;
            }
        }
    }
    return 0;
}
