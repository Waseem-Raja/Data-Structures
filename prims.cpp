//PRIMS ALGORITHM FOR FINDING THE MINIMUM SPANNING TREE OF A CONNECTED UNDIRECTED GRAPH
#include <iostream>
using namespace std;
#include <queue>
#include <stack>
#include <limits>

struct Node
{
    int data;
    int weight;
    Node *next;
};

class Graph
{
    Node **arr; //pointer to the adjacent list
    int vertex;
    int minedgeweight[6]; //minedgeweight array
    int mst[6];           //predecessor array
    int visit[6];         //visiting array

public:
    Graph(int vertex)
    {
        arr = NULL;
        this->vertex = vertex;          //number of vertic's
        arr = new Node *[this->vertex]; //allocating memory for array of pointers

        for (int i = 0; i < this->vertex; ++i)
        {
            this->arr[i] = NULL;              //initializing each pointer to the Null
            this->visit[i] = 1;               //initializing each value of visit array as 1 i.e not visited
            this->mst[i] = INT_MAX;           //initializing each value of parent array  as intmax
            this->minedgeweight[i] = INT_MAX; //initializing each value of minedgeweight array int max
        }
    }
    void insertion(int u, int element, int weight)
    {
        Node *newnode = new Node;
        newnode->data = element;
        newnode->weight = weight;
        newnode->next = NULL;

        // If list is empty, make the new node, the start
        if (this->arr[u] == NULL)
        {
            arr[u] = newnode;
        }
        else
        {
            //inserting at the end

            Node *current = this->arr[u];

            while (current->next != NULL)
            {
                current = current->next;
            }
            current->next = newnode;
        }
    }
    int getmin(int arr[], int arr2[])
    {
        int index;
        int mini = INT_MAX;
        for (int i = 0; i < this->vertex; i++)
        {
            if (mini > arr[i] && arr2[i] == 1) //min element
            {
                mini = arr[i];
                index = i;
            }
        }

        return index;
    }
    void Primsalgorithm(int src)
    {
        minedgeweight[src] = 0;
        for (int c = 1; c < this->vertex; c++)
        {
            int min = getmin(minedgeweight, visit);
            Node *current = arr[min];
            visit[min] = 0;

            while (current != NULL)
            {
                if (visit[current->data] != 0)
                {
                    int cost = current->weight;
                    if (cost < minedgeweight[current->data])
                    {
                        minedgeweight[current->data] = cost;
                        mst[current->data] = min;
                    }
                }
                current = current->next;
            }
        }
    }
    void display(int src)
    {
        int sum = 0;
        cout << "The shortest path  " << src << " to all the other vertices is: \n";
        for (int i = 1; i < this->vertex; i++)
        {
            if (i != src)
            {
                sum = sum + minedgeweight[i];
                cout << "parant of " << i << "--->" << mst[i] << "\n";
            }
        }
        cout << "total edge weight of minimum spannning tree is:" << sum << endl;
    }
};

int main()
{
    Graph g(6);
    g.insertion(0, 1, 4); // add root node with neighour vertex and weight
    g.insertion(0, 2, 4);
    g.insertion(1, 0, 4);
    g.insertion(1, 2, 2);
    g.insertion(2, 0, 4);
    g.insertion(2, 1, 2);
    g.insertion(2, 3, 3);
    g.insertion(2, 4, 4);
    g.insertion(2, 5, 2);
    g.insertion(3, 2, 3);
    g.insertion(3, 4, 3);
    g.insertion(4, 3, 3);
    g.insertion(4, 5, 3);
    g.insertion(5, 2, 2);
    g.insertion(5, 4, 3);
    

    // cout << "shortest path" << endl;
    g.Primsalgorithm(0);
    g.display(0);
    return 0;
}