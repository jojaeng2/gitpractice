#!/bin/bash

git switch dev

echo "Enter new branch name: "
read newbranch

git checkout --orphan $newbranch
git rm --cached -r .

find . ! -name make-branch.sh -delete

echo "Delete unnecessary function files ..."

git add .
echo "Enter commit message: "
read commitmsg
git commit -m $commitmsg
git push origin $newbranch

git switch dev
git merge $newbranch --allow-unrelated-histories
git push origin dev

git switch $newbranch
