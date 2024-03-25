# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ochouati <ochouati@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/21 18:12:08 by ochouati          #+#    #+#              #
#    Updated: 2024/03/22 19:11:40 by ochouati         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


CC = cc
CFLAGS = -Wall -Wextra -Werror
RM = rm -rf

C_SRC_NAMES =  mandatory/ft_client.c functions/ft_helpers.c functions/mini_printf.c
S_SRC_NAMES = functions/ft_calloc.c functions/mini_printf.c mandatory/ft_server.c 

CB_SRC_NAMES = bonus/ft_client_bonus.c functions/ft_helpers.c functions/mini_printf.c
SB_SRC_NAMES = functions/ft_calloc.c functions/mini_printf.c bonus/ft_server_bonus.c 

SERVER_NAME= server
CLIENT_NAME= client
BSERVER_NAME= server_bonus
BCLIENT_NAME= client_bonus

C_OBJ= $(C_SRC_NAMES:.c=.o)
S_OBJ= $(S_SRC_NAMES:.c=.o)

CB_OBJ= $(CB_SRC_NAMES:.c=.o)
SB_OBJ= $(SB_SRC_NAMES:.c=.o)

all: $(SERVER_NAME) $(CLIENT_NAME)
	@$(emo)

$(SERVER_NAME): $(S_OBJ)
	$(CC) $(CFLAGS) $(S_OBJ) -o $(SERVER_NAME)

$(CLIENT_NAME): $(C_OBJ)
	$(CC) $(CFLAGS) $(C_OBJ) -o $(CLIENT_NAME)

bonus : $(BSERVER_NAME) $(BCLIENT_NAME)

$(BSERVER_NAME): $(SB_OBJ)
	$(CC) $(CFLAGS) $(SB_OBJ) -o $(BSERVER_NAME)

$(BCLIENT_NAME): $(CB_OBJ)
	$(CC) $(CFLAGS) $(CB_OBJ) -o $(BCLIENT_NAME)

clean:
	@$(RM) $(C_OBJ)
	@$(RM) $(S_OBJ)
	@$(RM) $(CB_OBJ)
	@$(RM) $(SB_OBJ)


fclean: clean
	@$(RM) $(SERVER_NAME)
	@$(RM) $(CLIENT_NAME)
	@$(RM) $(BSERVER_NAME)
	@$(RM) $(BCLIENT_NAME)

re: fclean all


define emo
@echo "\033[0;91m" # ANSI SHADOW :: https://manytools.org/hacker-tools/ascii-banner/
@echo "\t███╗   ███╗██╗███╗   ██╗██╗████████╗ █████╗ ██╗     ██╗  ██╗"
@echo "\t████╗ ████║██║████╗  ██║██║╚══██╔══╝██╔══██╗██║     ██║ ██╔╝"
@echo "\t██╔████╔██║██║██╔██╗ ██║██║   ██║   ███████║██║     █████╔╝ "
@echo "\t██║╚██╔╝██║██║██║╚██╗██║██║   ██║   ██╔══██║██║     ██╔═██╗ "
@echo "\t██║ ╚═╝ ██║██║██║ ╚████║██║   ██║   ██║  ██║███████╗██║  ██╗"
@echo "\t╚═╝     ╚═╝╚═╝╚═╝  ╚═══╝╚═╝   ╚═╝   ╚═╝  ╚═╝╚══════╝╚═╝  ╚═╝"
@echo "\033[0m"
@echo "\033[0;32m"
@echo "\t ______            _______         _                                  _ "
@echo "\t(____  \          (_______)       | |                            _   (_)"
@echo "\t ____)  ) _   _    _     _   ____ | |__    ___   _   _  _____  _| |_  _ "
@echo "\t|  __  ( | | | |  | |   | | / ___)|  _ \  / _ \ | | | |(____ |(_   _)| |"
@echo "\t| |__)  )| |_| |  | |___| |( (___ | | | || |_| || |_| |/ ___ |  | |_ | |"
@echo "\t|______/  \__  |   \_____/  \____)|_| |_| \___/ |____/ \_____|   \__)|_|"
@echo "\t         (____/   "
@echo "\033[0m"
@echo "\033[0;33m" 
@echo "\t  _ ____________    __  __ ___ ___  "
@echo "\t / |__ /__ /__  |  |  \/  | __|   \ "
@echo "\t | ||_ \|_ \ / /   | |\/| | _|| |) |"
@echo "\t |_|___/___//_/    |_|  |_|___|___/ "
@echo "\033[0m"
endef

                                    
                                          