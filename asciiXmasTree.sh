#!/bin/bash

day="4"
star="\e[5;33m*\e[0m\e[1;32m"
o="\e[0m\e[1;31mo\e[0m\e[1;32m"

white="\e[0;37m"
red="\e[1;31m"
green="\e[1;32m"
yellow="\e[1;33m"
dark_green="\033[38;5;58m"
magenta="\033[38;5;125m"
bg_magenta="\033[48;5;125m"
reset="\e[0m"

echo -e "
       ${star}
       Λ
      ${green}/.\\
     ${green}/${o}..\\ ${white}    ${bg_magenta} Advent of Code 2024 ${reset}
     ${green}/..${o}\\ ${white}          ${magenta} Day ${day}
    ${green}/.${o}..${o}\\ ${white}                         ${red}_🟥_   ❄️      
    ${green}/...${o}.\\ ${white}                         ${white}(.˛.) ${brown}y    
   ${green}/..${o}....\\ ${white}                       ${white}\\( : )/
   ${green}^^^| |^^^   ${white}                    ${white} (     )
${dark_green}───────────────────────────────────────────────${reset}
"

: <<'COMMENT'
printf "\n\n===== hex =====\n"
for i in {0..15}; do
  for j in {0..15}; do
    v=$((i * 16 + j))
    printf "\033[38;5;%dm%02X\033[0m " $v $v
  done
  printf "\n"
done
printf "\n\n"
for i in {0..15}; do
  for j in {0..15}; do
    v=$((i * 16 + j))
    printf "\033[48;5;%dm%02X\033[0m " $v $v
  done
  printf "\n"
done
printf "\n\n===== decimal =====\n"
for i in {0..15}; do
  for j in {0..15}; do
    v=$((i * 16 + j))
    printf "\033[38;5;%dm%d\033[0m " $v $v
  done
  printf "\n"
done
printf "\n\n"
for i in {0..15}; do
  for j in {0..15}; do
    v=$((i * 16 + j))
    printf "\033[48;5;%dm%d\033[0m " $v $v
  done
  printf "\n"
done
COMMENT
