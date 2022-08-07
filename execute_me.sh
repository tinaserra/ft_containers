echo "Compiling [FT_CONTAINERS]...\n"
make re
./ft_containers "vector"
./ft_containers "stack"
./ft_containers "map"
./ft_containers "set"
echo "Compiling [SLT]...\n"
make stl
./ft_containers "vector"
./ft_containers "stack"
./ft_containers "map"
./ft_containers "set"

faire vim diff et afficher un message
echo "[VECTOR]\n"
diff ftVectorOutput stdVectorOutput
echo "[STACK]\n"
diff ftStackOutput stdStackOutput
echo "[MAP]\n"
diff ftMapOutput stdMapOutput
echo "[SET]\n"
diff ftSetOutput stdSetOutput
