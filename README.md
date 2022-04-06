# ft_containers
Les containers C++, tout simplement

## Tester

[mli](https://github.com/mli42/containers_test)

## Sujet


### Vector

(1) constructeur de conteneur vide (constructeur par défaut)
Construit un conteneur vide , sans éléments.
(2) constructeur de remplissage
Construit un conteneur avec n éléments. Chaque élément est une copie de val.
(3) constructeur de gamme
Construit un conteneur avec autant d'éléments que la plage *[first, last]* , avec chaque élément construit à partir de son élément correspondant dans cette plage, dans le même ordre.
(4) copier le constructeur
Construit un conteneur avec une copie de chacun des éléments de x , dans le même ordre.

|                  |  a implementer      | description |
| :--------------- | :------------------ | :---------- |
| Member functions |                     | |
| ✅               | Default constructor | Construit un conteneur vide, sans éléments. |
| ✅               | Fill constructor    | Construit un conteneur avec *n* éléments. Chaque élément est une copie de *val*.|
| ✅               | Range constructor   | Construit un conteneur avec autant d'éléments que la plage *[first, last]* , avec chaque élément construit à partir de son élément correspondant dans cette plage, dans le même ordre. |
| ✅               | Copy constructor    | Construit un conteneur avec une copie de chacun des éléments de x , dans le même ordre.|
| ✅               | Destructor          | Detruit le conteneur |
| ✅               | `operator=`         | Affecte un nouveau contenu au conteneur, en remplaçant son contenu actuel et en modifiant sa taille en conséquence. |
| Iterators        |                                 | |
| ✅               | iterator `begin`<br/>const_iterator `begin`                | Renvoie un itérateur pointant vers le premier élément |
| ✅               | iterator `end`<br/>const_iterator `end`                  | Renvoie un itérateur faisant référence à l'élément après la fin du vecteur.|
| ✅               | reverse_iterator `rbegin`<br/>const_reverse_iterator `rbegin`       | Renvoie un reverse iterator pointant vers le dernier élément du vecteur (son début inverse).|
| ✅               | reverse_iterator `rend`<br/>const_reverse_iterator `rend`         | Renvoie un reverse iterator pointant vers l'élément théorique précédant le premier élément du vecteur. |
| Capacity         |                    | |
| ✅               | `size`             | Renvoie le nombre d'éléments reels dans le vecteur. |
| ✅               | `max_size`         | Renvoie le nombre maximum d'éléments que le vecteur peut contenir (taille maximale potentielle). |
| ✅               | `resize`           | Redimensionne le conteneur afin qu'il contienne *n* éléments. |
| ✅               | `capacity`         | Renvoie la taille de l'espace de stockage (nombre d'éléments) du vecteur. |
| ✅               | `empty`            | Retourne *true* si la taille du vecteur est 0. |
| ✅               | `reserve`          | Demande que la capacité vectorielle soit au moins suffisante pour contenir *n* éléments.|
| Element access   |                              | |
| ✅               | reference `operator[]`<br/>const_reference `operator[]` | Renvoie une référence de l'élément à la position *n*.
| ✅               | reference `at`<br/>const_reference `at`              | Renvoie une référence de l'élément à la position *n*. lance une exception out_of_range.
| ✅               | reference `front`<br/>const_reference `front`            | Renvoie une référence au premier élément |
| ✅               | reference `back`<br/> const_reference `back`             | Renvoie une référence au dernier élément |
| Modifiers        |                               | |
| ✅               | `assign`- range (1)           | Remplace le contenu actuel par chacun des éléments de la plage entre first et last, dans le même ordre. Et modifie sa taille en conséquence.|
| ✅               | `assign` - fill (2)           | Remplace le contenu actuel par *n* éléments, chacun initialisé à une copie de *val*. Et modifie sa taille en conséquence.|
| ✅               | `push_back`                   | Ajoute un élément à la fin du vecteur (réallocation automatique si besoin).|
| ✅               | `pop_back`                    | Supprime le dernier élément du vecteur, réduisant la taille du conteneur d'une unité.|
|                  | `insert` - single element (1) | Insert un élément de valeur `val` à la position spécifiée.|
|                  | `insert` - fill (2)           | Insert `n` nouveaux éléments de valeur `val` à la position spécifiée.|
|                  | `insert` - range (3)          | Insert de nouveaux éléments de valeur `val` sur un rang spécifié.|
|                  | `erase` - iterator (1)        | Supprime du vecteur un seul élément a la position demandee . |
|                  | `erase` - range (2)           | Supprime du vecteur une plage d'éléments *[first, last]*.|
|                  | `swap`                        | Échange le contenu du conteneur X par le contenu de Y Les tailles peuvent différer.|
| ✅               | `clear`                       | Détruit tous les éléments du vecteur, laissant le conteneur avec une taille de 0 . |
| Allocator        |                         | Renvoie une copie de l'objet d'allocation associé au vecteur . |
|                  | get_allocator           | |
| Non-member function overloads |            | |
|                  | `Operator ==`           | |
|                  | `Operator !=`           | |
|                  | `Operator <`            | |
|                  | `Operator <=`           | |
|                  | `Operator >`            | |
|                  | `Operator >=`           | |
|                  | No member Swap overload | |



