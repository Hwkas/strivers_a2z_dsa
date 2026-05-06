create_branch:
	git checkout -b $(name) $(shell git rev-list --max-parents=0 HEAD)

remove_untracked:
	git clean -fd -x -e .vscode
