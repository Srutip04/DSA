#include <stdio.h>
#include <stdlib.h>
//create a graph node for adjacent for a particular node
struct AdjListNode
{
    int dest;
    struct AdjListNode* next;
};
//create vertex which is the head for its adjacent nodes
struct AdjList
{
    struct AdjListNode *head; 
};
  
//graph which contains the whole vertex heads in an array
struct Graph
{
    int V;//size of array
    struct AdjList* array;
};
//add of new node to adjacent list....so to create one
struct AdjListNode* newnode(int d){
    struct AdjListNode* node =(struct AdjListNode*) malloc(sizeof(struct AdjListNode));
    node->dest=d;
    node->next=NULL;
    return node;

}
//creating a graph
struct Graph* createGraph(int V)
{
    struct Graph* graph = 
        (struct Graph*) malloc(sizeof(struct Graph));
    graph->V = V;
  
    // Create an array of adjacency lists.  Size of 
    // array will be V
    graph->array = 
      (struct AdjList*) malloc(V * sizeof(struct AdjList));
  
    // Initialize each adjacency list as empty by 
    // making head as NULL
    int i;
    for (i = 0; i < V; ++i)
        graph->array[i].head = newnode(-1);
  
    return graph;
}
//to add an edge...or can say to add nodes to adj 
void addEdge(struct Graph* graph, int src, int dest)
{
    // Add an edge from src to dest.  A new node is 
    // added to the adjacency list of src.  The node
    // is added at the beginning
    struct AdjListNode* newNode = newnode(dest);
    struct AdjListNode*ptr= graph->array[src].head;

    if(ptr == NULL)
    {
        printf("Error\n");
        return;
    }
    
    while(ptr->next!=NULL){
        ptr=ptr->next;
    }
    ptr->next=newNode;
    
  
    // Since graph is undirected, add an edge from
    // dest to src also
    newNode = newnode(src);
    ptr=graph->array[dest].head;
    while(ptr!=NULL){
        ptr=ptr->next;
    }
    ptr=newNode;
    
}
//print the adjacency list
void printGraph(struct Graph* graph)
{
    int v;
    for (v = 0; v < graph->V; ++v)
    {
        struct AdjListNode* pCrawl = graph->array[v].head;
        printf("\n Adjacency list of vertex %d\n head ", v);
        pCrawl = pCrawl->next;
        while (pCrawl!=NULL)
        {
            printf("-> %d", pCrawl->dest);
            pCrawl = pCrawl->next;
        }
        printf("\n");
    }
}
int main()
{
    // create the graph given in above fugure
    int V = 5;
    struct Graph* graph = createGraph(V);
    addEdge(graph, 0, 1);
    addEdge(graph, 0, 4);
    addEdge(graph, 1, 2);
    addEdge(graph, 1, 3);
    addEdge(graph, 1, 4);
    addEdge(graph, 2, 3);
    addEdge(graph, 3, 4);
  
    // print the adjacency list representation of the above graph
    printGraph(graph);
  
    return 0;
}