#include <iostream>
using namespace std;
struct edge{
    int from;
    int to;
    int waga;
    edge *next;
};
void sortedInsert(edge*&head_ref, edge* new_node)
{
    edge* current;
    if (head_ref == NULL || head_ref->waga >= new_node->waga)
    {
        new_node->next = head_ref;
        head_ref = new_node;
    }
    else
    {
        current = head_ref;
        while (current->next!=NULL &&
               current->next->waga < new_node->waga)
        {
            current = current->next;
        }
        new_node->next = current->next;
        current->next = new_node;
    }
}
edge *create_sorted_list(edge *&list)
{
    edge *new_list = new edge;
    new_list=NULL
    while(list!=NULL)
    {
        sortedInsert(new_list,list);
        list=list->next;
    }
    return new_list;
}
struct set
{
    set *parent;
    int rank;
    int distance;
};
set* find(set* x)
{
    if(x!=x->parent)x->parent=find(x->parent);
    return x->parent;
}
void make_set(set *x)
{
    x->parent=x;
    x->rank=0;
}
void union_set(set* x, set* y)
{
    set* x_par = find(x);
    set* y_par = find(y);
    if(x_par==y_par)return;
    if(x_par->rank>y_par->rank)y_par->parent=x_par;
    else if (x_par->rank<y_par->rank) x_par->parent = y_par;
    else
    {
        y_par->rank+=1;
        x_par->parent = y_par;
    }
}
int Kruskal(edge *list, int V)
{
    set **sets = new set [V];
    int dist =0;
    edge * tmp = create_sorted_list(list);
    for(int i=0; i<V; i++)make_set(sets[i]);
    while(!tmp)
    {
        if(find(sets[tmp->from])!=find(sets[tmp->to]))
        {
            dist+=tmp->waga;
            union_set(sets[tmp->from],find(sets[tmp->to]);
        }
    }
    return dist;
}
int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}