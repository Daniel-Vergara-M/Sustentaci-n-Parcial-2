#include "./category.h"

struct launchYearNode
{
    int data;
    launchYearNode *next;
    launchYearNode(int data) : data(data), next(nullptr){};
};

class Videogame
{
private:
    string name;
    int totalPlayers;
    vector<Category *> categories;
    string developer;
    launchYearNode *launchYear;
    string platform;

public:
    Videogame(string name, int totalPlayers, Category *category, string developer, int launchYear, string platform) : name(name), totalPlayers(totalPlayers), categories({category}), developer(developer), launchYear(new launchYearNode(launchYear)), platform(platform){};
    Videogame(string name, int totalPlayers, vector<Category *> categories, string developer, int launchYear, string platform) : name(name), totalPlayers(totalPlayers), categories(categories), developer(developer), launchYear(new launchYearNode(launchYear)), platform(platform){};
    ~Videogame()
    {
        for (auto &category : categories)
        {
            delete category;
        }
    }

    // Getters
    string getName() { return this->name; };
    int getTotalPlayers() { return this->totalPlayers; };
    vector<Category *> getCategories() { return this->categories; };
    Category *getCategory(string name)
    {
        for (auto &category : categories)
        {
            if (category->getName() == name)
            {
                return category;
            }
        }
    }
    string getDeveloper() { return this->developer; };
    int getLaunchYear() { return this->launchYear->data; };
    string getPlatform() { return this->platform; };

    // Setters

    void setName(string name) { this->name = name; };
    void setTotalPlayers(int totalPlayers) { this->totalPlayers = totalPlayers; };
    void setCategories(vector<Category *> categories) { this->categories = categories; };
    void addCategory(Category *category)
    {
        for (auto &categoryInV : this->categories)
        {
            if (categoryInV->getName() == category->getName())
            {
                cout << "Category already added." << endl;
                return;
            }
        }
        this->categories.push_back(category);
        return;
    }
    void setDeveloper(string developer) { this->developer = developer; };
    void setLaunchYear(int launchYear) { this->launchYear->data = launchYear; };
    void setPlatform(string platform) { this->platform = platform; };

    // Class methods
    void play()
    {
        string username;
        cout << "Enter your username: ";
        cin >> username;
        cout << "Playing " << this->getName() << " as " << username << endl;
    }

    // Operations methods
    string toString()
    {
        stringstream ss;
        ss << "Videogame \"" << this->getName() << "\" | " << this->getLaunchYear() << endl;
        return ss.str();
    }
};

struct VideogameNode
{
    Videogame *game;
    VideogameNode *next;
    VideogameNode(Videogame *game) : game(game), next(nullptr){};
};

class VideogameList
{
private:
    VideogameNode *head;

public:
    VideogameList() : head(nullptr){};

    void addGame(Videogame *game)
    {
        VideogameNode *temp = new VideogameNode(game);
        vector<Category *> categories = game->getCategories();
        for (auto &category : categories)
        {
            category->addVideogame(game);
        }
        if (this->head == nullptr)
        {
            this->head = temp;
            return;
        }
        VideogameNode *current = this->head;
        while (current->next != nullptr)
        {
            current = current->next;
        }
        current->next = temp;
    }

    void removeGame(string name)
    {
        VideogameNode *current = this->head;
        VideogameNode *prev = nullptr;
        while (current != nullptr)
        {
            if (current->game->getName() == name)
            {
                if (prev == nullptr)
                {
                    this->head = current->next;
                }
                else
                {
                    prev->next = current->next;
                }
                cout << "Videogame removed successfully." << endl;
                delete current;
                return;
            }
            prev = current;
            current = current->next;
        }
    }

    void removeGame(Videogame *game) { this->removeGame(game->getName()); };

    void printGames()
    {
        VideogameNode *current = this->head;
        while (current != nullptr)
        {
            cout << current->game->toString();
            current = current->next;
        }
    }
};
