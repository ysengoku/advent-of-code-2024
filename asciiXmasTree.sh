#!/bin/bash

day="4"
star="\e[5;33m*\e[0m\e[1;32m"
o="\e[0m\e[1;31mo\e[0m\e[1;32m"

white="\e[0;37m"
red="\e[1;31m"
green="\e[1;32m"
yellow="\e[1;33m"
reset="\e[0m"

echo -e "
      ${star}
     /.\\       
    /${o}..\\     ${yellow}Advent of Code 2024 🎄 Day ${day}${green}
    /..${o}\\                                   ${red}_${green}
   /.${o}..${o}\\                                ${red}_|_|_${green}
   /...${o}.\\                                 ${white}(\")${green}
  /..${o}....\\                              ${white}-( : )-;
${yellow}__${green}^^^|_|^^^${yellow}______________________________${white}(_____)${yellow}______${reset}
 
"
