NAME = IIKH
PATH_SRC = srcs/
HEADER_SRC = headers/
OPTION = -std=c++11 -o
SRC = $(PATH_SRC)*.cpp

all: $(NAME)

$(NAME):
	g++ -I $(HEADER_SRC) $(SRC) $(OPTION) $(NAME)
clean:
	rm -f $(NAME)

re: clean all
