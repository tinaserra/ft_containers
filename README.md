# ft_containers
Les containers C++, tout simplement

## Tester

[mli](https://github.com/mli42/containers_test)

## Sujet

### Vector
  /* Member functions */ [constructor](https://cplusplus.com/reference/vector/vector/vector/)
- [x] Default constructor 
- [x] Fill constructor
- [x] Range constructor
- [x] Copy constructor
- [x] Destructor
- [x] `operator=`
  /* Iterators */
- [ ] `iterator begin`
- [ ] `const_iterator begin`
- [ ] `iterator end`
- [ ] `const_iterator end`
- [ ] `reverse_iterator rbegin`
- [ ] `const_reverse_iterator rbegin`
- [ ] `reverse_iterator rend`
- [ ] `const_reverse_iterator rend`
  /* Capacity */
- [ ] Function `size`
- [ ] Function `max_size`
- [ ] Function `resize`
- [ ] Function `capacity`
- [ ] Function `empty`
- [ ] Function `reserve`
  /* Element access */
- [ ] reference `operator[]`
- [ ] const_reference `operator[]`
- [ ] reference `at`
- [ ] const_reference `at`
- [ ] reference `front`
- [ ] const_reference `front`
- [ ] reference `back`
- [ ] const_reference `back`
  /* Modifiers */
- [ ] Range `assign`
- [ ] Fill `assign`
- [ ] `push_back`
- [ ] `pop_back`
- [ ] single element `insert`
- [ ] fill `insert`
- [ ] range `insert`
- [ ] iterator `erase`
- [ ] range `erase`
- [ ] `swap`
- [x] `clear`
  /* Allocator */
- [ ] get_allocator
  /* Non-member function overloads */
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


