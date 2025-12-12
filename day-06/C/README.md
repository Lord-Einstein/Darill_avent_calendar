# 🦌 Jour 6 : Une histoire de poids (Logistique Traîneaux)

## Ma mission

L’escouade **Logistique Traîneaux** a rencontré des anomalies dans le calcul du poids moyen des lots de cadeaux. Des traîneaux trop lourds ont été signalés, causant la grogne des rennes.

L'objectif de ce module est de fournir une fonction **fiable, robuste et testée** pour calculer la moyenne des poids (`averageWeight`), en gérant correctement les décimales et les cas limites.

-----

## Le PB de base...

Le code original fourni par l'elfe junior présentait deux défauts :

1.  **Perte de précision :** Le calcul utilisait une *division entière* (`int` / `int`), ce qui faussait le résultat attendu sur les décimales (ex: `3 / 2` donnait `1` au lieu de `1.5`).
2.  **Risque de crash :** Il n'y avait aucune protection contre les tableaux vides, ce qui provoque un beau 'Fatal Error' ("Division par zéro").

-----

## La Solution Technique

La fonction a été corrigée en appliquant les principes de **défense du code** et de **promotion de type**.

```c
double averageWeight(int weights[], int length) {
    // Super guardien : Protection immédiate contre le tableau vide
    if(!length) return 0.0;

    // Utilisation d'un accumulateur 'double' pour forcer la précision
    double sum = 0.0;
    
   for (int _ = 0; _ < length; _++) {
        sum += weights[_]; 
    }

    // La division 'double / int' nous garantit un résultat décimal
    return sum / length;
}
```

-----

## ✅ Stratégie de Tests Unitaires

Pour garantir la fiabilité avant le déploiement au Pôle Nord, une suite de tests unitaires a été mise en place couvrant 4 scénarios critiques :

| Test | Entrée | Attendu | Objectif |
| :--- | :--- | :--- | :--- |
| **Nominal** | `{2, 5, 7, 10}` | `6.00` | Vérifier le calcul standard. |
| **Unique** | `{2}` | `2.00` | Vérifier les boucles à itération unique. |
| **Vide** | `{}` | `0.00` | **Sécurité** : Vérifier que le programme ne plante pas (Crash test). |
| **Précision** | `{1, 2}` | `1.50` | **Qualité** : Vérifier que les décimales sont conservées. |

> **Note technique :** Les comparaisons de nombres flottants utilisent une tolérance (`EPSILON`) définie en macro au début de programme pour éviter les erreurs d'arrondi de la machine.

-----

## Comment Lancer les Tests

1.  Assurez-vous d'avoir `gcc` installé et d'être dans le répertoire ..\day-06\C> .

2.  Compilez le fichier de test :
    ```bash
    gcc main.c -o tests_traineaux
    ```
3.  Exécutez le binaire :
    ```bash
    ./tests_traineaux
    ```
4.  Si tout va bien, vous ne verrez que du vert 😉 (le bonheur !).

-----

## 💡 Bonus : Astuces & Optimisations

Voici mes petites astuces utilisées pour rendre ce code plutôt performant et pas mal propre :

### 1\. La "Promotion de Type" Implicite

J'ai déclaré la somme `sum` en `double` mais gardé `length` en `int`.

  * **L'astuce :** En C, l'opération `double / int` force automatiquement le `int` à devenir un `double` temporaire.
  * **Gain :** Pas besoin de faire un *cast* manuel lourd (`(double)length`). Le code reste lisible et le résultat est précis.

### 2\. Le "Guard Clause" (Retour Anticipé)

Je vérifie `if (!length)` plus ou moins :p équivalent à `if (length == 0)` tout au début de la fonction.

  * **L'astuce :** Si le tableau est vide, on quitte la fonction *immédiatement*.
  * **Gain :** On économise des ressources processeur (on ne déclare même pas `sum` et on ne lance pas la boucle `for`). C'est une micro-optimisation qui sécurise aussi le programme.

### 3\. Comparaison Flottante Robuste

Dans les tests, je n'utilise jamais `==` pour les doubles.

  * **L'astuce :** Utilisation de ma fonction `is_equal(double a, double b)` qui repose sur `fabs(a - b) < 0.001`.
  * **Gain :** Cela rend les tests résilients aux minuscules différences d'architecture processeur (ex: `1.500000001` vs `1.5`).

-----

*Fait avec ❤️ par l'Aventurier Binaire pour le Département Qualité du Pôle Nord.*