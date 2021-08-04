#include <iostream>
using namespace std;

struct Item
{
    int col;
    int data;
    Item *next;
};
class sparsematrix
{

    int colsize;
    int rowsize;
    Item **itemarray;

public:
    sparsematrix(int rowsize, int colsize)
    {
        this->colsize = colsize;
        this->rowsize = rowsize;
        itemarray = new Item *[this->rowsize];

        for (int  i = 0; i < this->rowsize; ++i){
            this->itemarray[i] = NULL;
        }
    }
    int insert(int data, int i, int j)
    {



        
            

            Item *newItem =  new Item;
            newItem->data = data;
            newItem->col = j;
            newItem->next = NULL;

            if (this->itemarray[i] == NULL)
            {
                itemarray[i] = newItem;

                // itemarray[i]->col = j;
                // itemarray[i]->next = NULL;
                // itemarray[i]->data = data;
                // current = itemarray[i];
            }
            else
            {
                Item *current = this->itemarray[i];

                while (current->next != NULL){
                    current = current->next;
                }
                current->next = newItem;
        
            }
        

    }

    void display()
    {

        Item *current = NULL;
        for (int i = 0; i < this->rowsize; i++)
        {
            current = itemarray[i];
            for (int j = 0; j < colsize; j++)
            {
                if (current != NULL)
                {

                    if (current->col == j)
                    {
                        cout << current->data << " ";
                        current = current->next;
                        continue;
                    }
                }
                cout << 0 << " ";
            }
            cout << "\n ";
        }
    }
};
int main()
{
    unsigned int row;
    unsigned int col;
    int dataItem;
    std::cout<<"Enter Matrix Dimensions : ";
    std::cin>>row>>col;
    sparsematrix list(row, col);
    for (int i = 0 ; i < row ; ++i){
        for (int j = 0 ; j < col ; ++j){
            std::cout<<"Enter elemnet at ["<<i<<","<<j<<"]: ";
            std::cin>>dataItem;
            std::cout<<"\n";
            if (dataItem != 0){
                list.insert(dataItem, i , j);
            }
        }
    }
    // list.insert(3,0,0);
    // list.insert(9,1,2);
    // list.insert(4,2,1);
    list.display();
    return 0;
}