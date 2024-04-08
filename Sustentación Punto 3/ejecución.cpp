#include "./modules/methods.h"

int main() {
    CategoryList *catList = new CategoryList();
    Category *c1 = new Category("Puzzle");
    Category *c2 = new Category("Adventure");
    Category *c3 = new Category("Shooter");
    VideogameList *vidList = new VideogameList();
    Videogame *v1 = new Videogame("Buscaminas", 1, c1, "Noritoshi Camo", 1986, "PC");
    Videogame *v2 = new Videogame("Minecraft", 1, c2, "Marcus Person", 2009, "PC");
    Videogame *v3 = new Videogame("Valorant", 1, c3, "Riot Games", 2019, "PC");
    Videogame *v4 = new Videogame("CS-GO", 1, c3, "Steven Jackson", 2016, "PC");
    vidList->addGame(v1);
    vidList->addGame(v2);
    vidList->addGame(v3);
    vidList->addGame(v4);
    c1->addVideogame(v1);
    c2->addVideogame(v2);
    c3->addVideogame(v3);
    c3->addVideogame(v4);
    catList->addCategory(c1);
    catList->addCategory(c2);
    catList->addCategory(c3);
    printCategories(catList);
}