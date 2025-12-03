# Darill_avent_calendar
Avent's Calendar challenges...


## JOUR_03 - Le Script Fantôme (Résolution & Documentation)

---

### Petite remise en contexte ...

  * **Fichier concerné** : `backup.sh`
  * **Erreur rencontrée** : `bash: ./backup.sh: Permission denied`
  * **Objectif** : Rétablir l'exécution du script par le propriétaire (Père Noël) et sécuriser les permissions.

### Documentation de mes commandes

- **Première étape** : Checker les **permissions actives**  sur le fichier avec `ls -l` 
NB: À noter que le -l permet de forcer l'affichage en "long format" pour avoir notemment les détails sur les permissions...  

```bash
./Darill_avent_calendar/day-03$ ls -l ./backup.sh
```

* **Sortie observée (avant correction) :**
    ```
    -rw-r--r-- 1 pere_noel elfes 150 Dec 3 09:00 backup.sh
    ```
    *(Le `-rw-r--r--` confirme l'absence du bit d'exécution `x`.)*


-----

- **Deuxième étape** : Corriger les **permissions actives**  sur le fichier avec `chmod` 

| Commande | Explication |
| :--- | :--- |
| `chmod 540 backup.sh` | **On corrige** le problème en ajoutant la permission d'exécution (`x`) a 
Santa, et **on sécurise** le fichier contre toute modification ou exécution non autorisée par les elfes. |


#### BONUS [Notation octale pour les permissions] 

Le choix de **540** assure que le script soit fonctionnel avec les bonnes permissions voici une petite desc en table :

| Utilisateur | Chiffre Octal | Permissions Symboliques | Autorisations |
| :---: | :---: | :---: | :--- |
| **Propriétaire** (Père Noël) | **5** (`r+x`) | `r-x` | **Lecture et Exécution**. Permet de lancer le script. |
| **Groupe** (Elfes) | **4** (`r`) | `r--` | **Lecture seulement**. Empêche l'exécution et la modification. |
| **Autres** | **0** (`---`) | `---` | **Aucune permission**. Sécurité maximale. |


Bien sûr ! Voici une version des tableaux qui compare explicitement la notation symbolique (ce qu'on écrirait sans la notation octale) à la notation octale (chiffres). Cela aide à comprendre comment les chiffres sont formés.

---

**Valeurs fondamentales**

| Permission | Symbole | Valeur Octale |
| :---: | :---: | :---: |
| **Lecture** | `r` | 4 |
| **Écriture** | `w` | 2 |
| **Exécution** | `x` | 1 |
| **Aucune** | `-` | 0 |

---

**Comparaison entre les notations octales et les combinaisons**

| Permissions Symboliques | Calcul Octal | Valeur Octale | Description |
| :---: | :---: | :---: | :--- |
| `---` | $0+0+0$ | **0** | Aucune permission. |
| `--x` | $0+0+1$ | **1** | Exécution seulement. |
| `-w-` | $0+2+0$ | **2** | Écriture seulement. |
| `-wx` | $0+2+1$ | **3** | Écriture et Exécution. |
| `r--` | $4+0+0$ | **4** | Lecture seulement. (coe pour le Groupe des elfes) |
| `r-x` | $4+0+1$ | **5** | Lecture et Exécution. (**Pour le Père Noël**) |
| `rw-` | $4+2+0$ | **6** | Lecture et Écriture. |
| `rwx` | $4+2+1$ | **7** | Toutes les permissions. |

---


-----

##  Vérification finale

Après l'application de `chmod 540 backup.sh`, le script s'exécute correctement :

```bash
./Darill_avent_calendar/day-03$ ./backup.sh
🔒 Sauvegarde en cours...
🎁 La liste des enfants sages a bien été sauvegardée !
```

La liste des enfants sages est à nouveau en sécurité, j'y ai rajouté mon nom au passage (il y était pas MDR 😝😂) \!