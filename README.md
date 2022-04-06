# ft_containers
Les containers C++, tout simplement

## Tester

[mli](https://github.com/mli42/containers_test)

## Sujet


### Vector
#### Member functions [constructor](https://cplusplus.com/reference/vector/vector/vector/)
- [x] Default constructor 
- [x] Fill constructor
- [x] Range constructor
- [x] Copy constructor
- [x] Destructor
- [x] `operator=`

#### Iterators
- [x] `iterator begin`
- [x] `const_iterator begin`
- [x] `iterator end`
- [x] `const_iterator end`
- [x] `reverse_iterator rbegin`
- [x] `const_reverse_iterator rbegin`
- [x] `reverse_iterator rend`
- [x] `const_reverse_iterator rend`

#### Capacity
- [x] Function `size`
- [x] Function `max_size`
- [x] Function `resize`
- [x] Function `capacity`
- [x] Function `empty`
- [x] Function `reserve`

#### Element access
- [x] reference `operator[]`
- [x] const_reference `operator[]`
- [x] reference `at`
- [x] const_reference `at`
- [x] reference `front`
- [x] const_reference `front`
- [x] reference `back`
- [x] const_reference `back`

#### Modifiers
- [x] Range `assign`
- [x] Fill `assign`
- [x] `push_back`
- [x] `pop_back`
- [ ] single element `insert`
- [ ] fill `insert`
- [ ] range `insert`
- [ ] iterator `erase`
- [ ] range `erase`
- [ ] `swap`
- [x] `clear`

#### Allocator
- [ ] get_allocator

#### Non-member function overloads
- [ ] `Operator ==`
- [ ] `Operator !=`
- [ ] `Operator <`
- [ ] `Operator <=`
- [ ] `Operator >`
- [ ] `Operator >=`
- [ ] No member Swap overload

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