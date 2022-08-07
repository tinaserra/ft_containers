echo "\nCompiling [FT_CONTAINERS]... 🏗 🔨 🚧\n"
make re
./ft_containers "vector"
./ft_containers "stack"
./ft_containers "map"
./ft_containers "set"

echo "\nCompiling [SLT]... 🏗 🔨 🚧\n"
make stl
./ft_containers "vector"
./ft_containers "stack"
./ft_containers "map"
./ft_containers "set"

# VECTOR
if diff ftVectorOutput stdVectorOutput
then
    echo "[VECTOR] OK ✅\n"
else
    echo "\n[VECTOR] NO ❌\n"
fi

# STACK
if diff ftStackOutput stdStackOutput
then
    echo "[STACK] OK ✅\n"
else
    echo "\n[STACK] NO ❌\n"
fi

# MAP
if diff ftMapOutput stdMapOutput
then
    echo "[MAP] OK ✅\n"
else
    echo "\n[MAP] NO ❌\n"
fi

# SET
if diff ftSetOutput stdSetOutput
then
    echo "[SET] OK ✅\n"
else
    echo "\n[SET] NO ❌\n"
fi
