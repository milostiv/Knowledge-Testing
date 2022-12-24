#!/bin/bash

TITLE="Report for $HOSTNAME"
CURRENT_TIME=$(date +"%x %r %Z")
TIME_STAMP="Generated $CURRENT_TIME, by $USER"

echo "<HTML>
	<HEAD>
			<TITLE>$TITLE</TITLE>
	</HEAD>
	<BODY>
			<H1>$TITLE</H1>
			<P>$TIME_STAMP</P>
	</BODY>
</HTML>" > report.html
