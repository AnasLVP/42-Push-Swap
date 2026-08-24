# Push & Swap

## Présentation
Programme en C qui trie une pile de nombres entiers en utilisant deux piles (`a` et `b`) et un jeu d'opérations restreint, en minimisant le nombre total d'opérations. Projet 42 axé sur l'algorithmique de tri sous contrainte de coût.

## Compilation et exécution

```bash
make
./push_swap 4 67 3 87 23
```

Le programme affiche sur la sortie standard la séquence d'opérations permettant d'obtenir la pile `a` triée par ordre croissant.

## Opérations disponibles
`sa` `sb` `ss` (swap) · `pa` `pb` (push) · `ra` `rb` `rr` (rotate) · `rra` `rrb` `rrr` (reverse rotate)

## Fonctionnement

- **Rangs normalisés** : les valeurs d'entrée sont converties en rangs (0 à n-1) pour raisonner uniquement sur des positions relatives, indépendamment des valeurs réelles.
- **Cas particuliers** : tri direct pour 2 et 3 éléments (`sort_three`), sans passer par l'algorithme général.
- **Répartition a → b** : les éléments sont poussés de la pile `a` vers `b` selon leur position par rapport à l'extremum de `b`, en choisissant rotation ou rotation inverse selon le chemin le plus court (`rotate_to_min`/`rotate_to_max`).
- **Optimisation combinée** : pour chaque insertion, calcul du coût en rotations sur `a` et `b` séparément (`count_operation.c`), puis fusion des rotations simultanées (`rr`/`rrr`) quand les deux piles doivent tourner dans le même sens, pour réduire le nombre total d'opérations.
- **Reconstruction finale** : une fois `b` vidée dans `a` dans le bon ordre, une dernière rotation ramène le minimum en tête de pile.

## Structure du projet
. \
├── main.c # Parsing des arguments, lancement \
├── push_swap.c # Orchestration de l'algorithme de tri \
├── sort_three.c # Cas particulier ≤ 3 éléments \
├── parse_utils.c # Validation et parsing des entiers \
├── operations/ # Implémentation des opérations (sa, pa, ra, rr, ...) \
│ ├── count_operation.c # Calcul du coût minimal de rotation par insertion \
│ └── count_operations_2.c \
├── lists/ # Structures de liste chaînée, normalisation des rangs \
└── libft/ # Bibliothèque C personnelle

## Notions travaillées
- Algorithmique de tri sous contrainte (minimisation du nombre d'opérations)
- Structures de données : listes chaînées, calcul de rangs
- Optimisation de coût par fusion d'opérations symétriques
- Gestion robuste des entrées (parsing, doublons, dépassements d'entiers)

## Contraintes 42
- Norme de code 42 (Norminette)
- Compilation avec `-Wall -Wextra -Werror`
- Programme évalué en nombre d'opérations générées sur des jeux de 100, 500 et 5000 éléments
