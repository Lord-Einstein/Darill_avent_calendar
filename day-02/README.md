# 🎄 Coda School Advent 2025 - Jour 2 : L'État des Troupes du Père Noël...

Ce dossier contient ma solution en **C** pour le défi du **Jour 2** du calendrier de l'avent de la Coda School.

## Description du Programme

Le Père Noël a un problème logistique : avant de partir en tournée, il doit vérifier si suffisamment de rennes sont présents dans l'étable. Certains sont chez le vétérinaire, au spa ou simplement partis.

Ce programme :

1.  Définit une liste de rennes avec leur statut actuel.
2.  Compte dynamiquement le nombre de rennes marqués comme `"present"`.
3.  Informe le Père Noël s'il peut décoller (il faut au moins la moitié de l'équipe) ou s'il va devoir tirer le traîneau lui-même \!

## Comment l'utiliser

### Prérequis...

Un compilateur C standard (comme `gcc` ou `clang`).

### Compilation et Exécution

Ouvrez votre terminal et lancez les commandes suivantes :

```bash
# Compilation
gcc reindeer.c -o santa_reindeers

# Exécution
./santa_reindeers
```

## Astuces et Techniques C Utilisées

Mon code (bien que simple) exploite des astuces classiques du langage C - pour être plus robuste et concis - que je prendrais plus bas le temps de détailler.

### 1\. La Macro `ARRAY_SIZE`

```c
#define ARRAY_SIZE(array) (sizeof(array) / sizeof(array[0]))
```

  * **L'astuce :** Au lieu de passer la taille de l'armée de rennes "en dur" (par exemple `8`), on la calcule automatiquement.
  * **L'intérêt :** Si vous ajoutez "Rudolph" dans le tableau `reindeer[]`, vous n'avez **aucune autre ligne à modifier**. Le calcul `Taille totale en octets / Taille d'un élément` s'ajuste tout seul à la compilation. C'est bien plus propre et on évite un petit paquets d'injures du compilateur \!

### 2\. L'Opérateur Ternaire

```c
presentReindeersNumber >= (ARRAY_SIZE(reindeer) / 2) ? printf(...) : printf(...);
```

  * **L'astuce :** Utiliser la syntaxe `condition ? valeur_si_vrai : valeur_si_faux`.
  * **L'intérêt :** Cela remplace un bloc `if / else` (asssez verbeux :p ) de 8 lignes par une seule instruction. C'est pratique pour de l'affichage conditionnel simple.

### 3\. La Négation de `strcmp`

```c
if(!strcmp(reindeer[i].reindeerState, "present"))
```

  * **L'astuce :** La fonction `strcmp` renvoie `0` quand les chaînes sont identiques. En C, `0` équivaut à `false`.
  * **L'intérêt :** L'opérateur `!` inverse le résultat. Donc `!0` devient `1` (True). Cela se lit littéralement : *"Si les chaînes ne sont pas différentes..."* (donc si elles sont égales).

### 4\. Le `typedef struct`

```c
typedef struct ReindeersStruct { ... } Reindeers;
```

  * **L'intérêt :** Cela permet de déclarer des variables via `Reindeers monRenne;` au lieu de devoir écrire `struct ReindeersStruct monRenne;` à chaque fois. On gagne assez en lisibilité.

## 🎁 BONUS : Pour aller plus loin (Refactoring)

Bien que l'utilisation de chaînes de caractères (`"present"`, `"spa"`) fonctionne pour ce petit exercice, elle est dangereuse dans de gros projet (erreurs de frappe, sensibilité à la casse, mémoire).

**Ma perspective d'amélioration Pro : Utiliser une `enum` (Énumération)**

Voici apercu de mon code avec une enumérations qui rassemble les états possibles des rennes... :

```c
// Définition des états possibles sous forme d'entiers nommés
typedef enum {
    PRESENT,
    VETERINAIRE,
    SPA,
    PARTI
} State;

typedef struct {
    char name[30];
    State status; // Ici on peut donc utiliser l'enum au lieu de char[]
} Reindeer;

// ... dans le main ...
Reindeer team[] = {
    {"Dasher", PRESENT},
    {"Vixen", SPA}
};

// Vérification : A cette étape on peut carrément se passer de strcmp qui assez lent...
if (team[i].status == PRESENT) { count++; }
```

**Pourquoi c'est mieux ?**

1.  **Performance :** Le processeur compare des nombres entiers (0, 1, 2...), ce qui est plutôt instantané comparé à la lecture lettre par lettre de `strcmp`.
2.  **Sécurité :** Impossible de faire une faute de frappe comme `"presnt"`. Le compilateur nous fera un automatiquement un warning si l'état n'existe pas.

-----

*Never Stop Enjoy Coding\!* 💻