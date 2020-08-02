base=$(pwd)
for file in $base/in/*; do
  time diff=$($base/a.out < $file | diff --strip-trailing-cr - $base/out/$(basename $file))
  if [ "$diff" = "" ]; then
    echo $(basename $file) OK
  else
    echo $(basename $file) NG
    echo "$diff"
    exit 1
  fi
done
