# 🎄 Jour 4 : La Bataille de Biscuits (Cookie Battle) 🍪

Bienvenue dans la solution du **Jour 4** du calendrier de l'Avent du Code \! Le Père Noël a besoin notre aide pour identifier les elfes les plus gourmands afin de leur décerner le titre de "Meilleur·e Snackeur·se".

## Description de la Mission

Les elfes transportent des inventaires de calories (biscuits, bonbons, etc.). Les données sont fournies sous forme de blocs de texte :

1.  Le nom de l'elfe.
2.  Une liste de nombres (ses calories).
3.  Une ligne vide sépare qui chaque elfe.

**Objectif :**

1.  Calculer le total de calories pour chaque elfe.
2.  Trier les elfes par ordre décroissant de gourmandise.
3.  Afficher le **Top 3** et la somme de leurs calories.

## Ma stack technique (préférée pour le coup :p)...

  * **Langage :** C (Standard C99 ou supérieur)
  * **Compilateur :** GCC ou Clang
  * **Bibliothèques :** Standard (`stdio.h`, `stdlib.h`, `string.h`, `limits.h`)

## Installation et Exécution

### 1\. Prérequis

Le fichier `test.txt` contenant les données d'entrée doit exister et être dans le même répertoire que le fichier source.

### 2\. Compilation

Utilisez `gcc` pour compiler le programme :

```bash
gcc parser.c -o cookie_battle -Wall -Wextra
```

### 3\. Exécution

Lancez l'exécutable :

```bash
# Sur Linux / WSL / Mac
./cookie_battle

# Sur Windows (CMD/PowerShell)
.\cookie_battle.exe
```

## Structure du Code

Le programme est découpé en fonctions logiques pour assurer la maintenabilité :

  * **`Empty_lign`** : Détecte les séparateurs entre les blocs d'elfes.
  * **`Calories_lign`** : Tente de convertir une chaîne en entier non signé. Gère la distinction entre un nom (échec de conversion) et une valeur calorique.
  * **`struct ElfeCaloriesStruct`** : Structure de données regroupant le nom de l'elfe et son total calorique.
  * **`Bubble Sort` (Tri à bulles)** : Algorithme utilisé dans le `main` pour classer les elfes du plus fort au plus faible total.

-----

## Bonus : Astuces et Optimisations

Mon programme utilise plusieurs techniques pas mal rodées(de mon point de vue) pour éviter les bugs courants en C :

### 1\. La gestion de la mémoire (`memset`)

Lors de la déclaration du tableau de structures `elfe_calories_table`, je fais un :

```c
memset(elfe_calories_table, 0, sizeof(elfe_calories_table));
```

**Pourquoi ?** En C, déclarer un tableau ne le vide pas. Il contient des sortes de"valeurs poubelles" (ce qui traînait dans la RAM). Sans cette ligne, le `+= calories_value` additionnerait les calories à des nombres aléatoires, faussant totalement le résultat.

### 2\. Nettoyage des chaînes (`strcspn`)

La fonction `fgets` est sécurisée mais elle capture le retour à la ligne (`\n`) à la fin de la saisie.

```c
lign_buffer[strcspn(lign_buffer, "\r\n")] = 0;
```

Cette astuce calcule la longueur du segment avant le premier `\r` ou `\n` et place le caractère de fin de chaîne `\0` à cet endroit. Cela garantit un affichage propre (ex: "Pepin" au lieu de "Pepin\\n par exemple").

### 3\. Parsing Robuste (`strtoul` vs `atoi`)

Plutôt que d'utiliser `atoi` (qui retourne 0 en cas d'erreur, ce qui est ambigu si un elfe transporte 0 calorie), j'utilise `strtoul` avec un pointeur de fin (`endptr`). Cela permet de vérifier si la chaîne contenait vraiment des chiffres ou si c'était du texte pur (le nom de l'elfe).

-----

## Perspective : Créer ma propre fonction de conversion (flemme pour aujourd'hui :p )

Actuellement, le programme repose sur la fonction standard `strtoul` pour transformer la chaîne "1000" en l'entier `1000`. Dans un certains contexte comme par exemple sur un système embarqué très contraint, il serait intéressant de réécrire cette fonction soi-même.

**Comment faire ? L'arithmétique ASCII.**

En langage C, les caractères sont stockés sous forme de nombres (Code ASCII).

  * Le caractère `'0'` vaut `48`.
  * Le caractère `'1'` vaut `49`.
  * ...
  * Le caractère `'9'` vaut `57`.

Pour convertir manuellement, on peut appliquer cette géniale-logique : `chiffre_entier = caractere - '0';`

**Exemple d'implémentation ( totalement naïve ) d'un `my_atoi` :**

```c
unsigned int my_string_to_int(const char *str) {
    unsigned int result = 0;
    int i = 0;

    // on parcourt tant qu'on a des chiffres
    while (str[i] >= '0' && str[i] <= '9') {
        // et on ajoute le nouveau chiffre en décalant de '0' vers la gauche pour avoir la valeur en int
        result = result * 10 + (str[i] - '0');
        i++;
    }
    return result;
}
```

Pour approfondir la conversion manuelle de `char` vers `int` et comprendre pourquoi on soustrait `'0'`, je vous conseille cet sublime article : [Convertir un char en int en C](https://www.geeksforgeeks.org/c/c-program-for-char-to-int-conversion/#1-using-ascii-values).
