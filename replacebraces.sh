#!/bin/sh
# cd ..
files=$(find reasonml -name "*.re" && find src -name "*.rei")
echo $files
for file in $files
do
echo $PWD/$file

fastreplacestring $file "[@implicit_arity] " " "
fastreplacestring $file "[@implicit_arity]" " "
fastreplacestring $file "[@ns.braces]" " "
fastreplacestring $file "[@ns.braces] " " "
fastreplacestring $file "[@ns.namedArgLoc]" " "
fastreplacestring $file "[@ns.namedArgLoc] " " "
fastreplacestring $file "[@ns.ternary]" " "
fastreplacestring $file "[@ns.ternary] " " "
fastreplacestring $file "[@ns.namedArgLoc]" " "
fastreplacestring $file "[@ns.namedArgLoc] " " "

done
