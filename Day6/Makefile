NAME = advent2024
CXX = g++

vpath %.cpp srcs
FILES = main Parser Guard
SRCS = $(addsuffix .cpp, $(FILES))

INCLUDE = includes/
HEADER_FILES = Parser Guard utils
HEADERS = $(addprefix $(INCLUDE), $(addsuffix .hpp, $(HEADER_FILES)))

OBJS_DIR = .objs/
OBJS = $(addprefix $(OBJS_DIR), $(addsuffix .o, $(FILES)))
DEPS = $(OBJS:.o=.d)

CPPFLAGS = -Wall -Wextra -Werror -std=c++17 -I$(INCLUDE)

all: $(NAME)

$(NAME): $(OBJS)
	$(CXX) $(CPPFLAGS) $^ -o $@
	@printf "\n       ${star}\\n"
	@printf "       Λ\\n"
	@printf "      ${green}/.\\\\\n"
	@printf "     ${green}/${o}..\\ ${white}\n"
	@printf "     ${green}/..${o}\\ ${white}    ${bg_magenta} Advent of Code 2024 ${reset}\n"
	@printf "    ${green}/.${o}..${o}\\ ${white}         ${magenta} Day ${day}${reset}          ${red}_🟥_   ❄️\n"
	@printf "    ${green}/...${o}.\\ ${white}                         ${white}(.˛.) ${yellow}y${reset}\n"
	@printf "   ${green}/..${o}....\\ ${white}                       ${white}\\( : )/${reset}\n"
	@printf "   ${green}^^^| |^^^   ${white}                     ${white}(     )${reset}\n"
	@printf "${dark_green}───────────────────────────────────────────────${reset}\n"

$(OBJS_DIR)%.o: %.cpp $(HEADERS) Makefile
	@mkdir -p $(OBJS_DIR)
	$(CXX) $(CPPFLAGS) -c $< -o $@ -MMD -MP

-include $(DEPS)

clean:
	$(RM) -r $(OBJS_DIR)

fclean: clean
	$(RM) $(NAME)

re: fclean
	$(MAKE) all

day="6"
star=$'\e[5;33m*\e[0m\e[1;32m
o=$'\e[0m\e[1;31mo\e[0m\e[1;32m

white=$'\e[0;37m
red=$'\e[1;31m
green=$'\e[1;32m
yellow=$'\e[1;33m
dark_green=$'\033[38;5;58m
magenta=$'\033[38;5;125m
bg_magenta=$'\033[48;5;125m
reset=$'\e[0m

.PHONY: all clean fclean re
