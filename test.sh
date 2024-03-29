#!/bin/bash

set -e

all=0

while test $# -gt 0; do
  case "$1" in
    -all)
      shift
      all=1
  esac
done

function problems() {
  if [[ $all = 1 ]]; then
    find contests -name main.cc | sort
  else
    git diff --stat=1024 contests/ | grep main.cc | cut -d ' ' -f 2 | sort
  fi
}

function test_a_problem() {
  problem=$1
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
contests/abc133/abc133_f/main.cc\
contests/abc157/abc157_f/main.cc\
contests/abc168/abc168_d/main.cc\
contests/abc182/abc182_b/main.cc\
contests/abc198/abc198_d/main.cc\
contests/abc215/abc215_e/main.cc\
contests/abc216/abc216_c/main.cc\
contests/abc224/abc224_g/main.cc\
contests/abc233/abc233_f/main.cc\
contests/abc239/abc239_f/main.cc\
contests/abc240/abc240_e/main.cc\
contests/abc244/abc244_c/main.cc\
contests/abc244/abc244_g/main.cc\
contests/abc251/abc251_d/main.cc\
contests/abc251/abc251_f/main.cc\
contests/abc252/abc252_e/main.cc\
contests/abc260/abc260_f/main.cc\
contests/abc272/abc272_g/main.cc\
contests/abc280/abc280_f/main.cc\
contests/abc286/abc286_f/main.cc\
contests/abc289/abc289_f/main.cc\
contests/abc291/abc291_h/main.cc\
contests/abc297/abc297_c/main.cc\
contests/abc299/abc299_d/main.cc\
contests/abc299/abc299_e/main.cc\
contests/abc305/abc305_f/main.cc\
contests/abc315/abc315_e/main.cc\
contests/agc006/agc006_b/main.cc\
contests/agc007/agc007_b/main.cc\
contests/agc013/agc013_b/main.cc\
contests/agc022/agc022_b/main.cc\
contests/agc050/agc050_a/main.cc\
contests/arc022/arc022_3/main.cc\
contests/arc043/arc043_a/main.cc\
contests/arc051/arc051_b/main.cc\
contests/arc091/arc091_c/main.cc\
contests/arc103/arc103_c/main.cc\
contests/arc106/arc106_c/main.cc\
contests/arc106/arc106_d/main.cc\
contests/arc108/arc108_c/main.cc\
contests/arc110/arc110_a/main.cc\
contests/arc110/arc110_c/main.cc\
contests/arc111/arc111_c/main.cc\
contests/arc117/arc117_a/main.cc\
contests/arc117/arc117_d/main.cc\
contests/arc127/arc127_b/main.cc\
contests/arc129/arc129_c/main.cc\
contests/arc130/arc130_c/main.cc\
contests/arc135/arc135_b/main.cc\
contests/arc159/arc159_c/main.cc\
contests/arc161/arc161_d/main.cc\
contests/code-festival-2015-qualb/codefestival_2015_qualB_a/main.cc\
contests/ddcc2020-qual/ddcc2020_qual_c/main.cc\
contests/intro-heuristics/intro_heuristics_a/main.cc\
contests/jsc2019-qual/jsc2019_qual_d/main.cc\
contests/keyence2020/keyence2020_c/main.cc\
contests/m-solutions2019/m_solutions2019_d/main.cc\
contests/nomura2020/nomura2020_b/main.cc\
contests/past202010-open/past202010_d/main.cc\
contests/past202012-open/past202012_g/main.cc\
contests/practice/practice_1/main.cc\
contests/practice2/practice2_d/main.cc\
contests/practice2/practice2_g/main.cc\
contests/tenka1-2017-beginner/tenka1_2017_c/main.cc\
contests/tenka1-2018-beginner/tenka1_2018_d/main.cc\
contests/typical90/typical90_ba/main.cc\
contests/typical90/typical90_bd/main.cc\
contests/typical90/typical90_bs/main.cc\
contests/typical90/typical90_cj/main.cc\
contests/typical90/typical90_z/main.cc\
"

  skip_match=$(echo $skip | grep $problem | wc -l)
  if [[ $skip_match -eq 1 ]]; then
    echo "SKIP $problem"
    return
  fi

  lines=$(cat $problem | wc -l)
  if [[ $lines -le 6 ]]; then
    echo "EMPTY $problem"
    return
  fi

  test_dir=$(dirname $problem)/test
  num_samples=$(ls $test_dir 2> /dev/null | wc -l)
  if [[ $num_samples -eq 0 ]]; then
    c=$(echo $problem | cut -d / -f 2)
    atcoder-compete $c
  fi

  if ! atcoder -t $problem >& /dev/null; then
    echo "FAIL $problem"
  else
    echo "SUCCESS $problem"
  fi
}

export -f test_a_problem
problems | xargs -P 8 -I {} bash -c 'test_a_problem {}'
