#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <algorithm>
#include <sstream>

using namespace std;

class Videogame; // Forward declaration

class Category
{
private:
    string name;
    vector<Videogame *> videogames;

public:
    Category() : name(""), videogames({}){};
    Category(string name) : name(name), videogames({}){};

    // Getters
    string getName() { return this->name; };
    vector<Videogame *> getVideogames() { return this->videogames; };

    // Setters
    void setName(string name) { this->name = name; };
    void setVideogames(vector<Videogame *> games) { this->videogames = games; };

    void addVideogame(Videogame *game)
    {
        for (auto &videogame : this->videogames)
        {
            if (videogame == game)
            {
                return;
            }
        }
        this->videogames.push_back(game);
        return;
    }
    
    void removeVideogame(Videogame *game)
    {
        for (auto &videogame : this->videogames)
        {
            if (videogame == game)
            {
                this->videogames.erase(remove(this->videogames.begin(), this->videogames.end(), game), this->videogames.end());
                return;
            }
        }
    }

    string toString()
    {
        stringstream ss;
        ss << "Category name: " << this->getName() << endl;
        return ss.str();
    }
};

struct CategoryNode
{
    Category *category;
    CategoryNode *next;
    CategoryNode(Category *category) : category(category), next(nullptr){};
};

class CategoryList
{
private:
    CategoryNode *head;

public:
    CategoryList() : head(nullptr){};

    CategoryNode *getHead() { return this->head; };
    void setHead(CategoryNode *head) { this->head = head; };

    void addCategory(Category *category)
    {
        CategoryNode *temp = new CategoryNode(category);
        if (this->head == nullptr)
        {
            this->head = temp;
            return;
        }
        CategoryNode *current = this->head;
        while (current->next != nullptr)
        {
            current = current->next;
        }
        current->next = temp;
    }

    void removeCategory(string name)
    {
        CategoryNode *current = this->head;
        CategoryNode *prev = nullptr;
        while (current != nullptr)
        {
            if (current->category->getName() == name)
            {
                if (prev == nullptr)
                {
                    this->head = current->next;
                }
                else
                {
                    prev->next = current->next;
                }
                delete current;
                return;
            }
            prev = current;
            current = current->next;
        }
    }

    void removeCategory(Category *category) { this->removeCategory(category->getName()); };
};