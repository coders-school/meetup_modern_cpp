#!/bin/bash

RED="\e[41m"
GREEN="\e[42m"
BOLD="\e[1m"
DEFAULT="\e[0m"
FILE=shapes.cpp

function check()
{
    if [ "$1" != 0 ] ; then
        echo -e $RED "Failed on" "$@" $DEFAULT
        exit 1
    fi
}

function module()
{
    echo -e $BOLD "$1" $DEFAULT
    egrep "$2" "$FILE"
    check $? $1
}

function compile()
{
    echo -e $BOLD "Compiling code with C++14" $DEFAULT
    make compile
    check $? "compilation"
    echo -e $GREEN "Compilation passed" $DEFAULT
}

compile

echo -e $BOLD "Performing mandatory checks" $DEFAULT
module "nullptr" "nullptr"
module "using alias for Collection" "using\s+Collection\s*=\s*(std::)?vector.*"
module "auto" "auto"
module "range based for loop" "auto.*\:"
module "defaulted Rectangle copy constructor" "(Rectangle)\((const)?\s*\1\s*(const)?\s*\&.*\)\s*=\s*default"
module "defaulted Square copy constructor" "(Square)\((const)?\s*\1\s*(const)?\s*\&.*\)\s*=\s*default"
module "deleted getY()" "double getY\(\)\s*=\s*delete"
module "deleted Rectangle()" "Rectangle\(\)\s*=\s*delete"
module "deleted Square()" "Square\(\)\s*=\s*delete"
module "final Square" "(class|struct)\s+Square\s+final\s*:\s*"
module "final getX()" "virtual\s+double\s+getX\(\)\s*const\s+final"
module "override" "\(\)\s*const\s+override"
echo -e $GREEN "All mandatory checks passed" $DEFAULT

