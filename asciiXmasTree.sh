#!/bin/bash

day="4"
star="\e[5;33m*\e[0m\e[1;32m"
o="\e[0m\e[1;31mo\e[0m\e[1;32m"

white="\e[0;37m"
red="\e[1;31m"
green="\e[1;32m"
yellow="\e[1;33m"
blue="\e[1;34m"
magenta="\e[1;35m"
cyan="\e[1;36m"
light_gray="\e[0;37m"
dark_gray="\e[1;30m"
gray="\033[90m"
light_red="\e[1;31m"
light_green="\e[1;32m"
light_yellow="\e[1;33m"
light_blue="\e[1;34m"
light_magenta="\e[1;35m"
light_cyan="\e[1;36m"
brown="\e[0;33m"
reset="\e[0m"

echo -e "
      ${star}                                       ${gray}/ ${green}
      Λ                                      ${gray}(( ${green}
     /.\\                               ${blue}______|_|__ ${green}
    /${o}..\\   ${cyan}Advent of Code 2024🎄     ${blue}/_)_)_)_)_)_\\ ${green}
    /..${o}\\           ${cyan}Day ${day}${blue}            /_)_)_)_)_)_)_\\ ${green}
   /.${o}..${o}\\                    ${red}_     ${blue}/_)_)_)_)_)_)_)_\\ ${green}         
   /...${o}.\\                  ${red}_|_|_    ${white}|  ${blue}__   ___   ${white}| ${green}      
  /..${o}....\\                  ${white}(‥)  Y  ${white}| ${blue}|  | |_|_|  ${white}| ${green}
  ^^^| |^^^                ${white}\\( : )/   ${white}| ${blue}| '| |_|_|  ${white}| ${green}
${brown}_____${green}|_|${brown}___________________${white}(     )${brown}___${white}|_${blue}|__|${white}________${white}|${brown}____${reset}
"

printf "\n"
for i in {0..15}; do
  for j in {0..15}; do
    v=$((i * 16 + j))
    printf "\033[38;5;%dm%02X\033[0m " $v $v
  done
  printf "\n"
done

for i in {0..15}; do
  for j in {0..15}; do
    v=$((i * 16 + j))
    printf "\033[48;5;%dm%02X\033[0m " $v $v
  done
  printf "\n"
done
