git add .
# testcommit: your commite message
git commit -m "testactions"
# vXX.XX.XX: your version. your tag
# git tag -a v0.0.06 -m "test release"
# master: your branch name 
git push origin dev
# release and push to github & docker.io
# goreleaser release  --rm-dist
# only test realase
# goreleaser --snapshot --skip-publish --rm-dist