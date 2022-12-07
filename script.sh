echo "make clean"
read -n 1 -s
make clean
read -n 1 -s
echo "\nmake"
read -n 1 -s
make
read -n 1 -s

echo "\nTP7"
read -n 1 -s
echo "\n./curiosity-test TP7/TestsCorrects/terrain1 TP7/TestsCorrects/prg1"
read -n 1 -s
./curiosity-test TP7/TestsCorrects/terrain1 TP7/TestsCorrects/prg1
read -n 1 -s

echo "\n make curiosity-test4"
make curiosity-test4 
read -n 1 -s

read -n 1 -s
echo "\n./curiosity-test4 TP7/TestsCorrects/terrain1 TP7/TestsCorrects/prg1"
read -n 1 -s
./curiosity-test4 TP7/TestsCorrects/terrain1 TP7/TestsCorrects/prg1
read -n 1 -s

echo "\nTP8"
read -n 1 -s

echo "\n./test_generation_terrains 10 11 11 0.6 sortie.txt"
./test_generation_terrains 10 11 11 0.6 sortie.txt
echo "fichier sortie.txt crée"
read -n 1 -s

echo "\n./test_generation_terrains 10 11 11 0.2 sortie.txt"
./test_generation_terrains 10 11 11 0.2 sortie.txt
echo "fichier sortie.txt modifé"
read -n 1 -s

echo "\n./test_generation_terrains 10 11 11 0.9 sortie.txt"
./test_generation_terrains 10 11 11 0.9 sortie.txt
echo "fichier sortie.txt modifé"

read -n 1 -s
echo "\n./curiosity-perf TP8/prg1_infini 20 11 11 0.8 102 1000 sortie.txt"
./curiosity-perf TP8/prg1_infini 20 11 11 0.8 102 1000 sortie.txt

read -n 1 -s
echo "\n./curiosity-perf TP8/prg1_infini 20 11 11 0.3 102 1000 sortie.txt"
./curiosity-perf TP8/prg1_infini 20 11 11 0.3 102 1000 sortie.txt

read -n 1 -s
echo "\n./curiosity-perf TP8/prg2_infini 20 11 11 0.3 102 1000 sortie.txt"
./curiosity-perf TP8/prg2_infini 20 11 11 0.3 102 1000 sortie.txt

read -n 1 -s
echo "\n./curiosity-perf TP8/prg2_infini 20 11 11 0.8 102 1000 sortie.txt"
./curiosity-perf TP8/prg2_infini 20 11 11 0.8 102 1000 sortie.txt

read -n 1 -s
echo "\n./curiosity-perf TP8/prg2_infini 20 13 13 0.8 102 1000 sortie.txt"
./curiosity-perf TP8/prg2_infini 20 13 13 0.8 102 1000 sortie.txt

read -n 1 -s
echo "\n./curiosity-perf TP8/prg2_infini 20 15 15 0.8 102 1000 sortie.txt"
./curiosity-perf TP8/prg2_infini 20 15 15 0.8 102 1000 sortie.txt

read -n 1 -s
echo "\n./curiosity-perf TP8/prg2_infini 20 17 17 0.8 102 1000 sortie.txt"
./curiosity-perf TP8/prg2_infini 20 17 17 0.8 102 1000 sortie.txt

read -n 1 -s
echo "\n./curiosity-perf TP8/prg2_infini 20 19 19 0.8 102 1000 sortie.txt"
./curiosity-perf TP8/prg2_infini 20 19 19 0.8 102 1000 sortie.txt

read -n 1 -s
echo "\n./curiosity-test TP8/terrain1 TP8/prg1_infini"
read -n 1 -s
./curiosity-test TP8/terrain1 TP8/prg1_infini

read -n 1 -s
echo "\n./curiosity-test TP8/terrain1 TP8/prg2_infini"
read -n 1 -s

read -n 1 -s
echo "\n./curiosity-test TP8/terrain2 TP8/prg1_infini"
read -n 1 -s

read -n 1 -s
echo "\n./curiosity-test TP8/terrain2 TP8/prg2_infini"
read -n 1 -s
./curiosity-test TP8/terrain2 TP8/prg2_infini

echo "\nTP9"
read -n 1 -s
echo "\n./curiosity-obs tp9/terrainNouvelAutomateAccepte tp9/prgNouvelAutomate"
read -n 1 -s
./curiosity-obs tp9/terrainNouvelAutomateAccepte tp9/prgNouvelAutomate
read -n 1 -s

echo "\n./curiosity-obs tp9/terrainNouvelAutomateRejete tp9/prgNouvelAutomate"
read -n 1 -s
./curiosity-obs tp9/terrainNouvelAutomateRejete tp9/prgNouvelAutomate
read -n 1 -s