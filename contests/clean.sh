for i in *.cpp; do
    [ -f "$i" ] || break
    truncate -s 0 $i
done
