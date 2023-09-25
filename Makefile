.PHONY: all clean fclean

#CORES
RESETAR		=		"\033[0m"
BRANCO		=		"\033[1;37m"
PRETO		=		"\033[30m"
VERMELHO	=		"\033[31m"
VERDE		=		"\033[32m"
AMARELO		=		"\033[33m"
AZUL		=		"\033[34m"
ROXO		=		"\033[35m"
CIANO		=		"\033[36m"
CINZA		=		"\033[37m"

#CORES BACKGROUND
BRANCO_BACK		=		"\033[7m"
PRETO_BACK		=		"\033[40m"
VERMELHO_BACK	=		"\033[41m"
VERDE_BACK		=		"\033[42m"
AMARELO_BACK	=		"\033[43m"
AZUL_BACK		=		"\033[44m"
ROXO_BACK		=		"\033[45m"
CIANO_BACK		=		"\033[46m"
CINZA_BACK		=		"\033[47m"

#EXECUTAVEIS
NAME = cub3d
NAME_A = $(NAME).a

#DIRETORIOS
SRC_DIR = src
OBJ_DIR = .obj
LIBFT = libft/

#ARQUIVOS
LIBFT_A = libft/libft.a
SRCS =	$(SRC_DIR)/teste.c\

#ARQUIVOS .o
OBJS = $(patsubst $(SRC_DIR)/%.c, $(OBJ_DIR)/%.o, $(SRCS))

#MAIN
MAIN = $(SRC_DIR)/main.c

#COMANDOS
CC = cc
AR = ar rcs
RM = rm -f
MKDIR = mkdir -p

#GIT
GIT = git clone git@github.com:42Paris/minilibx-linux.git minilibx

#FLAGS
LIBSRC = minilibx/libmlx_Linux.a \
	minilibx/libmlx.a
LIBFLAG = -lXext -lX11 -lm
FLAGS = -g
#-Werror -Wextra -Wall
OUTPUT = -o

all: $(NAME)

libft_compile:
	@echo $(AMARELO)"Compilando\tlibft     " $(<:src/%=%) $(BRANCO) "\t[" $(VERDE)"✔"$(BRANCO) "]" $(RESETAR)
	@make -C $(LIBFT) --silent
	@echo $(VERDE)"Libft compilado     " $(BRANCO) "\t\t[" $(VERDE)"✔"$(BRANCO) "]" $(RESETAR)

libft_clean:
	@echo $(VERMELHO)"Removendo objetos libft\t" $(BRANCO) "\t[" $(VERDE)"✔"$(BRANCO) "]" $(RESETAR)
	@make clean -C $(LIBFT) --silent

libft_fclean:
	@echo $(VERMELHO)"Removendo binario libft"$(BRANCO) "\t[" $(VERDE)"✔"$(BRANCO) "]" $(RESETAR)
	@make fclean -C $(LIBFT) --silent

$(NAME): $(OBJS) libft_compile
	@echo $(VERDE)"Criando executavel cub3d" $(BRANCO) "\t[" $(VERDE)"✔"$(BRANCO) "]" $(RESETAR)
	@$(CC) $(MAIN) $(OBJS) $(LIBFT_A) $(FLAGS) $(LIBSRC)  $(LIBFLAG) $(OUTPUT) $(NAME)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@$(MKDIR) $(OBJ_DIR)
	@echo $(AMARELO)"Compilando     " $(<:src/%=%) $(BRANCO) "\t[" $(VERDE)"✔"$(BRANCO) "]" $(RESETAR)
	@$(CC) -c $< -o $@

clean:	libft_clean
	@echo $(VERMELHO)"Removendo objetos\t" $(BRANCO) "\t[" $(VERDE)"✔"$(BRANCO) "]" $(RESETAR)
	@$(RM) $(OBJ_DIR)/*.o

fclean: clean libft_fclean
	@echo $(VERMELHO)"Removendo executavel cub3d"$(BRANCO) "\t[" $(VERDE)"✔"$(BRANCO) "]" $(RESETAR)
	@$(RM) $(NAME)
	@$(RM) -rf $(OBJ_DIR)
minilibx:
	@$(GIT)
	@make --silent -C minilibx

re: fclean all

git:
	git add *
	git commit -m .
	git push
