#!/bin/bash

echo "Enter new branch name: "
read newbranch

git checkout --orphan $newbranch
git rm --cached -r .

# rm -ri *

find . ! -name make-branch.sh -exec rm {} \;

echo "Delete unnecessary function files ..."

commitmsg="init"

git add .
git commit -m $commitmsg
git push origin $newbranch

git switch dev
git merge $newbranch --allow-unrelated-histories
git push origin dev

git switch $newbranch
