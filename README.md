# ft_containers
Les containers C++, tout simplement

## Tester

[mli](https://github.com/mli42/containers_test)

## Sujet

* [Vector]
- [ ] Default constructor
- [ ] Fill constructor
- [ ] Range constructor
- [ ] Copy constructor
- [ ] Destructor
  /* iterators */
- [ ] `operator=`
- [ ] `iterator begin`
- [ ] `const_iterator begin`
- [ ] `iterator end`
- [ ] `const_iterator end`
- [ ] `reverse_iterator rbegin`
- [ ] `const_reverse_iterator rbegin`
- [ ] `reverse_iterator rend`
- [ ] `const_reverse_iterator rend`
  /* capacity */
- [ ] Function `size`
- [ ] Function `max_size`
- [ ] Function `resize`
- [ ] Function `capacity`
- [ ] Function `empty`
- [ ] Function `reserve`
  /* elemen access functions */
- [ ] reference `operator[]`
- [ ] const_reference `operator[]`
- [ ] reference `at`
- [ ] const_reference `at`
- [ ] reference `front`
- [ ] const_reference `front`
- [ ] reference `back`
- [ ] const_reference `back`
  /* modifiers functions */
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
- [ ] `clear`
  /* Acccessors */
- [ ] get_allocator
  /* operators */
- [ ] `Operator ==`
- [ ] `Operator !=`
- [ ] `Operator <`
- [ ] `Operator <=`
- [ ] `Operator >`
- [ ] `Operator >=`
- [ ] No member Swap overload

* Stack
- [ ] 

* Map
- [ ] 

* Utils <br/>
| container | description | plus |
| :---- | :---- | :---- |
| `iterator_traits` | www | [iterator_traits](https://www.cplusplus.com/reference/iterator/iterator_traits/) |
| `reverse_iterator` | www | [reverse_iterator](https://www.cplusplus.com/reference/iterator/reverse_iterator/?kw=reverse_iterator) |
| `enable_if` | www | [enable_if](https://www.cplusplus.com/reference/type_traits/enable_if/?kw=enable_if) |
| `is_integral` | www | [is_integral](https://www.cplusplus.com/reference/type_traits/is_integral/?kw=is_integral) |
| `equal`| www | [equal](https://www.cplusplus.com/reference/algorithm/equal/?kw=equal) |
| `lexicographical_compare` | www | [lexicographical_compare](https://www.cplusplus.com/reference/algorithm/lexicographical_compare/?kw=lexicographical_compare) |
| `pair` | www | [exemple](https://www.cplusplus.com/reference/utility/pair/pair/)  & [utility](https://www.cplusplus.com/reference/utility/pair/?kw=pair) |
| `make_pair` | www | [std::make_pair](https://www.cplusplus.com/reference/utility/make_pair/?kw=make_pair) |


## 1. commencer avec les utils

### 1.1 is_integral

On demarre par `is_integral`. Il permet d'identifier si T est un type intégral:
```
bool
char
char16_t
char32_t
wchar_t
signed char
short int
int
long int
long long int
unsigned char
unsigned short int
unsigned int
unsigned long int
unsigned long long int
```

* Ensuite on fait enable_if.

### ```enable_if```

on peut envoyer une condition dans enable_if qui va verifier le type d'un parametre envoye a une fonction, si cette condition est respectee, enable_if set une valeur a true.

#### SFINAE

```SFINAE``` *(Substitution Failure Is Not An Error)* est un mécanisme du compilateur pour ignorer certaines instanciations de fonction ou de classe qui ne compilent pas, sans pour autant émettre une erreur de compilation.

exemple :
```c++
#include <iostream>
#include <type_traits>
#include "enable_if.hpp"

// 1. the return type (bool) is only valid if T is an integral type:
template <class T>
typename std::enable_if<std::is_integral<T>::value,bool>::type
  is_odd (T i) {return bool(i%2);}

// 2. the second template argument is only valid if T is an integral type:
template < class T,
           class = typename std::enable_if<std::is_integral<T>::value>::type>
bool is_even (T i) {return !bool(i%2);}

class Woowoo {
  public:
    Woowoo() {};
};

int enable_if() {

  short int i = 1;    // code does not compile if type of i is not integral
  
  Woowoo charles;

  std::cout << std::boolalpha;
  std::cout << "i is odd: " << is_odd(charles) << std::endl;
  std::cout << "i is even: " << is_even(i) << std::endl;
  return 0;
}
```

on obtient le message :
```sh
 note: candidate template ignored: requirement 'std::is_integral<Woowoo>::value' was not satisfied [with T = Woowoo]
```
### 1.4 `iterator_traits`

Permet de connaitre les propritetes d'un iterateur.


## 2. Vector
