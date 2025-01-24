#!/bin/bash

cd ../src/lib/
echo Modifying sources to GNU AS format
grep -rlZi section --include \*.src . | xargs -0 sed -i 's/\bsection\b/.section/ig'
grep -rlZi assume --include \*.src . | xargs -0 sed -i 's/\bassume\b/.assume/ig'
grep -rlZi public --include \*.src . | xargs -0 sed -i 's/\bpublic\b/.global/ig'
grep -rlZi private --include \*.src . | xargs -0 sed -i 's/\bprivate\b/.local/ig'
grep -rlZi extern --include \*.src . | xargs -0 sed -i 's/\bextern\b/.extern/ig'
grep -rlZi require --include \*.src . | xargs -0 sed -i 's/\brequire\b/.extern/ig'
grep -rlZ label --include \*.src . | xargs -0 sed -i '/label[[:space:]]\+\S\+[[:space:]]\+at/d'
grep -rlZ assert --include \*.src . | xargs -0 sed -i '/assert/d'
grep -rlZ end --include \*.src . | xargs -0 sed -i 's/end if/.endif/g'
grep -rlZ if --include \*.src . | xargs -0 sed -i 's/\bif\b/.if/g'
grep -rlZ else --include \*.src . | xargs -0 sed -i 's/\belse\b/.else/g'
grep -rlZ end --include \*.src . | xargs -0 sed -i 's/end if/.endif/g'
grep -rlZ PREFER_OS_LIBC --include \*.src . | xargs -0 sed -i 's/.if PREFER_OS_LIBC/.ifdef PREFER_OS_LIBC/g'
grep -rlZ PREFER_OS_CRT --include \*.src . | xargs -0 sed -i 's/.if PREFER_OS_CRT/.ifdef PREFER_OS_CRT/g'
grep -rlZ jq --include \*.src . | xargs -0 sed -i 's/\bjq\b/jp/g'
grep -rlZ rb --include \*.src . | xargs -0 sed -i 's/\brb\b/ds/g'
grep -rlZ dl --include \*.src . | xargs -0 sed -i 's/\bdl\b/d24/g'
grep -rlZ dd --include \*.src . | xargs -0 sed -i 's/\bdd\b/d32/g'
grep -rlZ ident --include \*.src . | xargs -0 sed -i 's/\bident\b/.ident/g'
grep -rlZ weak --include \*.src . | xargs -0 sed -i 's/\bweak\b/.weak/g'
grep -rlZ dup --include \*.src . | xargs -0 sed -i 's/db[[:space:]]\([0-9]\+\)[[:space:]]dup[[:space:]]\([0-9]\+\)/.rept \1 \n db \2 \n.endr/'
grep -rlZ lea --include \*.src . | xargs -0 sed -i '/lea[[:space:]]\([^,]*\),[[:space:]]\([^0-9]*\)$/s/$/+0/'
grep -rlZ pea --include \*.src . | xargs -0 sed -i '/pea[[:space:]]\([^,]*\),[[:space:]]\([^0-9]*\)$/s/$/+0/'

cd ../../scripts/
echo Done
