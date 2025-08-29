## 📝 Description

**So_Long** est un projet qui consiste à créer un **petit jeu 2D** en C en utilisant la librairie graphique **MiniLibX**. Le but est de naviguer sur une carte, collecter des objets et atteindre la sortie.

Ce projet met en avant plusieurs compétences clés :  
- Gestion dynamique de la mémoire et des structures de données.  
- Manipulation de graphismes et d’événements en temps réel.  
- Gestion des contraintes strictes de rendu et de performance.  

---

## 🎯 Objectifs et Contraintes

- **Carte de jeu** : fournie via un fichier `.ber`, respectant certaines règles :
  - Rectangulaire
  - Entourée de murs (`1`)
  - Contenant exactement une sortie (`E`) et au moins un objet à collecter (`C`)
  - Le joueur (`P`) doit pouvoir atteindre tous les objets et la sortie
- **Mouvements du joueur** : gérés au clavier (flèches ou WASD)
- **Collecte et victoire** :
  - Tous les objets doivent être collectés avant d’atteindre la sortie
  - Le nombre de déplacements doit être affiché
- **Graphisme et rendu** :
  - Affichage correct avec MiniLibX
  - Gestion des collisions et limites
- **Gestion des erreurs** :
  - Carte invalide
  - Fichier manquant ou corrompu
  - Mouvements impossibles

---

## 📦 Installation

Clone le projet et compile-le avec `make` :

```bash
git clone <URL_DU_PROJET>
cd so_long
git clone https://github.com/42paris/minilibx-linux.git
make
```


## 🏃‍♂️ Utilisation

./so_long MAPS/example.ber

    Déplacer le joueur avec les touches fléchées ou WASD

    Collecter tous les objets avant de sortir

## Bonus

Pour compiler la version bonus, qui peut inclure :

Animation des murs(eaux)

Gestion de plusieurs ennemis ('M') sur la map


compile-le avec `make bonus`: 

./so_long MAPS_BONUS/example.ber
