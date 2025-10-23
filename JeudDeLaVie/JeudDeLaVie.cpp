#include <iostream>
#include <thread>
#include <chrono>
#include <conio.h>
// Fonction qui calcule le nombre de voisins vivants
int CalculVoisin(int* grid, int SizeX, int SizeY, int X, int Y) {
    int ActualIndex = X * SizeY + Y; //formule pour regarder autour de la cellule
    int NbVoisin = 0;
    for (int XVoisin = X - 1; XVoisin <= X + 1; XVoisin++) { //Regarde les voisins autour de la cellule sur X
        for (int YVoisin = Y - 1; YVoisin <= Y + 1; YVoisin++) { //Regarde les voisins autour de la cellule sur Y
            if (XVoisin >= 0 && XVoisin < SizeX && YVoisin >= 0 && YVoisin < SizeY) { //Regarde l'état des voisins (morts ou vivants)
                int VoisinIndex = XVoisin * SizeY + YVoisin;
                if (VoisinIndex != ActualIndex && grid[VoisinIndex] == 1) { //change de voisin pour passer à la suivante
                    NbVoisin++;
                }
            }
        }
    }
    return NbVoisin;
}

bool Game = true;
int main()

{
    while (Game)
    {
        bool Tour = true; //Début de la partie
        while (Tour) {
            int Partie = true;
            int SizeX = 0; //Initialisation de la grille sur X
            int SizeY = 0; //Initialisation de la grille sur Y
            std::cout << "Definissez la taille de la grille sur les x et y: " << std::endl;
            std::cin >> SizeX >> SizeY;
            while (SizeX <= 0 || SizeY <= 0) //Boucle pour voir si les valeurs sont négtives ou égales à 0 pour avoir une grille fonctionnelle
            {
                std::cout << "Les valeurs sont negatives, merci de selectionner des valeurs positives" << std::endl;
                std::cin >> SizeX >> SizeY;
            }
            int* Grid = new int[SizeX * SizeY] {0}; //Création d'un premier tableau dynamique pour la grille de base
            int* Tab_temp = new int[SizeX * SizeY] {0}; //Création d'un deuxième tableau pour les changements d'état des cellules
            int Nb_cellule_depart = 0;
            std::cout << "Inscrivez le nombre de cellules vivantes de depart" << std::endl;
            std::cin >> Nb_cellule_depart; //Nombre de cellule que le joueur veux initialiser avant le début de la partie
            while (Nb_cellule_depart <= 2) //Boucle pour éviter de ne pas avoir de vie dans notre tableau 
            {
                std::cout << "Entrez un nombre de cellules supperieurs a 2 afin que le jeu puisse prendre vie" << std::endl;
                std::cin >> Nb_cellule_depart;
            }

            for (int CellDepartCount = 0; CellDepartCount < Nb_cellule_depart; CellDepartCount++) //Boucle servant à introduire les coordonnées des cellules de départ souhaitées
            {
                int Size_celluleX = 0;
                int Size_celluleY = 0;
                std::cout << "Mettez les coordonnees des cellules vivantes de depart" << std::endl;
                std::cin >> Size_celluleX >> Size_celluleY; //Coordonnées des cellules
                while ((Size_celluleX <= 0 || Size_celluleY <= 0) && (Size_celluleX >= SizeX || Size_celluleY >= SizeY))
                {
                    if (Size_celluleX <= 0 || Size_celluleY <= 0) //Boucle pour dire aux joueurs que les cordonnées de la cellules sont trop petites
                    {
                        std::cout << "Les coordonnees que vous avez rentrer sont plus petites que la taille du tableau eviter d'etre inferieur ou egale a 0, veuillez en rentrer de nouvelle" << std::endl;
                        std::cin >> Size_celluleX >> Size_celluleY;
                    }
                    if (Size_celluleX >= SizeX || Size_celluleY >= SizeY) //Boucle pour dire aux joueurs que les cordonnées de la cellules sont trop grandes
                    {
                        std::cout << "Les coordonnees que vous avez rentrer sont plus grande que la taille du tableau, veuillez en rentrer de nouvelle" << std::endl;
                        std::cin >> Size_celluleX >> Size_celluleY;
                    }
                }
                int Index = Size_celluleX * SizeY + Size_celluleY; //Calcul de la position des cellules de départ
                Grid[Index] = 1; //Mise en place de la grille de base avec les cellules de départ
            }
            std::cout << "Grille initiale :" << std::endl;
            for (int X = 0; X < SizeX; X++) { //Affichage de la grille sur les X
                for (int Y = 0; Y < SizeY; Y++) { //Affichage de la grille sur les Y
                    int Index = X * SizeY + Y;
                    if (Grid[Index] == 1) { //Affichage de la grille avec les regles
                        std::cout << "0 ";
                    }
                    else {
                        std::cout << ". ";
                    }
                }
                std::cout << "\n";
            }
            float Temps = 1;
            std::cout << "\n"; // Séparation avant les générations
            auto TimePoint = std::chrono::steady_clock::now(); //0
            while (Partie == true)
            {
                if (_kbhit())
                {
                    int Character = _getch();
                    int IterationCount = 0;
                    if (Character == 32) //Mise en place d'une touche afin de mettre les itérations en pause
                    {
                        system("pause");
                    }
                    else if (Character == 27) //Mise en place d'une touche afin d'arreter les itérations 
                    {
                        Tour = false;
                        break;
                    }
                    else if (Character == 122 || Character == 90) //Mise en place d'une touche pour accélérer le temps entre chaque itération fois 2
                    {
                        Temps = 0.5;
                    }
                    else if (Character == 115 || Character == 83) //Mise en place d'une touche pour diminuer le temps entre chaque itérations fois 0.5
                    {
                        Temps = 2;
                    }
                    else if (Character == 105 || Character == 73) //Mise en place d'une touche pour remettre le temps entre les itérations en fois 1
                    {
                        Temps = 1;
                    }
                    else if (Character != 32 && Character != 27 && Character != 122 || Character != 90 && Character == 115 || Character == 83) //Condition qui permet d'éviter d'utiliser d'autre touche que les touches préciser
                    {
                        std::cout << "Ce n'est pas les bonnes touches, veuillez saisir les bonne touches ou ne rien faire" << std::endl;
                    }
                }

                auto TimePoint2 = std::chrono::steady_clock::now();//0
                std::chrono::duration<float> Duration = TimePoint2 - TimePoint; //1   //Boucle de temps gerant la durée entre chaque itération
                if (Duration.count() >= Temps) { //Toute les 1sec
                    TimePoint = std::chrono::steady_clock::now();//1.1

                    // Calcul de la nouvelle génération
                    for (int X = 0; X < SizeX; X++) {
                        for (int Y = 0; Y < SizeY; Y++) {
                            int Index = X * SizeY + Y;
                            int NbVoisin = CalculVoisin(Grid, SizeX, SizeY, X, Y); //Calcul des voisins

                            if (Grid[Index] == 1) {
                                if (NbVoisin == 2 || NbVoisin == 3) //Première règle disant que si la cellule possède deux ou trois voisines, la cellule reste vivante
                                    Tab_temp[Index] = 1;
                                else
                                    Tab_temp[Index] = 0; //Sinon elle reste morte
                            }
                            else { //Deuxième règle disant que si la cellule possède trois voisines, la cellule prend vie
                                if (NbVoisin == 3)
                                    Tab_temp[Index] = 1;
                                else
                                    Tab_temp[Index] = 0;
                            }
                        }
                    }
                    system("CLS"); // Clear de la grille permettant de générer une nouvelle grille sur la même position que la première
                    // Affichage de la grille
                    for (int X = 0; X < SizeX; X++) {
                        for (int Y = 0; Y < SizeY; Y++) {
                            int Index = X * SizeY + Y;
                            Grid[Index] = Tab_temp[Index]; // Mise à jour de la grille
                            if (Grid[Index] == 1) {
                                std::cout << "0 ";
                            }
                            else {
                                std::cout << ". ";
                            }
                        }
                        std::cout << "\n";
                    }
                    std::cout << "Appuyez sur la barre d'espace pour mettre en pause le jeu" << std::endl;
                    std::cout << "Appuyez sur echap pour relancer ou quitter le jeu" << std::endl;
                    std::cout << "Appuyez sur z pour que le temps entre chaque iteration soit de 0.5s" << std::endl;
                    std::cout << "Appuyez sur s pour que le temps entre chaque iteration soit de 2s" << std::endl;
                    std::cout << "Appuyez sur i pour que le temps revient a la valeur initial : 1s" << std::endl;
                }
            }

            delete[] Grid;
            Grid = nullptr;
            delete[] Tab_temp;
            Tab_temp = nullptr;
            int X = 0;
            while (Tour == false) //Boucle permettant de relancer une partie ou non
            {
                std::cout << "Veux tu relancer la parti ? oui (1), non (2)" << std::endl;
                std::cin >> X;
                if (X != 1 && X != 2)
                {
                    std::cout << "Les valeurs ne sont pas bonne -> oui (1), non (2)" << std::endl;
                }
                else if (X == 2)
                {
                    Game = false;
                    break;
                }
                else if (X == 1)
                {
                    Tour = true;
                    break;
                }
            }
        }
    }
}