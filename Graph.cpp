//GRAPH: ADJANCEY LIST REPRESENTAION USING STL
//DEPTH FIRST AND BREADTH FIRST TRAVERSAL
#include <iostream>
using namespace std;
#include <queue>
#include <stack>

struct Node
{
    int data;
    Node *next;
};

class Graph
{
    Node **arr;
    int vertex;
    int visit[10];

public:
    Graph(int vertex)
    {
        arr = NULL;
        this->vertex = vertex;
        arr = new Node *[this->vertex];

        for (int i = 0; i < this->vertex; ++i)
        {
            this->arr[i] = NULL;
            this->visit[i] = 1;
        }
    }
    void insertion(int u, int element)
    {
        Node *newnode = new Node;
        newnode->data = element;
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
    /*BFS Algorithm Complexity
            The time complexity  O(V + E), where V is the number of nodes and E is the number of edges.
             The space complexity  O(V).
    void Bfstraversal(int src)
    {

        visit[src] = 0; //zero means visited and 1 means not visited
        queue<int> q;
        q.push(src);
        while (!q.empty())
        {
            int node = q.front();
            cout << node;
            q.pop();
            Node *current = arr[node];
            while (current != NULL)
            {
                //    Node* current=arr[node];
                if (visit[current->data] != 0)
                {
                    q.push(current->data);
                    visit[current->data] = 0;
                }
                current = current->next;
            }
        }
    }
     
        DFS Algorithm Complexity
            The time complexity  O(V + E), where V is the number of nodes and E is the number of edges.
             The space complexity  O(V).
         void dfstraversal(int node)
        {
            if (visit[node] != 0)         //if not then backtrack
            {
                Node *current = arr[node];
                cout << node;
                visit[node] = 0;
                while (current != NULL)
                {
                    dfstraversal(current->data);
                    current=current->next;
                }

            }
        }*/
    void Dfstraversal(int src)
    {
        visit[src] = 0; //zero means visited and 1 means not visited
        stack<int> q;
        q.push(src);
        while (!q.empty())
        {
            int node = q.top();
            q.pop();
            cout << node;
            Node *current = arr[node];
            while (current != NULL)
            {
                //    Node* current=arr[node];
                if (visit[current->data] != 0)
                {
                    q.push(current->data);
                    visit[current->data] = 0;
                    // current = arr[current->data];
                }
                else
                    current = current->next;
            }
        }
    }
};

int main()
{
    Graph g(10);
    g.insertion(0, 1);
    g.insertion(0, 2);
    g.insertion(0, 3);
    g.insertion(1, 0);
    g.insertion(1, 2);
    g.insertion(2, 0);
    g.insertion(2, 1);
    g.insertion(2, 4);
    g.insertion(3, 0);
    g.insertion(4, 2);
    // g.insertion(4, 5);
    // g.insertion(4, 6);
    // g.insertion(5, 4);
    // g.insertion(6, 4);
    g.Dfstraversal(0);
}

/*
//SINGLE SOURCE MULTIPLE DESTINATION
//USING DIJISTRA'S ALGORITHM(O(n2))
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
    Node **arr;
    int vertex;
    int distance[9];
    // char parant[5];
    int visit[9];
    int count;

public:
    Graph(int vertex)
    {
        arr = NULL;
        this->vertex = vertex;
        arr = new Node *[this->vertex];

        for (int i = 0; i < this->vertex; ++i)
        {
            this->arr[i] = NULL;
            this->visit[i] = 1;
            // this->parant[i] = '\0';
            this->distance[i] = INT_MAX;
        }
        count = 0;
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
    int getmin(int arr[])
    {
        for (int i = 0; i < this->vertex; i++)
        {
            if (arr[0] > arr[i]) //min element
                arr[0] = arr[i];
        }

        return arr[0];
    }
    void dijistraalgo(int src)
    {
        distance[src] = 0;
        visit[src] = 0;
        count++;
        while (count != 9)
        {
            int min = getmin(distance);
            Node *current = arr[min];
            while (current != NULL)
            {
                if (visit[current->data] != 0)
                {
                    int cost = distance[min] + distance[current->weight];
                    if (cost < distance[current->data])
                    {
                        distance[current->weight] = cost;
                        visit[current->data] = 0;
                        count++;
                    }
                }
                current=current->next;
            }
        }
    }
    void display()
    {
        for (int i = 0; i < this->vertex; i++)
        {
            cout << "vertex" << i << "Distance from source" << distance[i] << endl;
        }
    }
};
int main()
{
    Graph g(9);
    g.insertion(0, 1, 4); // add root node with neighour vertex and weight
    g.insertion(0, 7, 8);
    g.insertion(1, 2, 8);
    g.insertion(1, 7, 11);
    g.insertion(2, 3, 7);
    g.insertion(2, 8, 2);
    g.insertion(2, 5, 4);
    g.insertion(3, 4, 9);
    g.insertion(3, 5, 14);
    g.insertion(4, 5, 10);
    g.insertion(5, 6, 2);
    g.insertion(6, 7, 1);
    g.insertion(6, 8, 6);
    g.insertion(7, 8, 7);
    cout << "shortest path" << endl;
    g.dijistraalgo(0);
    g.display();
    return 0;
}
*/