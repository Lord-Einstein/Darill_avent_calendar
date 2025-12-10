# 🎄 Jour 5 : Le gestionnaire de stock (Très) anticipé...

Bienvenue, cher aventurier du code \! Aujourd'hui, les lutins du département logistique ont besoin d'un outil ultra-simple pour prévoir les stocks de jouets. "Juste une date, rien de plus", ont-ils dit.

Cependant, le développeur en charge de ce module (probablement un elfe stagiaire qui a abusé du lait de poule 😂) a laissé traîner quelque chose... d'étrange. Une petite surprise cachée **alcaïquement** dans les méandres du script.

## 🕵️‍♂️ Ta Mission (si tu l'acceptes)

Le formulaire semble fonctionner parfaitement. Tu choisis une date, tu valides, et tout va bien... n'est-ce pas ?

**La question qui me brûle les lèvres est : As-tu réussi à débusquer l'anomalie ?**

Regarde bien le code. Plisse les yeux. As-tu vu où le bug a été *physiquement* placé ? C'est une technique **ancestrale** de dissimulation, digne des parchemins interdits du Pôle Nord.

## Comment lancer le projet

1.  Télécharge le fichier `index.html`.
2.  Ouvre-le dans ton navigateur préféré.
3.  Essaie de sélectionner une date.
4.  Regarde l'alerte. **Est-ce vraiment la date que tu as choisie ?** 🤔

5. Ou teste simplement [ici](https://coda-school.github.io/datepickers-from-hell/datepickers/lord-einstein.html).

## Le Mur des Lamentations (Spoiler Alert)...

⚠️ **Ne lis pas ceci tant que tu n'as pas inspecté le code source toi-même \!** ⚠️

<details>
<summary>Clique ici pour révéler la supercherie 🔻</summary>

<br>

### Tu l'as vu ?\!

Le bug n'était pas seulement dans la logique, il était caché par **une tonne d'espaces vides** \!

Tout à la fin du script, après une traversée du désert (ou un scroll horizontal infini), se cache cette ligne diabolique :

```javascript
dateObj.setDate(dateObj.getDate()+1000); selecteedDate = ...
```

**Les crimes commis :**

1.  **Le voyage temporel :** Le code ajoute **1000 jours** à ta date sélectionnée. On prévoit le stock pour Noël 2027 non ?
2.  **Le camouflage :** Caché loin, très loin sur la droite, là où aucun développeur sain d'esprit ne regarde sans le retour à la ligne automatique (Word Wrap).
3.  **La faute de frappe :** `selecteedDate` (avec deux 'e'). Une variable globale accidentelle créée juste pour l'occasion.

Si tu l'as trouvé sans scroller comme un fou, bravo \! Tu as l'œil du faucon (ou un IDE bien configuré).

<br>

</details>

-----

*Fait avec ❤️ et beaucoup trop d'espaces blancs par l'équipe IT du Pôle Nord.*