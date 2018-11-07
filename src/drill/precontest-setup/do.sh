chmod +x run
for i in {A..Z}; do
    mkdir $i
    cp t.cc $i/$i.cc
    cp sample/$i* $i
    cp sample/${i,}* $i
    ls $i/*
done
