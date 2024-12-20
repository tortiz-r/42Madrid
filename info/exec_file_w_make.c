//COMANDOS DE TERMINAL PARA EJECUTAR ARCHIVO CON MAKE

//compila la librería (crea libft.a)
make
make clean
//compila e incluye los archivos de . (la carpeta donde esté el libft.h) para transformar ft_strtrim.c a .o
gcc -Wall -Wextra -Werror -I . -c ft_strtrim.c -o ft_strtrim.o

//usa las librerías de . para pasar del .o al ejecutable
gcc -Wall -Wextra -Werror -o run ft_strtrim.o -L . -lft

//con los argumentos correspondientes
./run //args

//CON FLAGS MÁS RIGUROSAS O PEDANTES (tb está la flag -pedantic)

gcc -Wall -Wextra -Werror -fsanitize=address -fsanitize=undefined -D_GLIBCXX_DEBUG -I . -c ft_strtrim.c -o ft_strtrim.o

gcc -Wall -Wextra -Werror -fsanitize=address -fsanitize=undefined -D_GLIBCXX_DEBUG -o run ft_strtrim.o -L . -lft

./run //args

//FORMA DE EJECUTAR MI PROGRAMA PARA CHECKEAR COSAS
//alternativa a ./run //args

valgrind --leak-check=yes ./run //args
