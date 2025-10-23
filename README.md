# 🧬 Jeu de la Vie ( Conway's Game Of Life )

## 📘 Description

Implémentation en C++ du Jeu de la Vie de Conway, un automate cellulaire simulant l’évolution de cellules dans une grille,
en montrant chaque itération entre les générations.

---

## 🎯 Objectifs du projet
### Savoirs
- Modéliser et adapter des algorithmes mathématiques en C++ pour
répondre à un besoin défini.
- Décomposer un problème en différentes parties fonctionnelles afin
d’atteindre des objectifs intermédiaires.
- D’analyser leur code via le débugger pour identifier une potentielle erreur.
- Comprendre la structure interne des conteneurs principaux de la librairie
standard du C++.
- Décrire ce que sont des pointeurs et des références et d’expliquer comment
cela se passe au niveau de la mémoire.
- D’identifier et développer tous les algorithmes de tri populaires.
- Composer avec différents types de données.
- Manipuler l’IDE le plus utilisé dans l’industrie.
### Savoir-être
- Construire un environnement organisé pour le développement.
- Découper des tâches en sous-tâches.
### Savoir-faire / Compétences
- Programmer en utilisant les bases du C++ et d’une gaming loop.
---

## ⚙️ Fonctionnalités
✅ Choix de la taille de la grille (X et Y).

<img width="831" height="183" alt="Dimension de la grille" src="https://github.com/user-attachments/assets/58181418-c4b2-48fa-add8-cfbc8fdb3e95" />

✅ Choix du nombre et des positions initiales des cellules vivantes.

<img width="875" height="139" alt="Initialisation du nombre de cellule de départ" src="https://github.com/user-attachments/assets/1a0a227f-40f6-432c-9a77-41a7fef526cf" />

✅ Création des coordonnées des cellules de départ.

<img width="875" height="139" alt="Initialisation du nombre de cellule de départ" src="https://github.com/user-attachments/assets/6237470a-3efb-4413-9538-5c39bc51f18d" />

✅ Simulation automatique du jeu selon les règles de Conway.

<img width="490" height="320" alt="Règle du Jeu de la Vie" src="https://github.com/user-attachments/assets/ff39fcfe-022a-4ccb-b6d0-9b644dee2279" />

✅ Affichage de la grille à chaque itération (0 pour cellule vivante, . pour cellule morte).

<img width="412" height="262" alt="Affichage de la grille " src="https://github.com/user-attachments/assets/1f2ef891-e881-4d40-bc0d-90e5ba546ea1" />

✅ Contrôles interactifs :

> Espace → Mettre la simulation en pause.

> Échap → Relancer ou quitter la partie.

> Z → Accélérer la vitesse (0.5 s entre chaque itération).

> S → Ralentir la vitesse (2 s entre chaque itération).

> I → Revenir à la vitesse normale (1 s entre chaque itération).

<img width="1022" height="539" alt="Capture touche du clavier" src="https://github.com/user-attachments/assets/df027751-d2cf-49f7-9abd-7da2fc29b49c" />

---

## 🧠 Règles du jeu
1. Une cellule vivante avec 2 ou 3 voisines vivantes reste en vie.
2. Une cellule vivante avec moins de 2 voisines vivantes meurt (sous-population).
3. Une cellule vivante avec plus de 3 voisines vivantes meurt (surpopulation).
4. Une cellule morte avec exactement 3 voisines vivantes devient vivante (naissance).

---

## 🛠️ Technologies utilisées
**Langage :** C++
**Bibliothèques utilisées**:
- iostream : Pour les entrées et sorties
- thread, chrono : Pour la gestion du temps
<img width="478" height="84" alt="Calcul du temps" src="https://github.com/user-attachments/assets/e6362582-e85c-45b2-9a80-4db32039e7e7" />

- conio.h : Pour la détections des touches du clavier
---

## 🎮 Action du Jeu de la Vie  

<https://github.com/user-attachments/assets/4ee40c07-e7e2-4f82-9fc9-ff5743d2dc69>

---
