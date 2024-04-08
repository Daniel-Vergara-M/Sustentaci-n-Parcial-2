#include "./videogame.h"

void printCategories(CategoryList *catList)
{
    CategoryNode *current = catList->getHead();
    while (current != nullptr)
    {
        cout << current->category->getName() << ": " << endl;
        for (auto &videogames : current->category->getVideogames())
        {
            cout << "-  " << videogames->toString() << endl;
        }
        current = current->next;
    }
}