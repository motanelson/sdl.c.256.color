printf "\033c\033[43;30m\n"
clang -S -emit-llvm -o /tmp/$1.ll $1
llc -o $1.asm  /tmp/$1.ll 