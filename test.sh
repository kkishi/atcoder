#!/bin/bash

set -e

for f in $(find contests -name main.cc | sort); do
  skip="\
contests/abc006/abc006_3/main.cc\
contests/abc007/abc007_2/main.cc\
contests/abc019/abc019_4/main.cc\
contests/abc021/abc021_a/main.cc\
contests/abc026/abc026_d/main.cc\
contests/abc031/abc031_d/main.cc\
contests/abc043/arc059_b/main.cc\
contests/abc051/abc051_c/main.cc\
contests/abc068/arc079_b/main.cc\
contests/abc069/arc080_b/main.cc\
contests/abc074/arc083_a/main.cc\
contests/abc079/abc079_c/main.cc\
contests/abc081/arc086_b/main.cc\
contests/abc085/abc085_c/main.cc\
contests/abc092/arc093_b/main.cc\
contests/abc096/abc096_d/main.cc\
contests/abc099/abc099_c/main.cc\
contests/abc108/arc102_b/main.cc\
contests/abc109/abc109_d/main.cc\
contests/abc111/abc111_c/main.cc\
contests/abc126/abc126_d/main.cc\
contests/abc131/abc131_e/main.cc\
contests/abc157/abc157_f/main.cc\
contests/abc168/abc168_d/main.cc\
contests/abc182/abc182_b/main.cc\
contests/agc006/agc006_b/main.cc\
contests/agc007/agc007_b/main.cc\
contests/agc013/agc013_b/main.cc\
contests/agc022/agc022_b/main.cc\
contests/agc050/agc050_a/main.cc\
contests/arc022/arc022_3/main.cc\
contests/arc051/arc051_b/main.cc\
contests/arc091/arc091_c/main.cc\
contests/arc103/arc103_c/main.cc\
contests/arc106/arc106_c/main.cc\
contests/arc106/arc106_d/main.cc\
contests/arc108/arc108_c/main.cc\
contests/arc110/arc110_a/main.cc\
contests/arc110/arc110_c/main.cc\
contests/arc111/arc111_c/main.cc\
contests/ddcc2020-qual/ddcc2020_qual_c/main.cc\
contests/intro-heuristics/intro_heuristics_a/main.cc\
contests/jsc2019-qual/jsc2019_qual_d/main.cc\
contests/keyence2020/keyence2020_c/main.cc\
contests/m-solutions2019/m_solutions2019_d/main.cc\
contests/nomura2020/nomura2020_b/main.cc\
contests/past202012-open/past202012_g/main.cc\
contests/practice/practice_1/main.cc\
contests/practice2/practice2_d/main.cc\
contests/practice2/practice2_g/main.cc\
contests/tenka1-2017-beginner/tenka1_2017_c/main.cc\
contests/tenka1-2018-beginner/tenka1_2018_d/main.cc\
"

  skip_match=$(echo $skip | grep $f | wc -l)
  if [[ $skip_match -eq 1 ]]; then
    echo "SKIP $f"
    continue
  fi

  lines=$(cat $f | wc -l)
  if [[ $lines -le 6 ]]; then
    echo "EMPTY $f"
    continue
  fi

  test_dir=$(dirname $f)/test
  num_samples=$(ls $test_dir | wc -l)
  if [[ $num_samples -eq 0 ]]; then
    c=$(echo $f | cut -d / -f 2)
    compete --contest=$c
  fi

  if ! atcoder -t $f >& /dev/null; then
    echo "FAIL $f"
  else
    echo "SUCCESS $f"
  fi
done
