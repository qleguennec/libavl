#!/bin/bash

if [ -z "$RENDU_DIR" ]; then
	RENDU_DIR="/tmp/libbst"
fi

if [ -d "$RENDU_DIR" ]; then
	rm -rf $RENDU_DIR
fi

mkdir -p $RENDU_DIR
CPY=(auteur includes src Makefile)

for DIR in ${CPY[@]}; do
	cp -r $DIR $RENDU_DIR
done

[ -n "$MAKE" ] && make -C $RENDU_DIR $MAKE
ls -la $RENDU_DIR
