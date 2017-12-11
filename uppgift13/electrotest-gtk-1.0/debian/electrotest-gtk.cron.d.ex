#
# Regular cron jobs for the electrotest-gtk package
#
0 4	* * *	root	[ -x /usr/bin/electrotest-gtk_maintenance ] && /usr/bin/electrotest-gtk_maintenance
