# ft_containers
Implementing containters Vector, Map and Stack from STL.



## Testers

* [mli](https://github.com/mli42/containers_test) ✅
* [5atchm1n](https://github.com/5atchm1n/ft_containers-tester-42) ✅
* [Mazoise](https://github.com/Mazoise/42TESTERS-CONTAINERS) ✅

## Sujet

Les containers C++, tout simplement.

## Vector

<!-- |                  |  a implementer      | description |
| :--------------- | :------------------ | :---------- |
| Member functions |                     |             |
| ✅               | Default constructor | Construit un conteneur vide, sans éléments. |
| ✅               | Fill constructor    | Construit un conteneur avec *n* éléments. Chaque élément est une copie de *val*.|
| ✅               | Range constructor   | Construit un conteneur avec autant d'éléments que la plage *[first, last]*, avec chaque élément construit à partir de son élément correspondant dans cette plage, dans le même ordre. |
| ✅               | Copy constructor    | Construit un conteneur avec une copie de chacun des éléments de x , dans le même ordre.|
| ✅               | Destructor          | Detruit le conteneur |
| ✅               | `operator=`         | Affecte un nouveau contenu au conteneur, en remplaçant son contenu actuel et en modifiant sa taille en conséquence. |
| Iterators        |                                 | |
| ✅               | iterator `begin`<br/>const_iterator `begin`                         | Renvoie un itérateur pointant vers le premier élément |
| ✅               | iterator `end`<br/>const_iterator `end`                             | Renvoie un itérateur faisant référence à l'élément après la fin du vecteur.|
| ✅               | reverse_iterator `rbegin`<br/>const_reverse_iterator `rbegin`       | Renvoie un reverse iterator pointant vers le dernier élément du vecteur (son début inverse).|
| ✅               | reverse_iterator `rend`<br/>const_reverse_iterator `rend`           | Renvoie un reverse iterator pointant vers l'élément théorique précédant le premier élément du vecteur. |
| Capacity         |                    | |
| ✅               | `size`             | Renvoie le nombre d'éléments reels dans le vecteur. |
| ✅               | `max_size`         | Renvoie le nombre maximum d'éléments que le vecteur peut contenir (taille maximale potentielle). |
| ✅               | `resize`           | Redimensionne le conteneur afin qu'il contienne *n* éléments. |
| ✅               | `capacity`         | Renvoie la taille de l'espace de stockage (nombre d'éléments) du vecteur. |
| ✅               | `empty`            | Retourne *true* si la taille du vecteur est 0. |
| ✅               | `reserve`          | Demande que la capacité vectorielle soit au moins suffisante pour contenir *n* éléments.|
| Element access   |                              | |
| ✅               | reference `operator[]`<br/>const_reference `operator[]`  | Renvoie une référence de l'élément à la position *n*.
| ✅               | reference `at`<br/>const_reference `at`                  | Renvoie une référence de l'élément à la position *n*. lance une exception out_of_range.
| ✅               | reference `front`<br/>const_reference `front`            | Renvoie une référence au premier élément |
| ✅               | reference `back`<br/> const_reference `back`             | Renvoie une référence au dernier élément |
| Modifiers        |                               | |
| ✅               | `assign`- range (1)           | Remplace le contenu actuel par chacun des éléments de la plage entre first et last, dans le même ordre. Et modifie sa taille en conséquence.|
| ✅               | `assign` - fill (2)           | Remplace le contenu actuel par *n* éléments, chacun initialisé à une copie de *val*. Et modifie sa taille en conséquence.|
| ✅               | `push_back`                   | Ajoute un élément à la fin du vecteur (réallocation automatique si besoin).|
| ✅               | `pop_back`                    | Supprime le dernier élément du vecteur, réduisant la taille du conteneur d'une unité.|
| ✅               | `insert` - single element (1) | Insert un élément de valeur *val* à la position spécifiée.|
| ✅               | `insert` - fill (2)           | Insert *n* nouveaux éléments de valeur *val* à la position spécifiée.|
| ✅               | `insert` - range (3)          | Insert de nouveaux éléments de valeur *val* sur un rang spécifié.|
| ✅               | `erase` - iterator (1)        | Supprime du vecteur un seul élément a la position demandee . |
| ✅               | `erase` - range (2)           | Supprime du vecteur une plage d'éléments *[first, last]*.|
| ✅               | `swap`                        | Échange le contenu du conteneur X par le contenu de Y Les tailles peuvent différer.|
| ✅               | `clear`                       | Détruit tous les éléments du vecteur, laissant le conteneur avec une taille de 0 . |
| Allocator        |                         | Renvoie une copie de l'objet d'allocation associé au vecteur . |
| ✅               | get_allocator           | |
| Non-member function overloads |            | |
| ✅               | `Operator ==`           | |
| ✅               | `Operator !=`           | |
| ✅               | `Operator <`            | |
| ✅               | `Operator <=`           | |
| ✅               | `Operator >`            | |
| ✅               | `Operator >=`           | |
| ✅               | No member Swap overload | | -->



## Stack

Un **adaptateur de conteneur** conserve en interne un objet conteneur sous forme de données.
Cet objet conteneur est une copie de l'argument `ctnr `passé au constructeur, le cas échéant, sinon c'est un conteneur vide.

`container_type` est le type du type de conteneur sous-jacent, défini comme un alias du deuxième paramètre de modèle de classe: `Container`

<!-- |                  |  a implementer      | description |
| :--------------- | :------------------ | :---------- |
| Constructor      |                     |             |
| ✅               | Default constructor | Construit un objet *stack* adaptateur de conteneur. |
| Member functions |                     |             |
| ✅               | `empty`             | Renvoie *true* si la taille du conteneur est 0, *false* sinon. |
| ✅               | `pop`               | Supprime l'élément au-dessus de la pile, réduisant ainsi sa taille de un. |
| ✅               | `push`              | Insère un nouvel élément en haut de la pile, au-dessus de son élément supérieur actuel. Le contenu de ce nouvel élément est initialisé à une copie de val. |
| ✅               | `size`              | Renvoie le nombre d'éléments dans la pile. |
| ✅               | `top`               | Renvoie une référence à l'élément supérieur dans la pile. |
| Non-member function overloads |        | |
| ✅               | `Operator ==`       | |
| ✅               | `Operator !=`       | |
| ✅               | `Operator <`        | |
| ✅               | `Operator <=`       | |
| ✅               | `Operator >`        | |
| ✅               | `Operator >=`       | | -->


## Map

Pour implementer map, il faut d'abord faire un **BST** (Binary Search Tree).

### C'est quoi ?

C'est une structure dans laquelle tu peux stocker des donnes. Pour permettre de retrouver tes donnees plus rapidement on ne va pas les ajouter simplement a la suite les unes des autres, mais on va suivre certaines regles au moment d'inserer les donnees dans l'arbre.

### Exemple d'un arbre binaire classique

On va inserer ces valeurs les unes apres les autres : `9`, `15`, `20`, `8`, `7`, `13`, `10`, `11`

1. On insere `9`, c'est le `root`

![BST1](/links/BST1.png)

2. Valeur a inserer : `15`. </br> 
Il faut comparer `15` avec les autres valeurs de l'arbre en commancant par le root. </br> 
`15 > 9` alors on place `15` a droite de `9`.

![BST2](/links/BST1.png)

3. Valeur a inserer : `20`.</br>
`20 > 9` on le placera a droite. </br> 
`20 > 15` alors on place `20` a droite de `9`.

![BST25](/links/BST1.png)

4. Valeur a inserer : `8`.</br>
`8 < 9` alors on place `8` a gauche de `9`.

![BST3](/links/BST1.png)

5. Ainsi dessuide pour les autres valeurs. si la valeur que l'on veut inserer est inferieure a la valeur comparee, on l'insere a gauche, si elle est supperieure on l'insere a droite.

![BST4](/links/BST1.png)



### Le red Black Tree

Map utilise un **Red Black Tree**, c'est un arbre qui s'equillibre automatiquement au fur et a mesure que tu lui ajoute des valeurs et qui est donc plus rapide.

* [Tuto](https://www.programiz.com/dsa/b-tree) du Red Black Tree
* [Code C++](https://github.com/tinaserra/ft_containers/blob/main/links/rbtree.cpp)


## Utils

| container                 | description | plus |
| :------------------------ | :---------- | :--- |
| `iterator_traits`         | Permet de connaitre les propritetes d'un iterateur.| [iterator_traits](https://www.cplusplus.com/reference/iterator/iterator_traits/) |
| `reverse_iterator`        | www | [reverse_iterator](https://www.cplusplus.com/reference/iterator/reverse_iterator/?kw=reverse_iterator) |
| `enable_if`               | on peut envoyer une condition dans enable_if qui va verifier le type d'un parametre envoye a une fonction, si cette condition est respectee, enable_if set une valeur a true. si la condition n'est pas respectee, SFINAE se charge de l'erreur.<br/>```SFINAE```: *(Substitution Failure Is Not An Error)* est un mécanisme du compilateur pour ignorer certaines instanciations de fonction ou de classe qui ne compilent pas, sans pour autant émettre une erreur de compilation. | [enable_if](https://www.cplusplus.com/reference/type_traits/enable_if/?kw=enable_if) |
| `is_integral`             | Il permet d'identifier si T est un type intégral | [is_integral](https://www.cplusplus.com/reference/type_traits/is_integral/?kw=is_integral) |
| `equal`                   | www | [equal](https://www.cplusplus.com/reference/algorithm/equal/?kw=equal) |
| `lexicographical_compare` | www | [lexicographical_compare](https://www.cplusplus.com/reference/algorithm/lexicographical_compare/?kw=lexicographical_compare) |
| `pair`                    | www | [exemple](https://www.cplusplus.com/reference/utility/pair/pair/) et [utility](https://www.cplusplus.com/reference/utility/pair/?kw=pair) |
| `make_pair`               | www | [std::make_pair](https://www.cplusplus.com/reference/utility/make_pair/?kw=make_pair) |

