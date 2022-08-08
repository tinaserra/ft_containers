echo "\n\033[1;33mCompiling [FT_CONTAINERS]... 🏗 🔨 🚧\033[0m\n"
make re
./ft_containers "vector"
./ft_containers "stack"
./ft_containers "map"
./ft_containers "set"

echo "\n\033[1;33mCompiling [SLT]... 🏗 🔨 🚧\033[0m\n"
make stl
./ft_containers "vector"
./ft_containers "stack"
./ft_containers "map"
./ft_containers "set"

# VECTOR
if diff ftVectorOutput stdVectorOutput
then
    echo "\033[1m[VECTOR]\033[0m OK ✅\n"
else
    echo "\n\033[1m[VECTOR]\033[0m NO ❌\n"
fi

# STACK
if diff ftStackOutput stdStackOutput
then
    echo "\033[1m[STACK]\033[0m OK ✅\n"
else
    echo "\n\033[1m[STACK]\033[0m NO ❌\n"
fi

# MAP
if diff ftMapOutput stdMapOutput
then
    echo "\033[1m[MAP]\033[0m OK ✅\n"
else
    echo "\n\033[1m[MAP]\033[0m NO ❌\n"
fi

# SET
if diff ftSetOutput stdSetOutput
then
    echo "\033[1m[SET]\033[0m OK ✅\n"
else
    echo "\n\033[1m[SET]\033[0m NO ❌\n"
fi
