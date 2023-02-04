#!/bin/bash

TITLE="Report for $HOSTNAME"
CURRENT_TIME=$(date +"%x %r %Z")
TIME_STAMP="Generated $CURRENT_TIME, by $USER"

report_uptime () {
	echo "<H3>System Uptime</H3>
			<PRE>$(uptime)</PRE>"	
	return
} 

report_disc_space () {
	echo "<H3>Disc Space Utilisation</H3>
			<PRE>$(df -h)</PRE>"
	return
} 

report_home_space () {
	echo "<H3>Home Space Utilisation</H3>
			<PRE>$(du -sh /home/*)</PRE>"
	return
} 

echo "<HTML>
	<HEAD>
			<TITLE>$TITLE</TITLE>
	</HEAD>
	<BODY>
			<H1>$TITLE</H1>
			<P>$TIME_STAMP</P>
			$(report_uptime)
			$(report_disc_space)
			$(report_home_space)
	</BODY>
</HTML>" > report.html
