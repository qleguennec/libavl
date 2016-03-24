#!/bin/bash

if [ -z "$RENDU_DIR" ]; then
	RENDU_DIR="/tmp/libavl"
fi

if [ -d "$RENDU_DIR" ]; then
	make -C $RENDU_DIR fclean
	rm -rf $RENDU_DIR/build
else
	mkdir -p $RENDU_DIR
	CPY=(auteur includes src Makefile)

	for DIR in ${CPY[@]}; do
		cp -r $DIR $RENDU_DIR
	done
fi

cd $RENDU_DIR
make

ls -la $RENDU_DIR