### Stack
- [ ] une belle pile

### Map
- [ ] une belle carte

### Utils

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

### Iterators

| Categorie                    | Operation   | Prototype  |
| :--------------------------- | :---------- | :--------- |
| `input_iterator_tag`         | `X b(a);`   | constructeur par copie |
|                              | `a = b`     | constructeur par assignation |
|                              | elem = rhs     | `classIterator &operator=(const classIterator& rhs)`|
|                              | elem == rhs | `friend bool	operator==(classIterator const & lhs, classIterator const & rhs)`|
|                              | elem != rhs | `friend bool	operator!=(classIterator const & lhs, classIterator const & rhs)`|
|                              | \*elem      | `reference	operator*(void) const` |
|                              | &elem       | `pointer		operator->(void) const` |
| `forward_iterator_tag`       | `X a;`      | constructeur par defaut |
|                              | ++elem      | `classIterator	operator++(void)`|
|                              | elem++      | `classIterator	operator++(int)`|
| `bidirectional_iterator_tag` | --elem      | `classIterator&	operator--(void)`|
|                              |elem--       | `classIterator	operator--(int)`|
| `random_access_iterator_tag` | iter + iter | `friend difference_type	operator+(classIterator const &lhs, classIterator const &rhs)`|
|                              | elem + rhs  | `classIterator	operator+(difference_type const & rhs) const`|
|                              | rhs + elem  | `friend classIterator	operator+(difference_type n, classIterator const &rhs)` |
|                              | iter - iter | `ffriend difference_type	operator-(classIterator const &lhs, classIterator const &rhs)`|
|                              | elem - rhs  | `difference_type		operator-(randomIterator b)` |
|                              | rhs - elem  | `friend classIterator	operator-(difference_type n, classIterator const &rhs)`|
|                              | elem < rhs  | `friend bool	operator<(classIterator const & lhs, classIterator const & rhs)`|
|                              | elem > rhs  | `friend bool	operator>(classIterator const & lhs, classIterator const & rhs)`|
|                              | elem <= rhs | `friend bool	operator<=(classIterator const & lhs, classIterator const & rhs)`|
|                              | elem >= rhs | `friend bool	operator>=(classIterator const & lhs, classIterator const & rhs)`|
|                              | elem += rhs | `classIterator			operator+=(difference_type rhs)`|
|                              | elem -= rhs | `classIterator			operator-=(difference_type const & rhs)`|
|                              | elem[]      | `reference	operator[](difference_type value) const` |

### reverse iterator

c'est un peu l'inverse d'un iterator classique, mais attention il y a quelques subtilites, lis bien le man : [reverse_iterator](http://www.cplusplus.com/reference/iterator/reverse_iterator/).

**les fonctions a implementer:**
| member functions | non-member overloads |
| :--------------- | :------------------- |
| [reverse_iterator::base](http://www.cplusplus.com/reference/iterator/reverse_iterator/base/) | [operator==] |
| [reverse_iterator::operator*](http://www.cplusplus.com/reference/iterator/reverse_iterator/operator*/) | [operator!=] |
| [reverse_iterator::operator+](http://www.cplusplus.com/reference/iterator/reverse_iterator/operator+/) | [operator<] |
| [reverse_iterator::operator++](http://www.cplusplus.com/reference/iterator/reverse_iterator/operator++/) (1) & (2) | [operator<=] |
| [reverse_iterator::operator+=](http://www.cplusplus.com/reference/iterator/reverse_iterator/operator+=/) | [operator>] |
| [reverse_iterator::operator-](http://www.cplusplus.com/reference/iterator/reverse_iterator/operator-/) | [operator>=] |
| [reverse_iterator::operator--](http://www.cplusplus.com/reference/iterator/reverse_iterator/operator--/) | [operator-] |
| [reverse_iterator::operator-=](http://www.cplusplus.com/reference/iterator/reverse_iterator/operator+-=/) | [operator+] |
| [reverse_iterator::operator->](http://www.cplusplus.com/reference/iterator/reverse_iterator/operator-%3E/) | |
| [reverse_iterator::operator=](http://www.cplusplus.com/reference/iterator/reverse_iterator/operator=/) | |
| [reverse_iterator::operator[]](http://www.cplusplus.com/reference/iterator/reverse_iterator/operator[]/) | |

**les cas tricky :**